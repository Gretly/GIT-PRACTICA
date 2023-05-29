#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int matriz[3][3];
    int mayores[3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j]=rand()%10;
            cout<<matriz[i][j] << " ";
            if (j==0)
                mayores[j]=matriz[i][j];
            else
            {
                if (matriz[i][j]>mayores[j])
                    mayores[j]=matriz[i][j];
            }            
        }
        
        cout<<endl;
    }
    cout <<endl;
    for (int j = 0; j < 3; j++)
    {
        cout<<mayores[j] << " ";
    }
    return 0;
}