#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,y1,y2,y3,y4;
    printf("Input ");   scanf("%f%f%f%f",&y1,&y2,&y3,&y4);
   y1= y1>0? y1=y1: y1=0;
   y2= y2>0? y2=y2: y2=0;
   y3= y3>0? y3=y3: y3=0;
   y4= y4>0? y4=y4: y4=0;
   printf ("x1=%8.2f x2=%8.2f x3=%8.2f x4=%8.2ff\n", y1,y2,y3,y4); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

