#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i,p;
     for (p=1, i=2; i<=12; i+=2) 
            p*=i;
     printf ("P=%d \n",p);
    system("PAUSE");
    return 0;
}

