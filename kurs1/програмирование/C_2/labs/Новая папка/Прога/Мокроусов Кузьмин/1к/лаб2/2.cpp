#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,y1,y2,y3,y4,y5;
    printf("Input ");   scanf("%f%f%f%f%f",&y1,&y2,&y3,&y4,&y5);
    x=0;
   x= y1>0? x+=y1: x=x;
   x= y2>0? x+=y2: x=x;
   x= y3>0? x+=y3: x=x;
   x= y4>0? x+=y4: x=x;
   x= y5>0? x+=y5: x=x;
   printf ("x=%8.2f\n", x); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

