#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float r,max,min,y1,y2,y3,y4;
    printf("Input ");   scanf("%f%f%f%f",&y1,&y2,&y3,&y4);
    max=y1;
    min=y1;
   y2= y2>max? max=y2: y2<min? min=y2: y2=y2;
   y3= y3>max? max=y3: y3<min? min=y3: y3=y3;   
   y4= y4>max? max=y4: y4<min? min=y4: y4=y4;
   r=max-min;
   printf ("r=%8.2f \n", r); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

