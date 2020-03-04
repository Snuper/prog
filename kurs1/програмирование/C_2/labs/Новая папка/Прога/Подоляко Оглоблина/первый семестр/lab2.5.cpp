#include <stdlib.h>
#include <stdio.h>
int main()
{ float y1,y2,y3,y4;
printf("Input y1,y2,y3,y4"); scanf("%f%f%f%f",&y1,&y2,&y3,&y4);
if ((y1<y2)&&(y1<y3)&&(y1<y4)) printf("\n min por=1",1);
else if ((y2<y1)&&(y2<y3)&&(y2<y4)) printf ("\n min por = 2",2);
else if ((y3<y1)&&(y3<y2)&&(y3<y4)) printf ("\n min por = 3",3);
else if ((y4<y1)&&(y4<y2)&&(y4<y3)) printf ("\n min por = 4",4);
system("PAUSE");
return EXIT_SUCCESS;
}

