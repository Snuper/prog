#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
    
	void Draw(int x,int y,int w,int color1,int color2)
{ 
setcolor(color1);
setfillstyle(1,color2);
circle(x,y,w);
floodfill(x,y,color1);
moveto(x-w*2/3,y-w*2/3);
lineto(x+w*2/3,y+w*2/3);
moveto(x+w*2/3,y-w*2/3);
lineto(x-w*2/3,y+w*2/3);
}

void Menu(){
		setfillstyle(1, 0); 

bar (0, 0, 1279, 719); 

outtextxy(50,50,"1.Free move");
outtextxy(50,100,"2.Move with help of keyboard");
outtextxy(50,150,"3.Exit"); 
line(45,45,450,45);
line(450,45,450,180);
line(450,180,45,180);
line(45,180,45,45);
line(45,85,450,85);
line(45,125,450,125);

}

	  
main()
{
int n,x,y,w,code;
initwindow (1280, 720);
Menu();
while(1)
{
if(kbhit())
n=getch();
	if (n==51)
{
	closegraph();
	return 0;
}
	if (n==49)
{
initwindow(400, 400);
setfillstyle(1, 0);
bar (0, 0, 399, 399);
if ( kbhit() )
if ( getch() == 27 )
break;
w=20; y=w+100; x=w+1;
while(1)
{
if ( kbhit() )
if ( getch() == 27 )
break;
	while((x<400-w) and (y<400-w) and(x>w) and (y>w))
		{
		Draw (x,y,w,15,4);
		delay (10);
		Draw (x,y,w,0,0);
		x++;
		y++;
		}
w=w*0.5;
y=399-w;
if ( kbhit() )
if ( getch() == 27 )
break;
	while((x<400-w) and (y<400-w) and(x>w) and (y>w))
		{
		Draw (x,y,w,15,4);
		delay (10);
		Draw (x,y,w,0,0);
		x++;
		y=y-1;
		}
w=w*1.5;
x=399-w;
if ( kbhit() )
if ( getch() == 27 )
break;
	while((x<400-w) and (y<400-w) and(x>w) and (y>w))
		{
		Draw (x,y,w,15,4);
		delay (10);
		Draw (x,y,w,0,0);
		x=x-1;
		y=y-1;
		}
w=w*1.5;
y=w+1;
if ( kbhit() )
if ( getch() == 27 )
break;
	while((x<400-w) and (y<400-w) and(x>w) and (y>w))
		{
		Draw (x,y,w,15,4);
		delay (10);
		Draw (x,y,w,0,0);
		x=x-1;
		y++;
		}
w=w*0.5;
x=w+1;
}
closegraph();
initwindow(1280, 720);
Menu();
break;
}
	if (n==50)
{
initwindow(400, 400);
setfillstyle(1, 0);
bar (0, 0, 399, 399);
w=20; y=200; x=200;
while ( 1 )
{
Draw (x,y,w,15,4);
code = getch();
if ( code == 27 )
break;
Draw (x,y,w,0,0);
switch ( code )
{
case 75: x --; break;
case 77: x ++; break;
case 72: y --; break;
case 80: y ++;
}
}
Menu();
}
}
}
