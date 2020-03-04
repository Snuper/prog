#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i;
     float S;
     for (S=0, i=1; i<=25; i++) 
          S=S+sin(i);
     printf ("S=%1.3f\n",S);
    system("PAUSE");
    return 0;
}
