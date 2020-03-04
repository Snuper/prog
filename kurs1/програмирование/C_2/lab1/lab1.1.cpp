#include <iostream>
#include <math.h>
using namespace std;

float stepen (float x, int n){
      float rezultat = 1;
      if (n == 0)return 1;
      if (n > 0)
         for (int i = 0; i <n; i++)
             rezultat *= x;
      if (n < 0)
         for (int i = 0; i>n; n++)
             rezultat *= (1/x);
      return rezultat;
      }

int main(){
    float x;
    int n;
    cout<<"Vvedite chislo: ";
    cin>>x;
    cout<<"Stepen: ";
    cin>>n;
    cout<<stepen(x, n)<<endl;
    
    system ("PAUSE");
    return 0;
}
