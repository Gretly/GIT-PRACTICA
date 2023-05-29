#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector <int> elemento{5,4,3,2,1};
    vector <char> vocales{'a','e','i','o','u'};

    for (int i = 0; i < 5; i++)
    {
        cout << vocales[i] << endl; 
    }
    
    

        



}







/*cout<<"INGRESE CANTIDAD DE LETRAS: ";
    int letras=0;
    cin>>letras;

    vector <string> elemento(letras);
    
    for(int i=0; i < letras; i++){

        cout<<"INGRESE LA PALABRA NRO " <<i+1<<endl;
        cin>>elemento[i];
    }

    cout<<"PALABRAS ALMACENADAS: "<<endl;

    for(int i=0; i < elemento.size(); i++){

        cout<<i+1<<": "<<elemento[i]<<endl;
    }
*/