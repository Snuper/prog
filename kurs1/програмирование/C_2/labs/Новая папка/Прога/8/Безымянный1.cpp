#include <stdlib.h>
#include <graphics.h>
#include <math.h>
int main()
{
float x,f1,f2;	
initwindow(640,360); // ??????? ??????????? ???? 640 ?? 360 ????????
moveto(0,360);
for(x=0;x<641;x++)
{
f1=x*x*x;
lineto(x,360-f1);
}
for(x=0;x<641;x++)
{
f2=sqrt(x);
lineto(x,360-f2);
}
outtextxy (15,60, "FUNCTION f(x)=x*x*x;");
outtextxy (400,310, "FUNCTION f(x)=sqrt(x);");
setfillstyle (1,4);
floodfill (500,250,15);
getch();
closegraph(); // ????????? ??????????? ????
return 0;
}
