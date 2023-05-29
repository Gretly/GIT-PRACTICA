#include <iostream>
using namespace std;

int main(){
    int numero;
    bool n_primo = true;

    cout<<"INGRESA UN NUMERO ENTERO POSITIVO: ";
    cin>>numero;
    for (int i = 2; i < numero/2; i++)
    {
        if (numero % i == 0)
        {
            n_primo = false;

            break;
        }
        
    }

    if (n_primo)
    {
        cout << numero << " ES PRIMO" << endl;
    }
    else{
        cout << numero << " NO ES PRIMO" << endl;
    }
       
}