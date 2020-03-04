#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i,n;
     float S,b;
      printf("Vvedite n ");    scanf("%i",&n);
     for (S=0,b=0.18, i=1; i<=10; b+=0.02, i+=1) 
            S+=pow(b*n,i);
     printf ("S=%7.3f \n",S);
    system("PAUSE");
    return 0;
}

