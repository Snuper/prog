#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{    system("CLS"); 
     int i,n,x,f,j;
     float S;
      printf("Vvedite n ");    scanf("%i%i",&x,&n);
     for (S=0, i=1; i<=n; i+=1) 
            {for (f=1,j=1;j<=i-1;j++,f*=j){} 
            S+=pow(x,i)/f;}
     S+=1;
     printf ("S=%7.2f \n",S);
    system("PAUSE");
    return 0;
}

