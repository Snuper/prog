#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,sum,p,y1,y2,y3,y4,y5,y6 ;
    printf("Input y1,y2,y3,y4,y5,y6 ");   scanf("%f%f%f%f%f%f",&y1,&y2,&y3,&y4,&y5,&y6);
    sum=y1+y2+y3+y4+y5+y6; p=y1*y2*y3*y4*y5*y6;   
 if (p>sum)   (x=p-sum);
 else
 (x=sum-p);
  printf("x=%8.2f  \n",x ); 
   system("PAUSE");
   return EXIT_SUCCESS;
}






















