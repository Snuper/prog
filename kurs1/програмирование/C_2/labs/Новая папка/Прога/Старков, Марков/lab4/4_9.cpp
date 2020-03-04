#include <stdlib.h>
#include <stdio.h>
#include <math.h>
  int main(int argc, char *argv[]){
      
      float x,P,r,fact,S;
      int N,i;
      printf ("\n print x and N"); scanf ("%f%d", &x, &N);
  
      r=0;
      fact=1;
      
     
      for (i=1; i<=N; i++){
          
          r+=1;
          fact=fact*r;
          S=S+(pow(x,r)/fact);
          }
          S+=1;
          
          printf (" S=%3.2f" ,S);
           system("PAUSE");
          return 0;
          }
