#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i,n;
     float S;
      printf("Vvedite n ");    scanf("%i",&n);
     for (S=0, i=1; i<=n; i++) 
            S+=tan(i*2);  
     printf ("S=%7.2f \n",S);
    system("PAUSE");
    return 0;
}

