#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main()
{
     float y, t, z, x;  
     printf ("\n input z,t ");
     scanf ("%f%f",&z,&t);
     y= tan(t)+z;
     x=(8*pow(z,2)+1)/(y*exp(t)+pow(t,2));           
     printf("\n Output: x=%7.2f     ",x);
     system("PAUSE");
    return 0;
}
