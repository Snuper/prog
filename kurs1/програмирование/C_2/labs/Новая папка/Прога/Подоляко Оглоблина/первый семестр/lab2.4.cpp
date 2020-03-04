#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float p,o,y1,y2,y3,y4, y5,y6,y7,y8 ;
    printf("Input y1,y2,y3,y4,y5,y6,y7,y8");   scanf("%f%f%f%f%f%f%f%f",&y1,&y2,&y3,&y4,&y5,&y6,&y7,&y8); 
    (p=0); (o=0);
 if (y1>0) (p=p+1) ;else (o=o+1);
 if (y2>0) (p=p+1) ;else (o=o+1);
 if (y3>0) (p=p+1) ;else (o=o+1);
 if (y4>0) (p=p+1) ;else (o=o+1);
 if (y5>0) (p=p+1) ;else (o=o+1);
 if (y6>0) (p=p+1) ;else (o=o+1);
 if (y7>0) (p=p+1) ;else (o=o+1);
 if (y8>0) (p=p+1) ;else (o=o+1);
  
  printf("p=%4.0f  o=%4.0f \n",p,o ); 
   system("PAUSE");
   return EXIT_SUCCESS;
}
