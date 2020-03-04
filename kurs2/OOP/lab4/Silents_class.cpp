#ifndef _METERNZIF_H
#define _METERNZIF_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "interface_class.h"

using namespace std;
using namespace sf;

	void Simple::Create_romb()
		{		
				w = 0.5; h = 0.5;
			texture.loadFromFile("image/other/romb.png");
			sprite.setTexture(texture);
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);
			
			dir = 5;
		}
	
	void Hards::Create_romb()
		{		
				w = 0.5; h = 0.5;
			texture.loadFromFile("image/other/romb.png");
			sprite.setTexture(texture);
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);
			
			dir = 5;
		}
		
	void Simple::Create_triangle()
		{	
				w = 0.4; h = 0.4;
			texture.loadFromFile("image/other/triangle.png");
			sprite.setTexture(texture);
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);
			
			dir = 5;
		}
	
	void Hards::Create_triangle()
		{	
				w = 0.4; h = 0.4;
			texture.loadFromFile("image/other/triangle.png");
			sprite.setTexture(texture);
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);
			
			dir = 5;
		}
	
	void Simple::Create_square()
		{	
			w = 0.6; h = 0.3;
			texture.loadFromFile("image/other/square.png");
			sprite.setTexture(texture);	
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);	
			dir = rand()%4+1;
		}
	
	void Hards::Create_square()
		{	
			w = 0.6; h = 0.3;
			texture.loadFromFile("image/other/square.png");
			sprite.setTexture(texture);	
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);	
			dir = rand()%4+1;
		}
		
	void Hards::Create_elipse()
		{		
				w = 0.3; h = 0.15;
			texture.loadFromFile("image/point/pink.png");
			sprite.setTexture(texture);
			x = rand()%1300+1;
			y = rand()%700+1;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);
			
			dir = 5;
		}
		
	void Hards::Create_segment()
		{	
				w = 1; h = 0.05;
			texture.loadFromFile("image/other/square.png");
			sprite.setTexture(texture);
			x = rand()%1200+200;
			y = rand()%500+100;
			sprite.setScale(w,h);
			sprite.setPosition(x,y);
			
			dir = 5;
		}
	
	void Hards::Create_circle()
	{	
		int i = 0, color;
		color = rand()%4+1;
		switch (color)
		{
			case 1:
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/circle/red.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
				dir = rand()%4+1;
				break;
			}
			case 2: 
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/circle/green.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
				dir = rand()%4+1;
				break;
			}
			case 3:
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/circle/blue.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
				dir = rand()%4+1;
				break;
			}
			case 4:
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/circle/pink.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
				dir = rand()%4+1;
				break;
				}
			}
		}
	
	void Hards::Create_point()
	{	
		int i = 0, color;
		color = rand()%4+1;
		switch (color)
		{
			case 1:
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/point/red.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
				dir = rand()%4+1;
				break;
			}
			case 2: 
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/point/green.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
				dir = rand()%4+1;
				break;
			}
			case 3:
			{
				w = 0.15; h = 0.15;
				texture.loadFromFile("image/point/blue.png");
				sprite.setTexture(texture);
				x = rand()%1351+1;
				y = rand()%753+1;
				sprite.setScale(w,h);
				sprite.setPosition(x,y);
					
				dir = rand()%4+1;
				break;
			}
			case 4:
							{
					w = 0.15; h = 0.15;
					texture.loadFromFile("image/point/pink.png");
					sprite.setTexture(texture);
					x = rand()%1351+1;
					y = rand()%753+1;
					sprite.setScale(w,h);
					sprite.setPosition(x,y);
					
					dir = rand()%4+1;
					break;
				}
			}
		}
		
	void Simple::Move_where(float ping)
		{
			switch (dir)
			{
			case 1: sprite.move(-10,0);
					x-=10;
					if (x < 0) dir = 3;
					break; //Left
			case 2: sprite.move(0,10);
					y+=10;
					if (y > 743) dir = 4;
					break; //Down
			case 3: sprite.move(10,0);
					x+=10;
					if (x > 1351) dir = 1;
					break; //Right
			case 4: sprite.move(0,-10);
					y-=10;
					if (y < 0) dir = 2;
					break; //Up
			case 5: sprite.rotate(15);
					break; //Rotate
			}
		}	

	void Hards::Move_where(float ping)
		{
			switch (dir)
			{
			case 1: sprite.move(-10,0);
					x-=10;
					if (x < 0) dir = 3;
					break; //Left
			case 2: sprite.move(0,10);
					y+=10;
					if (y > 743) dir = 4;
					break; //Down
			case 3: sprite.move(10,0);
					x+=10;
					if (x > 1351) dir = 1;
					break; //Right
			case 4: sprite.move(0,-10);
					y-=10;
					if (y < 0) dir = 2;
					break; //Up
			case 5: sprite.rotate(15);
					break; //Rotate
			}
		}
#endif
