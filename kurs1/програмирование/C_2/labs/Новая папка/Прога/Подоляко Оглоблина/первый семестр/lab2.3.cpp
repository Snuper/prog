#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float y1,y2,y3,y4 ;
    printf("Input y1,y2,y3,y4 ");   scanf("%f%f%f%f",&y1,&y2,&y3,&y4); 
 if (y1<0) (y1=0);
  if (y2<0) (y2=0);
   if (y3<0) (y3=0);
    if (y4<0) (y4=0);
 
  printf("y1=%4.0f  y2=%4.0f y3=%4.0f y4=%4.0f \n",y1,y2,y3,y4 ); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
