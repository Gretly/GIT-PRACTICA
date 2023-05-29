#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int matriz[3][3];
    int suma[3];
    int filaMenor=0;
    int sumaMenor=0;
    for (int i = 0; i < 3; i++)
        suma[i]=0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j]=rand()%10;
            cout<<matriz[i][j] << " ";
            suma[i] += matriz[i][j];

            if (i==0){
                sumaMenor=suma[i];
                filaMenor=i;
            }
            else
            {
                if (suma[i]<suma[sumaMenor]){
                    sumaMenor=suma[i];
                    filaMenor=i;
                }
            }            
        }
        cout <<"SUMA DE LA COLUMNA: " << suma[i] <<endl;
    }
    cout <<endl;
    cout<<"LA FILA CON LA SUMA MENOR ES: " <<filaMenor+1<< " Y SU SUMA ES: " <<sumaMenor<<endl;
        
    return 0;
}   