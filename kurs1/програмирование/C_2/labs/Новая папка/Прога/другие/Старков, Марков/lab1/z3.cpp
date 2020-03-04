 #include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main(int argc, char *argv[])
{
     float y,z,t,x, S;  
     printf ("\n input t,z ");
     scanf ("%f%f",&t,&z);
     
     y=sin (t);
     
    x=4*(y*y) /( 4*y*exp(z) - 2*(t*t*t)) ;   
     
     printf("\n Output: x=%7.2f     ",x);
     system("PAUSE");
    return 0;
}
