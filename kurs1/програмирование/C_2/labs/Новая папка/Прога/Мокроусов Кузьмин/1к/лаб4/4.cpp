#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i;
     float S;
     for (S=0, i=1; i<=19; i+=2) 
            S+=log(i*0.1);  
     printf ("S=%7.3f \n",S);
    system("PAUSE");
    return 0;
}

