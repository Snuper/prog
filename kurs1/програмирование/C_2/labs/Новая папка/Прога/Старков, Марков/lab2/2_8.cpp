#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,x1,x2,x3,max,max2;
    printf("Input numbers ");   
    scanf("%f%f%f%f",&x,&x1,&x2,&x3);
  max=-200000;
  max2=-200000 ;  
     
     if(x>max) max=x;
     if(x1>max) max=x1;
     if(x2>max) max=x2;
     if(x3>max) max=x3;
     
     if((x>max2)&&(x<max)) max2=x;
     if((x1>max2)&&(x1<max)) max2=x1;
     if((x2>max2)&&(x2<max)) max2=x2;
     if((x3>max2)&&(x3<max)) max2=x3;
  printf("max=%8.2f max2=%8.2f  \n",max,max2); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
