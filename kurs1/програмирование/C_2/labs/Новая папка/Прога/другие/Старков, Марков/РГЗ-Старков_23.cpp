#include <stdlib.h> 
#include <graphics.h>
#include <math.h> 
#include <conio.h>
int c1=50,c2=50,flag=1,cat=1,check=1,rr=1,control=1;
int random (int N) { return rand() % N; }
int seep (int cord, int cord2, int COL){

moveto(cord+7,cord2+3);
setcolor(COL);
lineto(cord,cord2);
lineto(cord+7,cord2-3);
lineto(cord+7,cord2+20);
lineto(cord+2,cord2+20);
lineto(cord+12,cord2+30);
lineto(cord+62,cord2+30);
lineto(cord+72,cord2+20);
lineto(cord,cord2+20);
rectangle(cord+15,cord2+20,cord+60,cord2+13);
rectangle(cord+45,cord2+13,cord+50,cord2-10);


}

int choose(int alpha,int beta)
{rectangle(alpha,beta,alpha+600,beta+60);
	
}


int menut(){
	setfillstyle(1, 0);
	bar (11, 11, 629, 629);
setcolor(GREEN);
rectangle(10,10,630,630);
rectangle(1,1,639,639);
setfillstyle ( 8, 2 );
floodfill (2, 2, 2);
settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
outtextxy ( 220, 20, "MENU" );
outtextxy ( 30, 90, "Free movement" );
outtextxy ( 30, 150, "Keyboard motion" );
outtextxy ( 30, 210, "Out" );}

int menu(){
	int cat=1,num=0,code;
while (cat){
	if ( kbhit() )  {
	
code=getch();}
switch(code){
	case 80: num++; break;
	case 72: num--; 

}
if(num==3) num--;
if(num==-1) num++;
menut();
switch(num){
	case 0:choose (20,75); break;
	case 1:choose (20,145); break;
	case 2:choose (20,205); break;
}
while (kbhit()!=1){}
if ( kbhit() )
   if ( getch() == 13 ) {
   	return num;
   }
}
}

int dv (int x,int y){
	int ran;
if (rr)	{
	ran=random(5-2+1) + 2;
	rr=0;
}
else if(rr==0){
ran=random(1-0+1) + 0;
rr=1;
}
printf("%d",rr);
if((x==11)&&(y==21)&&(rr==0)) ran=2;
if((x==11)&&(y==599)&&(rr==0)) ran=4;
if((x==557)&&(y==21)&&(rr==0)) ran=5;
if((x==557)&&(y==559)&&(rr==0)) ran=3;
if((x==11)&&(y==21)&&(rr==1)) ran=1;
if((x==11)&&(y==599)&&(rr==1)) ran=0;
if((x==557)&&(y==21)&&(rr==1)) ran=1;
if((x==557)&&(y==559)&&(rr==1)) ran=0;

while((x+82<640)&&(y+40<640)&&(x-10>0)&&(y-20>0))
{
seep (x,y,5);
delay(5);
seep (x,y,0);
switch(ran){
case 0: y--; break;
case 1: y++; break;
case 2: x++; y++; break;
case 3: x--; y--; break;
case 4: x++; y--; break;
case 5: x--; y++; break;
}
if ( kbhit() )  
if ( getch() == 27 ) {
 check=0;
break;
}
}
switch(ran){
case 0: y++; break;
case 1: y--; break;
case 2: x--; y--; break;
case 3: x++; y++; break;
case 4: x--; y++; break;
case 5: x++; y--; break;
}

c1=x;c2=y;
}

int free(){
	setfillstyle(1, 0);
	bar (11, 11, 629, 629);
while((1)&&(check)){
dv(c1,c2);

}
}

int keys(){
	int kn,x,y;
	x=c1; y=c2;
while((x+82<640)&&(y+40<640)&&(x-10>0)&&(y-20>0)&&(check))
{
seep (x,y,5);
if ( kbhit() ) {
	setfillstyle(1, 0);
	bar (11, 11, 629, 629);
kn=getch();
switch(kn){
case 52: x--; break;
case 50: y++; break;
case 56: y--; break;
case 54: x++; break;
case 27: check=0; break;
}
}
if(x>=558) x--;
if(x<=10) x++;
if(y>=600)y--;
if(y<=20)y++;


}
c1=x;c2=y; 
}
int motionkey()
{
	setfillstyle(1, 0);
	bar (11, 11, 629, 629);
	while(check)
	keys();
}

int main() 
{
	int flag;
initwindow(700,700);
label:
	check=1;
flag=menu();
if(flag==0){
free();
	goto label;
}
else if(flag==1)
{motionkey();
goto label;
	}	
else if(flag==2)
{
	closegraph();
}
return 0;
}
