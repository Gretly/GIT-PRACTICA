#include <iostream>
using namespace std;

const int N = 8; // Tamaño del triángulo
int main() {
    int PAS[N][N];
    // Elementos columna 0
    for (int i=0; i<N; i++)
    PAS[i][0] = 1;
    // Elementos fila 0
    for (int j=0; j<N; j++)
    PAS[0][j] = 1;
    // Resto elementos triángulo de Pascal
    for (int i=1; i<N; i++)
    for (int j=1; j<N-i; j++)
    PAS[i][j] = PAS[i-1][j] + PAS[i][j-1];
    // Salida por consola triángulo
    for (int i=0; i<N; i++) {
    for (int j=0; j<=i; j++)
    std::cout << PAS[i-j][j] << " ";
    std::cout << std::endl;
    }
return 0;
}
