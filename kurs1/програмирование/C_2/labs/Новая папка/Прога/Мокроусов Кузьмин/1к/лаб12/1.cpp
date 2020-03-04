#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>


void Draw ( int x, int y, int color1)
                                             // color1 цвет линий, color2 цвет заливки
{ setcolor(color1);
    //setfillstyle ( 1, color1 ); // сплошная заливка, цвет color2
    setcolor(color1);
	moveto(x,y);
	lineto(x+6,y+6);
	moveto(x,y+6);
	lineto(x+6,y);
	moveto(x,y+3);
	lineto(x+6,y+3);
    moveto(x+3,y);
	lineto(x+3,y+6); // рисуем окружность радиусом 20 цвет color1
   //floodfill(x,y,color1);  // заполняем цветом color2 до границы  color1
}
int random (int N) {return rand() % N;}
main()
{
   int x=0, y=0,i,z=5,c; 
   initwindow (400, 400); 
   setfillstyle(1, 0);
   bar (0, 0, 399, 399); 

   while (1) 
  {
    if ( kbhit() ) 
       if ( getch() == 27 )  
            break; 
            
    for(i=0;i<100;i++){
    	x=random(394);
    	y=random(394);
    	c=random(16);
    	Draw ( x, y, c); 
	}
	delay(1000); 
    //Draw ( x, y, 0); 
    bar (0, 0, 400, 400); 
  }
  closegraph(); 
}

