#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{    system("CLS"); 
     int S,i;
     float n;
    S=0;
    n=0;
     for ( i=1; i<=25; i++)
      {
     S++;
     n=n+sin(S);
     }
    printf ("n=%7.4f",n );
    system("PAUSE");
    return 0;
}
