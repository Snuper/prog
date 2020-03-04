#include "Player.h"

Player::Player(String F, float X, float Y, float W, float H, float W_SCALE, float H_SCALE)
{
	w_scale = W_SCALE;
	h_scale = H_SCALE;
	w = W;
	h = H;
	x = X;
	y = Y;
	File = F;
	image.loadFromFile("image/character/" + File);
	texture.loadFromImage(image);
	sprite.setPosition(x, y);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(21, 194, w, h));
	sprite.setScale(w_scale, h_scale);
}

void Player::Move()
{
	if (dir == 0)
	{
		sprite.move(-5,0);
		sprite.setTextureRect(IntRect(138,255,128,78));
	}

	if (dir == 1)
	{
		sprite.move(5,0);
		sprite.setTextureRect(IntRect(12,58,128,78));
	}

	if ( dir == 2)
	{
		sprite.move(0,-5);
		sprite.setTextureRect(IntRect(21,194,78,128));
	}

	if (dir == 3)
	{
		sprite.move(0,5);
		sprite.setTextureRect(IntRect(188,32,78,128));
	}
}
