#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
using namespace std;

main(){
int key;
printf ("1. Svobodnoe dvijenie \n2. Dvijenie ob'ekta s pomoshu klavish \n3. Exit\n");
scanf ("%d", &key);
switch(key){
    case 1:
    int dx=2,dy,dy1,x=50,y=50,x1=100,y1=100,ch;
    printf ("Vvedite koornitany Y");
    scanf ("%d", &dy);
    dy1=dy;
 initwindow(800,800); 
 while(ch!=27)
 {
  	delay(20);
  	cleardevice();
  if (x>=750) dx=-2;
  if (y>=750) dy=-dy1;
  if (x<=0) dx=2;
  if (y<=25) dy=dy1;
  
  x=x+dx;
  y=y+dy;
  x1=x1+dx;
  y1=y1+dy;
  
  setcolor(15);
  rectangle(x,y,x1,y1);
  rectangle(x+15,y+10,x1-15,y1-15);
  moveto(x+25,y+10);
  lineto(x+25,y1-15);
  moveto(x+25,y-25);
  lineto(x-5,y+10);
  moveto(x+25,y+20);
  lineto(x1-15,y+20);
  setfillstyle(1,5);
  floodfill(x+17,y+8,15);
  moveto(x+25,y-25);
  lineto(x+55,y+10);
  setfillstyle(1,10);
  floodfill(x+25,y-20,15);
  if(kbhit()){
  	ch=getch();
  }
  
}	
	closegraph();
	return 0;
}
switch(key){
    case 2:
    
int dx=5,dy=5,x=50,y=50,x1=100,y1=100,ch;
initwindow(800,800);

setcolor(15);
rectangle(x,y,x1,y1);
rectangle(x+15,y+10,x1-15,y1-15);
moveto(x+25,y+10);
lineto(x+25,y1-15);
moveto(x+25,y-25);
lineto(x-5,y+10);
moveto(x+25,y+20);
lineto(x1-15,y+20);
setfillstyle(1,5);
floodfill(x+17,y+8,15);
moveto(x+25,y-25);
lineto(x+55,y+10);
setfillstyle(1,10);
floodfill(x+25,y-20,15);

do{  ch=getch();                 
     if(ch==0){ch=getch();
     delay(1);
     cleardevice();
     
setcolor(15);
rectangle(x,y,x1,y1);
rectangle(x+15,y+10,x1-15,y1-15);
moveto(x+25,y+10);
lineto(x+25,y1-15);
moveto(x+25,y-25);
lineto(x-5,y+10);
moveto(x+25,y+20);
lineto(x1-15,y+20);
setfillstyle(1,5);
floodfill(x+17,y+8,15);
moveto(x+25,y-25);
lineto(x+55,y+10);
setfillstyle(1,10);
floodfill(x+25,y-20,15);
  
     if(ch==72){ y=y-dy; y1=y1-dy;}
     if(ch==80){ y=y+dy; y1=y1+dy;}
     if(ch==75){ x=x-dx; x1=x1-dx;}
     if(ch==77){ x=x+dx; x1=x1+dx;}
         
          }
          }
          while (ch!=13);
}
switch(key){
    case 3:
     exit(0);
    }

    getch();            
    closegraph();       
    return 0;
}
