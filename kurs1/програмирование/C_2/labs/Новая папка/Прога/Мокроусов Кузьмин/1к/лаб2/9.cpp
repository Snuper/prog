#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float s,x,y1,y2,y3;
    printf("Input ");   scanf("%f%f%f",&y1,&y2,&y3);
   s=1;
   if (y1>y2&&y1>y3) 
   {if (y2<y3)
   {x=y2;
   y2=y1;
   y1=x;
   s=0;}
   else
   {x=y3;
   y3=y1;
   y1=x;}
   s=0;
   }
   if (y2>y1&&y2>y3&&s==1)
   {if (y1<y3)
   {x=y2;
   y2=y1;
   y1=x;
   s=0;}
   else
   {x=y3;
   y3=y2;
   y2=x;
   s=0;}
   }
   if (y3>y1&&y3>y2&&s==1)
   {if (y2<y1)
   {x=y2;
   y2=y3;
   y3=x;
   s=0;}
   else
   {x=y3;
   y3=y1;
   y1=x;
   s=0;}
   }
   printf ("x1=%8.2f x2=%8.2f x3=%8.2f \n", y1,y2,y3); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
