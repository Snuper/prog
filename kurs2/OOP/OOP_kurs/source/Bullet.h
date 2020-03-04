#ifndef BULLET_H
#define BULLET_H
#include "Tank.h"

class Bullet : public Tank
{
	public:
		Bullet(String F, float W, float H, float W_SCALE, float H_SCALE)
		{
			w_scale = W_SCALE;
			h_scale = H_SCALE;
			w = W;
			h = H;
			File = F;
			image.loadFromFile("image/character/" + File);
			texture.loadFromImage(image);
			sprite.setTextureRect(IntRect(12,58,128,78));
			sprite.setTexture(texture);
			sprite.setScale(w_scale, h_scale);
		}
		void Move();
};

#endif
