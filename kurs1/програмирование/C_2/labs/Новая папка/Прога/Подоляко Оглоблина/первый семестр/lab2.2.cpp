#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float sum,y1,y2,y3,y4,y5, ;
    printf("Input y1,y2,y3,y4,y5 ");   scanf("%f%f%f%f%f",&y1,&y2,&y3,&y4,&y5); 
    sum=0;
 if (y1>0) (sum=sum+y1);
  if (y2>0) (sum=sum+y2);
   if (y3>0) (sum=sum+y3);
    if (y4>0) (sum=sum+y4);
     if (y5>0) (sum=sum+y5);
  printf("sum=%8.2f  \n",sum ); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
