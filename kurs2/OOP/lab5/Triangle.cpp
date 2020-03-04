#include "Triangle.h"

void Triangle::Create_figure()
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

void Triangle::Move_where(float ping)
{
	if (dir == 1)
	{
		sprite.move(-10,0);
		x-=10;
		if (x < 0) dir = 3;
	} //Left
	else if (dir == 2)
	{
			sprite.move(0,10);
			y+=10;
			if (y > 743) dir = 4;
	} //Down
	else if (dir == 3)
	{
			sprite.move(10,0);
			x+=10;
			if (x > 1351) dir = 1;
	} //Right
	else if (dir == 4)
	{
			sprite.move(0,-10);
			y-=10;
			if (y < 0) dir = 2;
	}  //Up
	else
	{
		sprite.rotate(15);
	}  //Rotate
}
