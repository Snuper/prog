#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int S,n,i;
    S=0;
    n=0;
     for ( i=1; i<=117; i++)
      {
     S++;
     n=n+S;
     }
    printf ("n=%d",n );
    system("PAUSE");
    return 0;
}
