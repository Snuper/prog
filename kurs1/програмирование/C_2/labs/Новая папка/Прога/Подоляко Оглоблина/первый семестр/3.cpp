#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main(int argc, char *argv[])
{
     float x, y, t, z;  
     printf ("\n input t, z ");
     scanf ("%f%f",&t,&z);
     y=cos(t+z);
     x=4*log(y*y*y)-z/t;
     printf("\n Output: x=%7.2f ", x);
     system("PAUSE");
    return 0;
}
