#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main(int argc, char *argv[])
{
     float t,y,z,x, S;  
     printf ("\n input y,z ");
     scanf ("%f%f",&y,&z);
    
     t=(5 / (1+(y*y))); 
     x=2*y+3 *sinh( t)- z ;          
     printf("\n Output: x=%7.2f     z=%7.2f      y=%7.2f ",x, z, y);
     system("PAUSE");
    return 0;
}
