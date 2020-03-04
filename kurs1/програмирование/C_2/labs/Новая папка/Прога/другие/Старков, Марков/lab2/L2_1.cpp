#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,x1,x2,x3,x4,x5,max,sum,pr;
    printf("Input numbers ");   scanf("%f%f%f%f%f%f",&x,&x1,&x2,&x3,&x4,&x5);
    sum= x+x1+x2+x3+x4+x5;
    pr= x*x1*x2*x3*x4*x5;
    
 if(pr>sum)
 max= pr-sum;
 else
 max=sum-pr;
 
    printf ("max=%8.2f\n",max); 

  
   system("PAUSE");
   return EXIT_SUCCESS;
}
