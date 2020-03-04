#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

const int widht = 800, hieght = 600; 

int main()
{
	int x , y; 
	
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
    y = pow(x-2,2);
    moveto(widht/2 + x*10, hieght/2 - y*10);
	for (x = -20; x <= 20; x++) 
	{
	    y = pow(x-2,2) ; 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 

	}
	outtextxy(widht/2 + 80, hieght/2 - 200, "y = pow(x-2)");
	
	
	y = 4; 
	moveto(widht/2 + x *10, hieght/2 - y*10);	 
	
	
	for (x = -20; x <= 20; x++) 
	{
		y = 4; 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 
	}
	outtextxy(widht/2 + 80 , hieght/2 - 60, "y = 4");
	
	setfillstyle(1,YELLOW); 
	floodfill(widht/2+20 , hieght/2 - 5, WHITE); 
	
	
	
	getch(); 
	closegraph(); 
}
