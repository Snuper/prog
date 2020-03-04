#include <stdlib.h> 
#include <graphics.h>
#include <math.h> 
int main() 
{
	
float flag=0,y=0,x=16;
int i ;
y=sqrt(x-3);

initwindow(640,640);
moveto(320,0); 
lineto(320,640);
moveto(0,320); 
lineto(640,320);

i=0;
do{
moveto(i,320);
lineto(i,322);
lineto(i,317);
moveto(320,i);
lineto(322,i);
lineto(317,i);
i+=10;
}while(i!=640);
i=0;
x=3;
y=sqrt(x-3);
moveto(x*10+320,320-y*10);
x=19.9;
y=sqrt(x-3);
lineto(x*10+320,320-y*10);
x=16;
y=-10;
moveto(x*10+320,320-y*10);
x=16;
y=10;
lineto(x*10+320,320-y*10);

setfillstyle ( 1, 6 );  
floodfill (400, 315,15);

x=16;
y=sqrt(x-3);

 
outtextxy ( 50, 300, "Peresechenye v console ");
printf("peresechenie x=%f y=%f",x,y);











 
getch(); 
closegraph(); 
return 0; 
}


