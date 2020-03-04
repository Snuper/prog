/*#ifndef SORT_CLASS_H
#define SORT_CLASS_H
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
};

#endif
*/
