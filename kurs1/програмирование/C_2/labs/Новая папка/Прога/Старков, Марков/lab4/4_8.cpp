#include <stdlib.h>
#include <stdio.h>
#include <math.h>
  int main(int argc, char *argv[]){
      
      int r,i,M,P;
      
  
      r=0;
      P=1;
      M=12;
     
      for (i=1; i<=M; i++){
          
          r+=1;
          if (r%2==0) P=(P*r);
          
          
          }
          printf (" Sum=%d" ,P);
           system("PAUSE");
          return 0;
          }
