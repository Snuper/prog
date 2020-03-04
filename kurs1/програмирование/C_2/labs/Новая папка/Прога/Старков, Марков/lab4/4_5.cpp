#include <stdlib.h>
#include <stdio.h>
#include <math.h>
  int main(int argc, char *argv[]){
      
      int r,i,x;
      float S,G;
      x=1;
      r=0;
      G=0.16;
      
      
      for (i=1; i<=10; i++){
          
      G+=0.02;
      r+=1;
      
          S=S+pow((G*x),r);
          }
          printf (" S=%f " ,S);
           system("PAUSE");
          return 0;
          }
