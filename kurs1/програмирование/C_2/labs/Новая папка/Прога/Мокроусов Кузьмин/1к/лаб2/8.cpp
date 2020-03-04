#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x1,x2,y1,y2,y3,y4;
    printf("Input ");   scanf("%f%f%f%f",&y1,&y2,&y3,&y4);
   x1=y1;
   y2= y2>x1?x1=y2:y2=y2;
   y3= y3>x1?x1=y3:y3=y3;
   y4= y4>x1?x1=y4:y4=y4;
   if (x1==y1) x2=y2;
   else x2= y1;
   y2= y2>x2&&y2<x1? x2=y2:y2=y2;
   y3= y3>x2&&y3<x1? x2=y3:y3=y3;
   y4= y4>x2&&y4<x1? x2=y4:y4=y4;
   printf ("x1=%8.2f x2=%8.2f \n", x1,x2); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

