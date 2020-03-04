#ifndef TANK_H
#define TANK_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;
using namespace sf;

class Tank
{
	public:
		float w, h, x, y, speed, w_scale, h_scale;
		int dir;
		bool life = true;
		bool shoot = false;
		String File;
		Image image;
		Texture texture;
		Sprite sprite;
		virtual void Move()=0;
};

#endif
