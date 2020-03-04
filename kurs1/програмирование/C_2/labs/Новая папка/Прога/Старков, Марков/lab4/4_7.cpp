#include <stdlib.h>
#include <stdio.h>
#include <math.h>
  int main(int argc, char *argv[]){
      
      int r,i,M,P;
      printf ("\n print M"); scanf ("%d", &M);
  
      r=0;
      P=1;
      
     
      for (i=1; i<=M; i++){
          
          r+=1;
          P=(P*r);
          
          
          }
          printf (" Sum=%d" ,P);
           system("PAUSE");
          return 0;
          }
