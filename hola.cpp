#include <iostream>

using namespace std;

int main(){

    int i, primero[10];
    for (int i = 0; i < 6; i++)
    
       cin>>primero[i];
    
    for (int i = 2; i >= 0 ; i--)
    
        cout<<primero[2*i]<< " ";
        return 0;   
      
}