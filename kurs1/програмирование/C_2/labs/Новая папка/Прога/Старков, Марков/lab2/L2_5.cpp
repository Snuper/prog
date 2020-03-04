#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,x1,x2,x3,min,num;
    printf("Input numbers ");   
    scanf("%f%f%f%f",&x,&x1,&x2,&x3);
    
min=20000;
    
 if (x<min)   {num=1; min=x;}
 if (x1<min)   {num=2; min=x1;}
 if (x2<min)   {num=3; min=x2;}
 if (x3<min)   {num=4; min=x3;}

  printf("num=%8.2f  \n",num); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
