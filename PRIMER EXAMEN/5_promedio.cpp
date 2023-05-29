#include <iostream>
using namespace std;

int main(){
    float notas[4];
    float suma=0;
    for (int i = 0; i < 4; i++)
    {
        cout<<"INTRODUZCA NOTA " <<i+1<<endl;
        cin>>notas[i];
        suma += notas[i];
    }
    cout<<"EL PROMEDIO DE LAS NOTAS ES: " <<suma/4;
    return 0;
}