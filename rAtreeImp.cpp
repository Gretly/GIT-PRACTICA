
#include <vector>
#include <algorithm>

using namespace std;




const int MAX_LOAD = 4;
const int MIN_LOAD = 2;

struct Rect {
    int x_min, y_min, x_max, y_max;
    Rect() {}
    Rect(int x1, int y1, int x2, int y2)
        : x_min(x1), y_min(y1), x_max(x2), y_max(y2) {}
};

struct Node {
    vector<Rect> rects;
    vector<Node*> children;
    bool is_leaf;
    Node() : is_leaf(true) {}
    Node(const vector<Rect>& rs, const vector<Node*>& cs, bool leaf)
        : rects(rs), children(cs), is_leaf(leaf) {}
};

Rect get_bounding_box(const vector<Rect>& rects) {
    Rect bbox = rects[0];
    for (int i = 1; i < rects.size(); ++i) {
        bbox.x_min = min(bbox.x_min, rects[i].x_min);
        bbox.y_min = min(bbox.y_min, rects[i].y_min);
        bbox.x_max = max(bbox.x_max, rects[i].x_max);
        bbox.y_max = max(bbox.y_max, rects[i].y_max);
    }
    return bbox;
}

bool rects_overlap(const Rect& a, const Rect& b) {
    return a.x_min <= b.x_max && a.x_max >= b.x_min && a.y_min <= b.y_max && a.y_max >= b.y_min;
}

int pick_seed(const vector<Rect>& rects) {
    int n = rects.size();
    int seed1 = 0, seed2 = 0;
    int max_dist = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = (rects[i].x_min - rects[j].x_min) * (rects[i].x_min - rects[j].x_min) +
                       (rects[i].y_min - rects[j].y_min) * (rects[i].y_min - rects[j].y_min) +
                       (rects[i].x_max - rects[j].x_max) * (rects[i].x_max - rects[j].x_max) +
                       (rects[i].y_max - rects[j].y_max) * (rects[i].y_max - rects[j].y_max);
            if (dist > max_dist) {
                max_dist = dist;
                seed1 = i;
                seed2 = j;
            }
        }
    }
    return seed1 == seed2 ? 0 : seed1;
}

Rect get_mbr(const vector<Rect>& rects) {
    Rect mbr = rects[0];
    for (int i = 1; i < rects.size(); ++i) {
        mbr.x_min = min(mbr.x_min, rects[i].x_min);
        mbr.y_min = min(mbr.y_min, rects[i].y_min);
        mbr.x_max = max(mbr.x_max, rects[i].x_max);
        mbr.y_max = max(mbr.y_max, rects[i].y_max);
    }
    return mbr;
}

void pick_next(const vector<Rect>& rects, vector<int>& group1, vector<int>& group2) {
    int n = rects.size();
    if (group1.size() == 1) {
        group2.push_back(group1.back());
        group1.pop_back();
        return;
    }


}
