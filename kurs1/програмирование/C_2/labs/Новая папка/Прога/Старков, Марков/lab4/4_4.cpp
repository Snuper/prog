#include <stdlib.h>
#include <stdio.h>
#include <math.h>
  int main(int argc, char *argv[]){
      
      int n,i;
      float S,p;
      
      p=-0.1;
      for (i=1; i<=10; i++){
          
          p+=0.2;
          S=S+log(p);
          }
          printf (" S=%f" ,S);
           system("PAUSE");
          return 0;
          }
