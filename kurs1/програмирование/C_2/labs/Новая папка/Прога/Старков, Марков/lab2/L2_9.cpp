#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,x1,x2,y,y1,y2;
    printf("Input numbers ");   
    scanf("%f%f%f",&x,&x1,&x2);
  if((x>x2)&&(x2>x1)) {y=x1;y1=x;y2=x2;}
  if((x1>x2)&&(x2>x)) {y=x1;y1=x;y2=x2;}
  if((x2>x)&&(x>x1)){y=x;y1=x2;y2=x1;}
  if((x1>x)&&(x>x2)){y=x;y1=x2;y2=x1;}
  if((x>x1)&&(x1>x2)){y=x2;y1=x1;y2=x;}
  if((x2>x1)&&(x1>x)){y=x2;y1=x1;y2=x;}


  printf("y=%8.2f y1=%8.2f y2=%8.2f \n",y,y1,y2); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
 
