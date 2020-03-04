#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>
#include <ctime>
#define width 1366
#define height 500 

void DRAW(int x, int y, int color1, int color2) 
{
int i, a = 1, b = 4;
setcolor(color1);
moveto(x+400,y+350);
lineto(x+410,y+350);
moveto(x+400,y+395);        //труба
lineto(x+400,y+350);
moveto(x+410,y+395);
lineto(x+410,y+350);

moveto(x+340,y+395);
lineto(x+450,y+395);    //Трюм
moveto(x+340,y+395);
lineto(x+340,y+410);  
moveto(x+450,y+395);
lineto(x+450,y+410);

moveto(x+300,y+410);
lineto(x+480,y+410);   //Нижгняя труба

moveto(x+300,y+410);
lineto(x+310,y+430);
moveto(x+480,y+410); //Основа.Тело
lineto(x+470,y+430);

moveto(x+310,y+430); //Дно
lineto(x+470,y+430);

moveto(x+310,y+410);
lineto(x+310,y+390);
moveto(x+310,y+390);
lineto(x+320,y+392);    //Флаг  
moveto(x+320,y+392);
lineto(x+310,y+395);
} 
void MENU(int x, int y, int color1, int color2) 
{ 
setcolor(9); 
line(x+800,y+170,x+500,y+170); 
line(x+500,y+100,x+500,y+310); 
line(x+800,y+100,x+800,y+310); 
line(x+800,y+100,x+500,y+100); 
line(x+800,y+310,x+500,y+310); 
line(x+800,y+240,x+500,y+240); 
setcolor(9); 
outtextxy(x+550,y+130, "1 - Свободное движение"); 
setcolor(9); 
outtextxy(x+550,y+200, "2 - Управляемое движение"); 
setcolor(9); 
outtextxy(x+550,y+267, "3 - Выход"); 
} 

const int N = 4;
void uncontrolled() 
{ srand(time(0)); 
int ping = 100, code, flag = 0, x = 70, y = 70, vector = 1; 
initwindow(width,height); 
while(1) 
{ 
if(kbhit()) flag = getch(); 
if (flag == 32) break;  
DRAW(x, y, 0, 0); 
if (ping == 100)
{
vector = rand()%4 + 1;
ping = 0;
}
if (vector == 1 and y<250) { 
++y; 
} else if (vector == 2 and x<885) { 
++x; 
} else if (vector == 3 and y>-550) { 
--y; 
} else if (vector == 4 and x > -300) { 
--x; 
delay(10);
ping++;
} 
DRAW(x, y, 15, 15); 
if (ping == 100) 
{
vector = rand()%4 + 1;
ping = 0; 
if (vector == 1 and y<250) vector = 3; 
else if (vector == 2 and x<885) vector = 4; 
else if (vector == 3 and y>-550) vector = 1; 
else if (vector == 4 and x > -300) vector = 2; 
} 
delay(10); 
ping++;
} 
} 

void controlled() 
{ 
srand(time(NULL)); 
int code,flag = 1, x = 70, y = 70; 
initwindow(width,height); 
{DRAW(x, y, 15, 15); 
while(flag) 
{code = getch(); 
switch ( code ) 
{ 
case 75: if(x > -300) {DRAW(x, y, 0, 0); x--; DRAW(x, y, 15, 15);} break; 
case 77: if(x<885) {DRAW(x, y, 0, 0); x++; DRAW(x, y, 15, 15);} break; 
case 72: if(y>-350) {DRAW(x, y, 0, 0); y--; DRAW(x, y, 15, 15);} break; 
case 80: if(y<250) {DRAW(x, y, 0, 0); y++; DRAW(x, y, 15, 15);} break; 
case 32: flag = 0;break; 
default: break; 

} 

} 
} 
} 
void back() 
{ 
srand(time(NULL)); 
int code, x = 70, y = 70; 
closegraph(); 
initwindow(width,height); 
MENU(x, y, 1, 1); 
} 
int main() 
{ 
initwindow(width,height); 
int code,flag = 1, x=70, y=70; 
setcolor(9);  
line(x+800,y+170,x+500,y+170); 
line(x+500,y+100,x+500,y+310); 
line(x+800,y+100,x+800,y+310); 
line(x+800,y+100,x+500,y+100); 
line(x+800,y+310,x+500,y+310); 
line(x+800,y+240,x+500,y+240); 
setcolor(9); 
outtextxy(x+550,y+130, "1 - Свободное движение"); 
setcolor(9); 
outtextxy(x+550,y+200, "2 - Управляемое движение"); 
setcolor(9); 
outtextxy(x+550,y+267, "3 - Выход");  

MENU(x, y, 1, 1); 
while (flag) { 
code = getch(); 
switch (code) { 
case 49: { 
closegraph(); 
uncontrolled(); 
back(); 
};break; 
case 50: { 
closegraph(); 
controlled(); 
back(); 
};break; 
case 51: { 
closegraph(); 
flag = 0; 
};break; 
case 36: 
case 32: { 
back(); 
};break; 
default:break; 
} 
} 
return 0; 
}
