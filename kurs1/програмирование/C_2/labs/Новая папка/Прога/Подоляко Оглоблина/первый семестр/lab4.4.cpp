#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{    system("CLS"); 
     float S,i;
     for (S=0, i=0.1; i<=2.0; i=i+0.2) 
        S=S+log(i);
     printf ("S=%2.4f\n",S);
    system("PAUSE");
    return 0;
}

