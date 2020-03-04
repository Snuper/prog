#include <stdlib.h> 
#include <graphics.h>
#include <math.h> 
int main() 
{
	
float y1,y2,x,z,s;
int i;

initwindow(640,640);
moveto(320,0); 
lineto(320,640);
moveto(0,320); 
lineto(640,320);
outtextxy (330, 10, "y");
outtextxy (610, 300, "x");

i=0;
while(i!=640) {
moveto(i,320);
lineto(i,322);
lineto(i,318);
moveto(320,i);
lineto(322,i);
lineto(318,i);
i+=10;}         

i=0; 
x=-3;
y1=(1+x);
moveto(x*50+320,320-y1*50);
x=3;
y1=(1+x);
lineto(x*50+320,320-y1*50);
outtextxy (160, 420, "y1=1+x;");

x=-3;
y2=x*x;
moveto(x*50+320,320-y2*50);
while(x<=3){
x+=0.1;
y2=x*x;
lineto(x*50+320,320-y2*50);
}
outtextxy (220, 120, "y2=x*x;");

setfillstyle ( 1, 15 );  
floodfill (322, 315,15);
floodfill (319, 315,15);  

printf ("abscissi tochek peresecheniya:");
s=0;
for (x=-5;x<=0;x+=0.01) {
y1=x*x;
y2=(1+x);
s=(y1/y2);
if ((s>0.98)&&(s<1.02))
printf("\nx1=%f",x);
}
s=0;
for (x=0;x<=5;x+=0.01) {
y1=x*x;
y2=(1+x);
s=(y1/y2);
if ((s>0.99)&&(s<1.00))
printf("\nx2=%f",x);}
getch(); 
closegraph(); 
return 0; 
}
