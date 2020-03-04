#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i,n;
     float S,b;
      printf("Vvedite n ");    scanf("%i",&n);
     for (S=0, i=1; i<=n; i+=1) 
            S+=i*pow((-1),i+1);
     printf ("S=%7.3f \n",S);
    system("PAUSE");
    return 0;
}

