#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x1,x2,y1,y2,y3,y4,y5,y6,max;
    printf("Input ");   scanf("%f%f%f%f%f%f",&y1,&y2,&y3,&y4,&y5,&y6);
    x1=y1+y2+y3+y4+y5+y6;
    x2=y1*y2*y3*y4*y5*y6;
   max= x1>x2||x2==x1? x1-x2 : x2-x1;
   printf ("max=%8.2f\n", max); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

