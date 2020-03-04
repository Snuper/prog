#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Interface_class.h"

using namespace std;
using namespace sf;

void tPoint::Create_point()
	{	
		float x, y, w, h, dx, dy, speed = 1;
		int dir = 0;
		String File;
		Texture texture;
		Sprite sprite;
		int i = 0, color;
		color = rand()%4+1;
			switch (color)
			{
				case 1:
				{
					w = 0.15; h = 0.15;
					texture.loadFromFile("red.png");
					sprite.setTexture(texture);
					x = y = rand()%585+1;
					sprite.setScale(w,h);
					sprite.setPosition(x,y);
					
					dir = rand()%4+1;
					break;
				}
				case 2: 
				{
					w = 0.15; h = 0.15;
					texture.loadFromFile("green.png");
					sprite.setTexture(texture);
					x = y = rand()%585+1;
					sprite.setScale(w,h);
					sprite.setPosition(x,y);
					
					dir = rand()%4+1;
					break;
				}
				case 3:
				{
					w = 0.15; h = 0.15;
					texture.loadFromFile("blue.png");
					sprite.setTexture(texture);
					x = y = rand()%585+1;
					sprite.setScale(w,h);
					sprite.setPosition(x,y);
					
					dir = rand()%4+1;
					break;
				}
				case 4:
				{
					w = 0.15; h = 0.15;
					texture.loadFromFile("pink.png");
					sprite.setTexture(texture);
					x = y = rand()%585+1;
					sprite.setScale(w,h);
					sprite.setPosition(x,y);
					
					dir = rand()%4+1;
					break;
				}
			}
	}

void tPoint::Move_where(float ping)
	{
		float x, y, w, h, dx, dy, speed = 1;
		int dir = 0;
		String File;
		Texture texture;
		Sprite sprite;
		switch (dir)
		{
		case 1: sprite.move(-10,0);
				x-=10;
				if (x < 0) dir = 3;
				break; //Left
		case 2: sprite.move(0,10);
				y+=10;
				if (y > 575) dir = 4;
				break; //Down
		case 3: sprite.move(10,0);
				x+=10;
				if (x > 585) dir = 1;
				break; //Right
		case 4: sprite.move(0,-10);
				y-=10;
				if (y < 0) dir = 2;
				break; //Up
		}
	}

