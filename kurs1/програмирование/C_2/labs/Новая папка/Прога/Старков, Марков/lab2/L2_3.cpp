#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,x1,x2,x3,max;
    printf("Input numbers ");   
    scanf("%f%f%f%f",&x,&x1,&x2,&x3);
    
max=0;
    
 if (x<0)   x=0;
 if (x1<0)   x1=0; 
 if (x2<0)   x2=0; 
 if (x3<0)   x3=0;

  printf("x=%8.2f x1=%8.2f  x2=%8.2f  x3=%8.2f \n",x,x1,x2,x3); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
