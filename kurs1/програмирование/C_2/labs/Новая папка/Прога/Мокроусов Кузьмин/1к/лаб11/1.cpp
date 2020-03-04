#include <stdlib.h>
#include <graphics.h>
#include <math.h>
int main()
{
	float i1,i,a=0,a1=0;
 initwindow(700,700);         
 setcolor(GREEN); 
 moveto(100,150);
for(i=0;i<5;i+=0.01){
	a1=sqrt(25-i*i);
	if (a1<2) break;
	a=a1*100;
	i1=i*100;
	a=650-a;
	i1=100+i1;
//	printf("%f %f \n",a,i1);
	setcolor(GREEN);
	lineto(i1,a);   
	moveto(i1,a);
 } 
 lineto(100,a);  
 moveto(100,a);
 lineto(100,150);  
// circle(200,300,10);
 setfillstyle(1,2);
 floodfill(200,300,2);
  setcolor(15);     
 outtextxy(500,330, "f1(x)= sqrt(25-x*x)");
 outtextxy(400,a+10, "f2(x)= 2");
 printf("%f ", i1);

 //moveto(100,120);         
 //lineto(150,120);
 //floodfill(101,125,1);


 getch();            
 closegraph();        
 return 0;
}

