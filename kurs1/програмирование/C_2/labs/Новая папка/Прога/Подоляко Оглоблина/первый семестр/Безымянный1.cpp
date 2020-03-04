#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main(int argc, char *argv[])
{
     float x, y, t, z;  
     printf ("\n input y, z ");
     scanf ("%f%f",&y,&z);
     t= 5/(1+y*y);
     x=2*y+3*sinh(t)-z;
     printf("\n Output: x=%7.2f ", x);
     system("PAUSE");
    return 0;
}
