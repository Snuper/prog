/*#ifndef SORT_CLASS_H
#define SORT_CLASS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "interface_class.h"

using namespace std;
using namespace sf;

	void Hard::Create_elipse()
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
		
	void Hard::Create_segment()
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
	
		void Create_circle()
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
	
		void Hard::Create_point()
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
};

#endif
*/
