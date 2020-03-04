#ifndef INTERFACE_POINT_H
#define INTERFACE_POINT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;
using namespace sf;

class Figure
{
	public:
		float x, y, w, h, dx, dy, color;
		int dir;
		String File;
		Texture texture;
		Sprite sprite;
		virtual void Move_where(float ping);
		virtual void Create_figure();
};
#endif
