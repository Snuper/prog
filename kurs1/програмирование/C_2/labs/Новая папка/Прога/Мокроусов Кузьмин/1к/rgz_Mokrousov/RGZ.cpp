#include <conio.h>
#include <graphics.h>
void Draw ( int x, int y, int color1) // функция рисования круга
                                                                // color1 цвет линий, color2 цвет заливки
{ setcolor(color1);
    moveto(x+110,30);
 setcolor(color1);         
 circle (x+100,y+30,10); 
 setfillstyle ( 1, 0 ); // стиль 1, цвет 12
 bar (x+100,y+10,x+80,y+50);
 moveto(x+0,y+0);        
 lineto(x+20,y+0);   
 moveto(x+20,y+0);        
 lineto(x+40,y+20); 
 moveto(x+40,y+20);        
 lineto(x+60,y+20);
 moveto(x+60,y+20);        
 lineto(x+90,y+10);
 moveto(x+90,y+10);        
 lineto(x+100,y+20);
 moveto(x+100,y+40);        
 lineto(x+20,y+40);
 moveto(x+20,y+40);        
 lineto(x+0,y+0);
 moveto(x+50,y+30);        
 lineto(x+20,y+60);
 moveto(x+20,y+60);        
 lineto(x+40,y+60);
 moveto(x+40,y+60);        
 lineto(x+90,y+30); // заполняем цветом color2 до границы  color1
}
main()
{
   int x, y,code,o,i=200,c=1,c1=1,cc=1; 
   printf("1. Свободное движение объекта \n2. Движение объекта с помощью клавиатуры \n3. Выход из программы\n");
   scanf("%i",&o);
   initwindow (520, 480); 
   setfillstyle(1, 0); 
   bar (0, 0, 500, 500); 
   x = 200; y = 200; 
   
   
   /* анимация */
   if(o==1){
   while (1) 
{
if ( kbhit() ) 	
  code = getch(); 
  if ( code == 27 ) break; 
  		
  		if(c==1) Draw ( i, i, 2); 
  		if(c==2) Draw ( 400-i, i, 3); 
  		if(c==3) Draw ( 400-i, 400-i, 4); 
  		if(c==4) Draw ( i, 400-i, 5); 
    	delay(20); 
    	if(c==1) Draw ( i, i, 0); 
  		if(c==2) Draw ( 400-i, i, 0); 
  		if(c==3) Draw ( 400-i, 400-i, 0); 
  		if(c==4) Draw ( i, 400-i, 0); 
    	if(c1==0) i++;
    	if(c1==1) i--;
    	
    	
	if(i==0 or i==400){
	c1=0;
	
	}
	if(i==200) {
	c1=1;
	if(c==4 and cc==1) {
	c=1;
	cc=0;}
	if(c==3 and cc==1) {
	c=4;
	cc=0;}
	if(c==2 and cc==1) {
	c=3;
	cc=0;}
	if(c==1 and cc==1) {
	c=2;
	cc=0;}
	}
	cc=1;
}}
   
   
   if(o==2){
   while ( 1 ) 
{
  Draw ( x, y, 3); 
  code = getch(); 
  if ( code == 27 ) break; 
  Draw ( x, y, 0 ); 
  switch ( code ) 
  { // выбор направления
    //case 100:  x --; break; // влево
    //case 102:  x ++; break; // вправо
    //case 104:  y --; break; // вверх
    //case 98:  y ++; // вниз
    case 52:  x -=5; break; // влево
    case 54:  x +=5; break; // вправо
    case 56:  y -=5; break; // вверх
    case 50:  y +=5; // вниз
  }
}}
	
  closegraph(); 
}

