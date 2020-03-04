#include <iostream>
int xx (int a) {
  cout <<a<<"+"<<a<<endl;
  return a+a;
}
int yy ( int a) {
   cout <<a<<"*"<<a<<endl;
  return a*a;
}
int call (int a, int (*f) (int)) {
    
  cout <<"call " << " f() = " << f(a) <<"\n";
} 

int main () {
 call(3,xx);
 call(4,yy); 
}


