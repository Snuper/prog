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
	
    x = -20;
    y = (1+x);
    moveto(widht/2 + x*10, hieght/2 - y*10);
	for (x = -20; x <= 20; x++) 
	{
		y =(1+x) ; 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 

	}
	outtextxy(widht/2 + 80, hieght/2 - 88, "y = (1+x)");
	
	
	x = -20;
	y = pow(x,2);
	moveto(widht/2 + x*5, hieght/2 - y);
    for (x = -20; x <= 20; x+=0.2) 
	{
		y = pow(x,2); 
		setcolor(WHITE); 
		lineto(widht/2 + x*5, hieght/2 - y); 
		moveto(widht/2 + x*5, hieght/2 - y); 
	}
	outtextxy(widht/2 + 95 , hieght/2 - 280, "y = pow(x,2)"); 
	
	setfillstyle(1,MAGENTA); 
	floodfill(widht/2 + 1, hieght/2 - 5, WHITE); 
	floodfill(widht/2 - 2, hieght/2 - 5, WHITE);
	
	
	getch(); 
	closegraph(); 
}

