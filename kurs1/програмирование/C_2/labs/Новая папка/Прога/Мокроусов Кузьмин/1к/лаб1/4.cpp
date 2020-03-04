#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main()
{
     float y, t, z, x;  
     printf ("\n input t,z ");
     scanf ("%f%f",&t,&z);
     y= cos(t+z);
     x=4*log(pow(y,3))-z/t;           
     printf("\n Output: x=%7.2f     ",x);
     system("PAUSE");
    return 0;
}
