#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

const int widht = 800, hieght = 600; 

int main()
{
	int x = -20, y, i = 0; 
	
	initwindow(widht, hieght); 
	
	setcolor(WHITE); 
	moveto(widht/2,0); 
	lineto(widht/2, hieght); 
	outtextxy(widht/2 + 10 , 30, "Y ^"); 
	
	
	setcolor(WHITE); 
	moveto(0,hieght/2); 
	lineto(widht, hieght/2); 	
	outtextxy(widht - 50, hieght/2 - 20, "X ->"); 
	
	y = sqrt(25 - pow(x,2));
	moveto(widht/2 + x*10, hieght/2 - y*10);
	
	
	for (float a = -20; a <= 20; a += 2.1) 
	{
		y = sqrt(25 - pow(a,2)); 
		setcolor(WHITE); 
		lineto(widht/2 + a*10, hieght/2 - y*10); 
		moveto(widht/2 + a*10, hieght/2 - y*10); 
	}
	outtextxy(widht/2 - 100 , hieght/2 - 100, "y = sqrt(25 - pow(x,2))"); 
	
	
	y = 2; 
	moveto(widht/2 + x *10, hieght/2 - y*10);	
	
	
	for (x = -20; x <= 20; x++) 
	{
		y = 2; 
		setcolor(WHITE); 
		lineto(widht/2 + x*10, hieght/2 - y*10); 
		moveto(widht/2 + x*10, hieght/2 - y*10); 
	}
	outtextxy(widht/2 + x*10 , hieght/2 - 20, "y = 2"); 
	
	
	setfillstyle(1,GREEN); 
	floodfill(widht/2 - 1, hieght/2 - y,WHITE); 
	floodfill(widht/2 + 1, hieght/2 - y,WHITE); 
	
	getch(); 
	closegraph(); 
}

