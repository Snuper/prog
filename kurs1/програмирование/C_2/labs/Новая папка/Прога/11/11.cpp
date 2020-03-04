#include <stdlib.h>
#include <graphics.h>
#include <math.h>
int main()
{
int x;
float f1,f2;
float m1[640];
float m2[640];	
initwindow(640,360); // ??????? ??????????? ???? 640 ?? 360 ????????
moveto(0,360);
for(x=0;x<641;x++)
{
f1=x*x*x;
lineto(x,360-f1);
m1[x]=x*x*x;
}
for(x=0;x<641;x++)
{
f2=sqrt(x);
lineto(x,360-f2);
m2[x]=sqrt(x);
}
outtextxy (15,60, "FUNCTION f(x)=x*x*x;");
outtextxy (400,310, "FUNCTION f(x)=sqrt(x);");
setfillstyle (1,4);
floodfill (500,250,15);
getch();
closegraph(); // ????????? ??????????? ????
for(x=0;x<641;x++)
{
if(m1[x]=m2[x])
printf("x=%d", &x);
}
return 0;
}
