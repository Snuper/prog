#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctime>

const int widht = 800, hieght = 600; 
int draw_hero(float x, float y) //рисование самолёта
{
		line(500+x,307+y,300+x,307+y);
		arc(500+x,280+y,272,70,27);
		line(508+x,255+y,480+x,255+y);	
		line(440+x,210+y,480+x,255+y);
		line(380+x,240+y,440+x,210+y);
		line(330+x,240+y,380+x,240+y);
		line(300+x,190+y,330+x,240+y);
		line(250+x,190+y,300+x,190+y);
		line(300+x,307+y,250+x,190+y);
		line(305+x,360+y,355+x,270+y);
		line(330+x,360+y,305+x,360+y);
		line(430+x,270+y,330+x,360+y);
	    
}

int main()
{
	int i = 1,ch,x=0,y=0;
	
	
	
	initwindow(widht, hieght,"РГЗ",0,0,true); 
	do
	{
	cleardevice();
	//рисуем менюшку
	setcolor(WHITE); 
	moveto(widht-550,0); 
	lineto(widht-220,0);
	outtextxy(widht-545 , hieght-598, "1. Свободное движение обьекта");
	moveto(widht-550,hieght-578);
	lineto(widht-220,hieght-578);
	outtextxy(widht-545 , hieght-575, "2. Движение объекта с помощью клавиатуры");
	moveto(widht-550, hieght-555);
	lineto(widht-220,hieght-555);
	outtextxy(widht-545 , hieght-552, "3. Выход из программы");
	moveto(widht-550,hieght-532);
	lineto(widht-220,hieght-532);
	moveto(widht-550,0); 
	lineto(widht-550,hieght-532); 
	moveto(widht-220,0);
	lineto(widht-220,hieght-532);
    // двигаемся по менюшки и выбираем подпрограммы 

	if (kbhit())
	{
	  ch=getch();

	  if(ch==72) i--;
	  if(ch==80) i++;
	  if(i<1) i=3;
	  if(i>3) i=1;
	}
	  if(i==1)
	  {
	  	
	  	setfillstyle(1,RED); 
	    floodfill(widht-547, hieght-597,WHITE); 
	    setfillstyle(1,BLACK); 
	    floodfill(widht-547, hieght-576,WHITE); 
	    setfillstyle(1,BLACK); 
	    floodfill(widht-547, hieght-553,WHITE); 

	  }
	  if(i==2)
	  {
	  	 
	  	setfillstyle(1,RED); 
	    floodfill(widht-547, hieght-576,WHITE); 
	    setfillstyle(1,BLACK); 
	    floodfill(widht-547, hieght-597,WHITE); 
	    setfillstyle(1,BLACK); 
	    floodfill(widht-547, hieght-553,WHITE); 
	  }
	  if(i==3)
	  {
	  	
	  	setfillstyle(1,RED); 
	    floodfill(widht-547, hieght-553,WHITE); 
	    setfillstyle(1,BLACK); 
	    floodfill(widht-547, hieght-576,WHITE); 
	    setfillstyle(1,BLACK); 
	    floodfill(widht-547, hieght-597,WHITE); 
	  }

	swapbuffers();

	// сами подпрограммы 
	if(i==1 && ch==13)//тут надо свободное движение 
		{   
			while(1) 
			{
				cleardevice(); 
				draw_hero(x,y);
				delay(20);
				y++;
			    x++;
			    
				if (kbhit())
				
				if(getch()==27) break;
			    
			
			   	
				swapbuffers();
			}
		  break;
		}
	if(i==2 && getch()==13)
		{
	  		while(1)
		  	{
				cleardevice();
				draw_hero(x,y);
				if ( kbhit() ) 
				{
				if(getch()==27)	break;
				switch(getch())
				{
					case 75: x--;break;
					case 77: x++;break;
					case 72: y--;break;
					case 80: y++;break;
				}
			    }
																																										   
				
			    
				swapbuffers();
			}
		
	    break;
		  
	    
		}
	if(i==3 && ch==13)
	  {
		break; 
	  }

	}
	while(ch != 27);	
	
	closegraph(); 
}
