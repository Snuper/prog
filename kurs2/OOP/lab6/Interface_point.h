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
//		Figure::Figure(int dir_x, float w_x, float h_x)
//		{
//			dir = dir_x;
//			w = w_x;
//			h = h_x;
//		}
		float x, y, w, h, dx, dy, color;
		int dir;
		String File;
		Texture texture;
		Sprite sprite;
		virtual void Move_where(float ping);
		virtual void Create_figure();
};
#endif
