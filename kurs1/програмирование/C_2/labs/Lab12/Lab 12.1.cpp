#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>

const int width = 1200, height = 800; 
const int M = 500; 
int i; 

void DRAW(int x, int y, int color1, int color2) 
{
	setcolor(color1); 
	setfillstyle(1, color2); 
 
    
    line(x-5, y, x+6, y);  
	line(x-5, y-5, x+6, y+6);  
	line(x-5, y+5, x+6, y-6);  
	line(x, y-5, x, y+6); 
	
    
}

int main()
{
	initwindow(width,height); 
	srand(time(0)); 
	int x[M], y[M], color1; 

	for(i = 0; i < M; i++)  
	{
		x[i] = rand() % (1 + (width-1));
		y[i] = rand() % (1 + (height-1)); 
	}

	while(1) 
	{
	if (kbhit()) 
	if(getch() == 27)
	{
		break; 
	}

	
		i = rand()%M; 
		color1 = rand()%16; 
		DRAW(x[i], y[i], color1, color1); 


		
		delay(10); 
		
		
		i = rand()%M;  
		DRAW(x[i], y[i], 0, 0); 

		i = rand()%M;
		DRAW(x[i], y[i], 0, 0);
		
		i = rand()%M;
		DRAW(x[i], y[i], 0, 0);

		i = rand()%M;
		DRAW(x[i], y[i], 0, 0);
		
	}

	closegraph(); 
}

