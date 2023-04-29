#include <iostream>

using namespace std;

int main(){

    string estudiante = "DARIO";
    int semestre {3};

    double nota; 

    cout<<"INTRODUCE LA NOTA DEL ESTUDIANTE: ";
    cin>>nota; 

    cout<<"INTRODUCE EL SEMESTRE DEL ESTUDIANTE: "; 
    cin>>semestre; 

    estudiante="richard";

    cout<<"DATOS DEL ESTUDIANTE"<<endl;

    cout<<"NOMBRE: " << estudiante << ". SEMESTRE: " << semestre << ". NOTA:  " << nota;


}