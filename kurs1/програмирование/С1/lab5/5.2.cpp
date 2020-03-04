#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float xn,a,x,b,c,h,y,max,min;
   a=2.14;
   b=-4.21;
   c=3.25;
   xn=-4.5; //начальное значение
   x=-13.5; //Конечное значение
   h=-0.5; //шаг иследований
   y=(a*xn*xn+b*xn+c)*sin(xn);
   max=y;
   min=y;
   while (xn>=x)
{   
   y=(a*xn*xn+b*xn+c)*sin(xn);
   xn+=h;
   if (y>max)
   max=y;
   if(y<min)
   min=y;
}
   printf("max=%.3f \n min=%.3f",max,min);
    system("PAUSE");
    return 0;
}
