#ifndef PLAYER_H
#define PLAYER_H
#include "Tank.h"

class Player : public Tank
{
	public:
		float w, h, x, y, speed, w_scale, h_scale;
		Player(String F, float X, float Y, float W, float H, float W_SCALE, float H_SCALE);
		Player(String F) : w(0.5), h(0.5)
		{
			File = F;
			image.loadFromFile("image/character/" + File);
			texture.loadFromImage(image);
			sprite.setTexture(texture);
			sprite.setPosition(600, 300);
			sprite.setTexture(texture);
			sprite.setTextureRect(IntRect(21, 194, 78, 128));
			sprite.setScale(w, h);
		}
		void Move();
	protected:
};

#endif
