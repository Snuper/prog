#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main()
{
     float y, t, z, x;  
     printf ("\n input y,z ");
     scanf ("%f%f",&y,&z);
     t=5/(1+pow(y,2));
     x=2*y+3*sinh(t) - z;           
     printf("\n Output: x=%7.2f     ",x);
     system("PAUSE");
    return 0;
}
