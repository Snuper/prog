#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x1,x2,y1,y2,y3,y4,y5,y6,y7,y8;
    printf("Input ");   scanf("%f%f%f%f%f%f%f%f",&y1,&y2,&y3,&y4,&y5,&y6,&y7,&y8);
    x1=0;
    x2=0;
   y1= y1<0? x2+=1: x1+=1;
   y2= y2<0? x2+=1: x1+=1;
   y3= y3<0? x2+=1: x1+=1;
   y4= y4<0? x2+=1: x1+=1;
   y5= y5<0? x2+=1: x1+=1;
   y6= y6<0? x2+=1: x1+=1;
   y7= y7<0? x2+=1: x1+=1;
   y8= y8<0? x2+=1: x1+=1;
   printf ("x1=%8.2f x2=%8.2f \n", x1,x2); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

