#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float min,x,y1,y2,y3,y4;
    printf("Input ");   scanf("%f%f%f%f",&y1,&y2,&y3,&y4);
   min=y1;
   x=1;
    if (y2<min)
   {x=2;
   min=y2;
   }
   if (y3<min)
   {x=3;
   min=y3;
   }
   if (y4<min)
   {x=4;
   min=y4;
   }
   printf ("x=%8.2f \n", x); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

