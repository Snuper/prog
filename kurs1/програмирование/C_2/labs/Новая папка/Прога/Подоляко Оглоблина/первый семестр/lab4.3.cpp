#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{    system("CLS"); 
     int n,i;
     float S;
     printf("Vvedite n ");    scanf("%d",&n);
     for  (S=0, i=2; i<=n*2; i=i+2) 
        S=S+tan(i);
     printf ("S=%1.2f\n",S);
    system("PAUSE");
    return 0;
}
