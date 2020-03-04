#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

const int widht = 1000, hieght = 800; 

int main()
{
	int x , y; 
	
	initwindow(widht, hieght); 
	
	setcolor(WHITE); 
	moveto(widht/2,0); 
	lineto(widht/2, hieght); 
	outtextxy(widht/2 + 20, 20, "Y ^"); 
	
	setcolor(WHITE); 
	moveto(0,hieght/2); 
	lineto(widht, hieght/2); 	
	outtextxy(widht - 40, hieght/2 - 20, "X ->");
	
    x = -81;
    y = pow(x-1,2);
    moveto(widht/2 + x*10, hieght/2 - y*10);
	for (x = -81; x <= 81; x++) 
	{
	    y = pow(x-1,2) ; 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 

	}
	outtextxy(widht/2 + 80, hieght/2 - 300, "y = pow(x-1)");
	

	y = 16; 
	moveto(widht/2 + x *10, hieght/2 - y*10);	 
	
	
	for (x = -81; x <= 81; x++) 
	{
		y = 16; 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 
	}
	outtextxy(widht/2 - 200 , hieght/2 - 190, "y = 16");
	
	setfillstyle(1,BROWN); 
	floodfill(widht/2+10 , hieght/2 - 5, WHITE); 
	floodfill(widht/2-1, hieght/3 - 5, WHITE);
	
	
	getch(); 
	closegraph(); 
}
