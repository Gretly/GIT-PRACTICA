#include<iostream>
using namespace std;

int main(){

    /*int mi_array[3][4] = {40,10,20,30,50,60,70,80,90,100,110,120};
    cout<<mi_array[0][2];*/

   int mi_array[3][4];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           cin >> mi_array[i][j];
        }
        
    }
    
    cout << "LOS VALORES ALMACENADOS SON: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           cout << mi_array[i][j];
        }
        cout <<endl; 
        
    }
    
}