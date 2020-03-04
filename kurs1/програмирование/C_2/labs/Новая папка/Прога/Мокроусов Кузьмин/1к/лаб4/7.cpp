#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i,n,p;
      printf("Vvedite m ");    scanf("%i",&n);
     for (p=1, i=1; i<=n; i+=1) 
            p*=i;
     printf ("P=%d \n",p);
    system("PAUSE");
    return 0;
}

