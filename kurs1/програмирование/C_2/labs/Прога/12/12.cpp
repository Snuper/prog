#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Draw (int x, int y, int color) 
{ 
setcolor(color);
moveto(x,y-20);
lineto(x,y+20);
moveto(x-20,y);
lineto(x+20,y);
moveto(x-13,y-13);
lineto(x+13,y+13);
moveto(x+13,y-13);
lineto(x-13,y+13);
}
const int N = 600;
int random (int N) { return rand()%N;}
main()
{	
int x, y, i,color;
int a[50];
srand(42);
initwindow (600, 600);
setfillstyle(1, 0);
bar (0, 0, 599, 599);
while(x<700)
{
for(i=0;i<51;i++)
{
	x=random(601);
	y=random(601);
	color=random(14)+1;
	Draw(x,y,color);
}
delay(1000);
setfillstyle(1, 0);
bar (0, 0, 599, 599);
delay(30);
}
getch();
closegraph();
return 0;
}
