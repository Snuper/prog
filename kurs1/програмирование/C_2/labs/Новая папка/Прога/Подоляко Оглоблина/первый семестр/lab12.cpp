#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
void Draw ( int x, int y, int color1)
{  setcolor(color1);
	moveto(x,y);
	 lineto(x+16,y);
	 lineto(x-16,y);  
	moveto(x,y);
	 lineto(x,y+16);
     lineto(x,y-16);
	moveto(x,y);
     lineto(x+12,y+12);
	 lineto(x-12,y-12);  
	moveto(x,y);
     lineto(x-12,y+12);
	 lineto(x+12,y-12); 
}
int random (int N) {return rand() % N;}
main()
{
   int x=0,y=0,i,c; 
   initwindow (640, 640); 
   setfillstyle(1, 0);
   bar (0, 0, 639, 639); 

   while (1) 
  {
    if ( kbhit() ) 
       if ( getch() == 27 )  
            break; 
            
    for(i=0;i<100;i++){
    	x=random(608);
    	y=random(608);
    	c=random(16);
    	Draw ( x, y, c); 
	}
	delay(1000); 
    bar (0, 0, 640, 640); 
  }
  closegraph(); 
}
