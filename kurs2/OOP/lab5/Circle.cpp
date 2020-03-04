#include "Circle.h"

void Circle::Create_figure()
{
	color = rand()%4+1;
	if (color == 1)
	{
		w = 0.15; h = 0.15;
		texture.loadFromFile("image/circle/red.png");
		sprite.setTexture(texture);
		x = rand()%1351+1;
		y = rand()%753+1;
		sprite.setScale(w,h);
		sprite.setPosition(x,y);
		dir = rand()%4+1;
	}
	else if (color == 2)
	{
		w = 0.15; h = 0.15;
		texture.loadFromFile("image/circle/green.png");
		sprite.setTexture(texture);
		x = rand()%1351+1;
		y = rand()%753+1;
		sprite.setScale(w,h);
		sprite.setPosition(x,y);
		dir = rand()%4+1;
	}
	else if (color == 3)
	{
		w = 0.15; h = 0.15;
		texture.loadFromFile("image/circle/blue.png");
		sprite.setTexture(texture);
		x = rand()%1351+1;
		y = rand()%753+1;
		sprite.setScale(w,h);
		sprite.setPosition(x,y);
		dir = rand()%4+1;
	}
	else
	{
		w = 0.15; h = 0.15;
		texture.loadFromFile("image/circle/pink.png");
		sprite.setTexture(texture);
		x = rand()%1351+1;
		y = rand()%753+1;
		sprite.setScale(w,h);
		sprite.setPosition(x,y);
		dir = rand()%4+1;
	}
}

void Circle::Move_where(float ping)
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
