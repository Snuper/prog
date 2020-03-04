#include <iostream>

using namespace std;

void to_bin(int n){
      if (n)
      {
         to_bin (n / 2);
         cout<< n % 2;     
      }
}

int main(){
    int x;
    cout<<"Enter the number: "<<endl;
    cin>>x;
    to_bin (x);
    cout<<endl;
    
    system ("PAUSE");
    return 0;
}
