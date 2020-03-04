#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,x1,x2,x3,x4,max;
    printf("Input numbers ");   
    scanf("%f%f%f%f%f",&x,&x1,&x2,&x3,&x4);
    
max=0;
    
 if (x>0)   max = max +x;
 if (x1>0)   max = max +x1; 
 if (x2>0)   max += x2; 
 if (x3>0)   max += x3;
 if (x4>0)   max += x4;
  printf("max=%8.2f \n",max); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
