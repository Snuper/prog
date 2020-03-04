#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctime>
#include <windows.h>

const int widht = 800, hieght = 600; 
int draw_hero(int x, int y)
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
	FreeConsole();
	
	int i = 1,ch,x = 0,y = 0;
	int direction = 0;
	bool running = true;
	
	
	
	initwindow(widht, hieght,"ÐÃÇ",0,0,true);
	
	while( running )
	{
		x = 0, y = 0;
		
		
		cleardevice();

		setcolor(WHITE); 	 
		line(580,0,250,0);
		outtextxy(widht-545 , hieght-598, "1. Svobodnoe dvighenie ");	
		line(580,22,250,22);
		outtextxy(widht-545 , hieght-575, "2. Dvighenie s pomoshiu klaviatury");	
		line(580,45,250,45);
		outtextxy(widht-545 , hieght-552, "3. Exit iz progy");	
		line(580,68,250,68);	 
		line(250,68,250,0); 
		line(580,68,580,0);
		
		if( kbhit())
		{
			ch = getch();
			
			if(ch == 72) i--;
			if(ch == 80) i++;
			
			if(i < 1) i = 3;
			if(i > 3) i = 1;
		}
		
		if(i == 1)
	  	{
	  		setfillstyle(1,RED); 
	    	floodfill(widht-547, hieght-597,WHITE); 
	    	setfillstyle(1,BLACK); 
	    	floodfill(widht-547, hieght-576,WHITE); 
	    	setfillstyle(1,BLACK); 
	    	floodfill(widht-547, hieght-553,WHITE); 

	  	}
	  	if(i == 2)
	  	{
	  		setfillstyle(1,RED); 
	    	floodfill(widht-547, hieght-576,WHITE); 
	    	setfillstyle(1,BLACK); 
	    	floodfill(widht-547, hieght-597,WHITE); 
	    	setfillstyle(1,BLACK); 
	    	floodfill(widht-547, hieght-553,WHITE); 
	  	}
	  	if(i == 3)
	  	{
	  		setfillstyle(1,RED); 
	    	floodfill(widht-547, hieght-553,WHITE); 
	    	setfillstyle(1,BLACK); 
	    	floodfill(widht-547, hieght-576,WHITE); 
	    	setfillstyle(1,BLACK); 
	    	floodfill(widht-547, hieght-597,WHITE); 
	  	}
	  	swapbuffers();
	  	int k = 0;
	  	
	  	if( i == 1 && ch == 13)
	  	{
	  		while( k > -1)
	  		{
	  			cleardevice();
				   
				draw_hero(x-220,y-190);
				
				if ( kbhit() && getch() == 27 ) 
				{
					k = -3;
					ch = 27;
				}
				
			   	switch(direction)
			   	{
			   		case 0:
					{
						delay(10);
						x++;
						y++;
						if (x >= 480 and y >= 400)
						direction = 1;		
						break;					   	
					}	
					case 1:
					{
						delay(10);
						y--;
						if (x <= 560 and y <= 10)
						direction = 2;	
						break;							   	
					}	
					case 2:
					{
						delay(10);
						x--;
						y++;
						if (x <= 10 and y >= 480)
						direction = 3;
						break;								   	
					}	
					case 3:
					{
						delay(10);
						y--;
						if (x <= 10 and y <= 10)
						direction = 0;								   	
						break;
					}	
				   
				}
				swapbuffers();
	  		}
	  	}
	  	
	  	k = 0;
	  	
	  	if( i == 2 && ch == 13)
	  	{
	  		while( (k > -1) and (x<272) and (x>-220) and (y<272) and (y>-200))
	  		{
	  			cleardevice();
				draw_hero(x,y);
								
				if( kbhit())
				{
					switch(getch())
					{                              
						case 75: x--;break;
						case 77: x++;break;
						case 72: y--;break;
						case 80: y++;break;
						case 27: k = -3; ch = 27; break;
					}
				}
            
				swapbuffers();
                
			}
	  	}
	  	
	  	k = 0;
	  	
	  	if( i == 3 && ch == 13)
	  	{
	  		running = false;
	  	}
	}
	
	closegraph();
	
}
