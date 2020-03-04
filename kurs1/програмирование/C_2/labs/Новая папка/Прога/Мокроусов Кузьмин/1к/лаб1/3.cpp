#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main()
{
     float y, t, z, x;  
     printf ("\n input t,z ");
     scanf ("%f%f",&t,&z);
     y= sin(t);
     x=4*pow(y,2)/(4*y*exp(z)-2*pow(t,3));           
     printf("\n Output: x=%7.2f     ",x);
     system("PAUSE");
    return 0;
}
