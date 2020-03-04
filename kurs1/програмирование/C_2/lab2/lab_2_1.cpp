#include <iostream>

using namespace std;

float func (int n){
      cin>>n;
      if (n != 0)
         {
           if (n > 0)
              cout<<"+"<<n<<endl;
           func (n); 
         }
      }

int main(){
    int x;
    cout<<"Enter the number: "<<endl;
    func (x);
    
    system ("PAUSE");
    return 0;
}
