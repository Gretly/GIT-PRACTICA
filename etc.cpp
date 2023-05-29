#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
  int i;
  string notas[]={2.3,8.5,3.2,9.5,4,5.5,7.0}; //array de 7 elementos
  cout << fixed << setprecision(2);
  for(i=0; i<7; i++)
      cout << notas[i] << " "; //se muestra cada elemento del array
  cout << endl;
  system("pause");
}
