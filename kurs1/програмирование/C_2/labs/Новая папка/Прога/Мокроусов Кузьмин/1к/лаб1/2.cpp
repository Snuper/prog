#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main()
{
     float y, t, z, x;  
     printf ("\n input t,z ");
     scanf ("%f%f",&t,&z);
     y= t+2*(1/tan(z));
     x=3*pow(y,2)/(4*tan(z)-2*pow(t,2));           
     printf("\n Output: x=%7.2f     ",x);
     system("PAUSE");
    return 0;
}
