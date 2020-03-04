#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{    system("CLS"); 
     int S,i;
     float z;
    S=0;
    z=0;
    
     for ( i=1; i<=25; i++)
      {
     S++;
     z=z+sin(S);
     }
    printf ("z=%7.4f",z );
    system("PAUSE");
    return 0;
}
