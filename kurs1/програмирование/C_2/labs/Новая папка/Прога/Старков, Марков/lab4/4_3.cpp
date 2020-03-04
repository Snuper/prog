#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{    system("CLS"); 
     int S,i,k;
     float z;
    S=19;
    z=0;
    
    
     for (k=0, i=1; i<=19; i++)
      {
     k++;
     z=z+tan(2*k);
     }
    printf ("z=%7.2f",z );
    system("PAUSE");
    return 0;
}
