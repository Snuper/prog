#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main(int argc, char *argv[])
{
     float x, y, t, z;  
     printf ("\n input t, z ");
     scanf ("%f%f",&t,&z);
     y=t+2*(1/tan(z));
     x=3*y*y/(4*(tan(z))-2*t*t);
     printf("\n Output: x=%7.2f ", x);
     system("PAUSE");
    return 0;
}
