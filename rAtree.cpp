#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_ITEMS = 4; // Factor de carga máximo permitido
const int MIN_ITEMS = 2; // Factor de carga mínimo permitido

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

struct Rect {
    Point ll; // Lower-left corner
    Point ur; // Upper-right corner

    Rect(Point ll = Point(), Point ur = Point()) : ll(ll), ur(ur) {}

    bool contains(Point p) const {
        return p.x >= ll.x && p.x <= ur.x && p.y >= ll.y && p.y <= ur.y;
    }

    bool intersects(Rect r) const {
        return ll.x <= r.ur.x && ur.x >= r.ll.x && ll.y <= r.ur.y && ur.y >= r.ll.y;
    }

    int area() const {
        return (ur.x - ll.x) * (ur.y - ll.y);
    }
};

struct Node {
    int level; // Nivel del nodo en la R* Tree
    Rect rect; // Rectángulo que cubre todos los objetos espaciales del nodo
    vector<Point> points; // Objetos espaciales almacenados en el nodo
    vector<Node*> children; // Punteros a los nodos descendientes

    Node(int level = 0, Rect rect = Rect()) : level(level), rect(rect) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }

    bool isLeaf() const {
        return children.empty();
    }

    bool isOverflow() const {
        return points.size() > MAX_ITEMS;
    }

    bool isUnderflow() const {
        return points.size() < MIN_ITEMS;
    }

    void split() {
        // Seleccione dos objetos espaciales que maximicen la separación entre ellos
        int n = points.size();
        Point p1, p2;
        int max_dist = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2);
                if (dist > max_dist) {
                    max_dist = dist;
                    p1 = points[i];
                    p2 = points[j];
                }
            }
        }

        // Dividir los objetos espaciales en dos grupos basados en su distancia al punto medio entre los dos objetos seleccionados
        int mid_x = (p1.x + p2.x) / 2;
        int mid_y = (p1.y + p2.y) / 2;
        vector<Point> group1, group2;
        for (int i = 0; i < n; i++) {
            if (pow(points[i].x - mid_x, 2) + pow(points[i].y - mid_y, 2) <= max_dist / 4) {
                group1.push_back(points[i]);
            } else {
                group2.push_back(points[i]);
            }
        }

        // Crear dos nuevos nodos hoja y distribuir los objetos espaciales entre ellos
        Node* child1 = new Node(level, Rect(Point(INT_MAX, INT_MAX), Point(INT_MIN, INT_MIN)));
        Node*