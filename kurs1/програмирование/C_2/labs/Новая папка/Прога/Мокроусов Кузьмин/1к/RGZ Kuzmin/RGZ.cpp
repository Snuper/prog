#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
const int n=600;

int random (int N) { return rand() % N; }
int x=50, y=50, c;


void draw ()
{
setfillstyle(1,0);
bar(0,0,n-1,n-1);
setcolor(5);
moveto(x+5,y+40);			
lineto(x+110,y+40);
moveto(x+10,y+50);
lineto(x+90,y+50);
moveto(x+5,y+40);
lineto(x+10,y+50);
moveto(x+110,y+40);
lineto(x+90,y+50);
moveto(x+35,y+35);			
lineto(x+65,y+35);
moveto(x+35,y+35);
lineto(x+35,y+40);
moveto(x+65,y+35);
lineto(x+65,y+40);  
moveto(x+55,y+35);             
lineto(x+55,y+5);     
moveto(x+50,y+35);       
lineto(x+50,y+5);      
moveto(x+50,y+5);        
lineto(x+55,y+5);      
moveto(x+10,y+40);          
lineto(x+10,y+10);
moveto(x+10,y+10);
lineto(x+5,y+15);
moveto(x+10,y+20);
lineto(x+5,y+15);
}

void Pravo(){
	while (c>0){
	draw();
	delay(30);
	x+=2;
	if (x+120>n) break;
	c--;
	draw();
}
}

void Levo(){
	while (c>0){
	draw();
	delay(30);
	x-=2;
	if (x<0) break;
	c--;
	draw();
}
}

void Verh(){
	while (c>0){
	draw();
	delay(30);
	y-=2;
	if (y<0) break;
	c--;
	draw();
}
}

void Niz(){
	while (c>0){
	draw();
	delay(30);
	y+=2;
	if (y+60>n) break;
	c--;
	draw();
}
}

void sluchaino(){
     closegraph();
int k,f;
initwindow(n,n);
while(1){
c=random(300);
k=random(4);
if (kbhit())
	if (getch()==27) {
	closegraph();
	break;
	}
if (k==0) {						
	Pravo();
	if (x+120>=n) Levo();
}
if (k==1) {						
	Levo();
	if (x<=0) Pravo();
}
if (k==2) {						
	Verh();
	if (y<=0) Niz();
}
if (k==3) {						
	Niz();
	if (y+60>=n) Verh();
}
}
}


void klaviatura ()
{
     closegraph();
int key;
initwindow(n,n);
draw();
while(1){

if (kbhit())
getch();
key=getch();
if (key==27) break;

delay(20);
switch(key){

case 50: y+=5;  draw(); break;					
case 56: y-=5;	draw(); break;						
case 54: x+=5;	draw(); break;					
case 52: x-=5;	draw(); 							

}
if (x+110>n) { printf("Nedopustimoe peremeshchenie\n");
x-=10;

}
if (x<0) { printf("Nedopustimoe peremeshchenie\n");
x+=10;

}
if (y+70>n) {printf("Nedopustimoe peremeshchenie\n");
y-=10;

}
if (y<0) {printf("Nedopustimoe peremeshchenie\n");
y+=10;

}
}
closegraph();
}

int main()
{
    initwindow(n,n);
    setcolor(5);
int k;
outtextxy(100, 200, "Viberite deistvie:");
outtextxy(100, 225, "	1. Svobodnoe dvizhenie");
outtextxy(100, 250, "	2. Upravlenie posredstvom klaviatury");
outtextxy(100, 275, "	3. Vihod is programmy");
if (kbhit())
getch();
k=getch();
if (k==49) sluchaino();
if (k==50) klaviatura();
if (k==51) return 0; 
main();
}







