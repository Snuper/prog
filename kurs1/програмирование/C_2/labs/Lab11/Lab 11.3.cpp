#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


const int widht = 800, hieght = 800; 

int main()
{
	int x = -10, y, f2, i = 0; 
	
	initwindow(widht, hieght); 
	setcolor(WHITE); 
	moveto(widht/2,0); 
	lineto(widht/2, hieght); 
	outtextxy(widht/2 + 10, 70, "Y ^"); 
	
	setcolor(WHITE); 
	moveto(0,hieght/2); 
	lineto(widht, hieght/2); 
	outtextxy(widht - 50, hieght/2 - 20, "X ->"); 
	
	
	
	for (; x <= 10; x++) 
	{
		i = ((abs(x)) % 4); 
		y = cos(x%2); 
		setcolor(WHITE); 
		if(i == 0) 
		{
			arc(widht/2 + x*15, hieght/2, 0, 180, 15); 
			moveto(widht/2 + x*15, hieght/2); 
	    }
		else if (i == 2) 
		{
			y *= -1; 
			arc(widht/2 + x*15, hieght/2, -180, 0, 15); 
			moveto(widht/2 + x*15, hieght/2); 

		}
	}
	
	outtextxy(widht/2 - 150, hieght/2 - 50, "cos(x)"); 
	
	
	x = -20;
	y = pow(x,2);
	moveto(widht/2 + x*2, hieght/2 - y);
	
	
	
	for (x = -20; x <= 20; x++) 
	{
		y = pow(x,2); 
		setcolor(WHITE); 
		lineto(widht/2 + x*2, hieght/2 - y); 
		moveto(widht/2 + x*2, hieght/2 - y); 
	}
	
	outtextxy(widht/2 + 50, 50, "pow(x,2)"); 
	
	setfillstyle(1, LIGHTCYAN); 
	floodfill(widht/2 + 1, hieght/2 - 7.5, WHITE); 
	floodfill(widht/2 - 1, hieght/2 - 7.5, WHITE); 
	
	
	getch(); 
	closegraph(); 
}

