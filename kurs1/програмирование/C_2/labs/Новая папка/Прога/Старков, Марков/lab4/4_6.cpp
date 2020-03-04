#include <stdlib.h>
#include <stdio.h>
#include <math.h>
  int main(int argc, char *argv[]){
      
      int r,n,i,x,S,N,Sum;
      printf ("\n print N"); scanf ("%d", &N);
      x=(-1);
      r=1;
      S=0;
      Sum=0;
      
     
      for (i=1; i<=N; i++){
          
          r+=1;
          S+=1;
          Sum=Sum+(S*(pow(x,r)));
          
          }
          printf (" Sum=%d" ,Sum);
           system("PAUSE");
          return 0;
          }
