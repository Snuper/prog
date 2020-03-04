#include <stdlib.h>
#include <graphics.h>
int main()
{
 initwindow(640,360);
 moveto(110,30);
 setcolor(GREEN);         
 circle (100,30,10); 
 setfillstyle ( 1, 0 ); // стиль 1, цвет 12
 bar (100,10,80,50);
 moveto(0,0);        
 lineto(20,0);   
 moveto(20,0);        
 lineto(40,20); 
 moveto(40,20);        
 lineto(60,20);
 moveto(60,20);        
 lineto(90,10);
 moveto(90,10);        
 lineto(100,20);
 moveto(100,40);        
 lineto(20,40);
 moveto(20,40);        
 lineto(0,0);
 moveto(50,30);        
 lineto(20,60);
 moveto(20,60);        
 lineto(40,60);
 moveto(40,60);        
 lineto(90,30);
 
 getch();            
 closegraph();       
 return 0;
}

