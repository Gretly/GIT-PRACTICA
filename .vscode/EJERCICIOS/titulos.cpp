#include <iostream>
#include <string>

using namespace std;


int main()
{
    string titulos[8];
    string autores[8];
    cout << "Por favor ingrese la siguiente información de los Libros: \n";
    for(int i = 0; i <8; i++)
    {
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        cin >> titulos[i];
        cout << "Autor: ";
        cin >> autores[i];
    }

    cout <<"EN LA BIBLIOTECA TENEMOS LOS SIGUIENTES LIBROS: \n";
    for(int i = 0; i < 8; i++){
        cout << "\n******* Libro " << i + 1 << "********:\n";
        cout << "Titulo: ";
        std::cout << titulos[i]<<endl;
        cout << "Autor: ";
        std::cout << autores[i];
        
    }
}