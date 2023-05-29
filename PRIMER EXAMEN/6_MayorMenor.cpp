#include <iostream>
using namespace std;

int main(){
    float numeros[4], mayor, menor;
    for (int i = 0; i < 4; i++)
    {
        cout<<"INGRESE EL " <<i+1 <<" NUMERO"<<endl;
        cin>>numeros[i];
        if (i==0){
            mayor=numeros[i];
            menor=numeros[i];            
        }

        if (numeros[i]>mayor)
            mayor=numeros[i];
        if (numeros[i]<menor)
            menor=numeros[i];                
    }
    
    cout<<"EL NRO MAYOR ES: " <<mayor<< " Y SU DOBLE ES: " <<mayor*2<<endl;
    cout<<"EL NRO MENOR ES: " <<menor<< " Y SU INCRMENTO EN DOS ES: " <<menor+2<<endl;
    return 0;
}