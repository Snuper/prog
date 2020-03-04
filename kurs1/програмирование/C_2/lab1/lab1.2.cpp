#include <iostream>
#include <math.h>

using namespace std;

float cosinus (float x){
      float q = 1, kx = x * x, sum = 0;
      int n = 0;
      while (fabs(q) >= 0.0001){
            sum += (n % 2 == 0 ? q: -q);
            n += 1;
            q *= kx / ((2 * n - 1) * 2 * n);
			}
      return sum;
}

int main(){
    float x;
    cout<<"Vvedite chislo: ";
    cin>>x;
    cout<<"Znachenie Taylor: "<<cosinus(x)<<endl;
    cout<<"Standartnoe znachenie cosinusa: "<<cos(x)<<endl;
    
    system ("PAUSE");
    return 0;
}
