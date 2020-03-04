#include "Bullet.h"

void Bullet::Move()
{
	if (dir == 0)
	{
		sprite.move(-10,0);
		sprite.setTextureRect(IntRect(138,255,128,78));
	}

	if (dir == 1)
	{
		sprite.move(10,0);
		sprite.setTextureRect(IntRect(12,58,128,78));
	}

	if (dir == 2)
	{
		sprite.move(0,-10);
		sprite.setTextureRect(IntRect(21,194,78,128));
	}

	if (dir == 3)
	{
		sprite.move(0,10);
		sprite.setTextureRect(IntRect(188,32,78,128));
	}
}
