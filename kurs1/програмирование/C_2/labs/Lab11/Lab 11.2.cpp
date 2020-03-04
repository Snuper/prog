#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

const int widht = 800, hieght = 600; 

int main()
{
	float x , y; 
	
	initwindow(widht, hieght); 
	
	setcolor(WHITE); 
	moveto(widht/2,0); 
	lineto(widht/2, hieght); 
	outtextxy(widht/2 + 10 , 20, "Y ^"); 
	
	setcolor(WHITE); 
	moveto(0,hieght/2); 
	lineto(widht, hieght/2); 	
	outtextxy(widht - 50, hieght/2 - 20, "X ->");
	for (x = 0; x <= 20; x++) 
	{
		y = pow(x,3); 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y); 
		moveto(widht/2 + x*10, hieght/2 - y); 

	}
	outtextxy(widht/2 + 80, 50, "y = pow(x,3)");
	y = sqrt(x);
	moveto(widht/2  , hieght/2  );

	for (x = 0; x <= 30; x+=0.2) 
	{
		y = sqrt(x); 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 
	}
	outtextxy(widht/2 + 300 , hieght/2 - 80, "y = sqrt(x)"); 
	
	setfillstyle(1,RED); 
	floodfill(widht/2 +1, hieght/2 - 1,WHITE); 
	
	
	getch(); 
	closegraph(); 
}

