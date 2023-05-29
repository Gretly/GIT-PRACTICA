#include <vector>
#include <iostream>

using namespace std;

int main()
{
int i, vector[10];
for(i = 0; i < 10; i++ )
vector[i] = 2 * i +1 ; 
for (i = 0; i < 10; i += 2)
cout << vector[i] << " ";
cout << endl;

}
