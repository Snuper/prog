#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main()
{
     float y, t, z, x;  
     printf ("\n input y,z ");
     scanf ("%f%f",&y,&z);
     t= sin(2+z);
     x=6*pow(t,2)-(1/tan(z)+1)/pow(y,2);           
     printf("\n Output: x=%7.4f     ",x);
     system("PAUSE");
    return 0;
}
