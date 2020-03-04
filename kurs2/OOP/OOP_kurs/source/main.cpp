#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Tank.h"
#include "Player.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

float x,y;
int T = 0, T_enemy = 0;
int bullet_dir, bullet_enemy_dir, last , last_enemy, i = 0, e = 0, q = 5;

int main()
{
	RenderWindow window(sf::VideoMode(1366, 768), "TANCHIKI_simple", Style::Fullscreen);
	Clock clock;
	srand(time(0));
	
	float time;
	bool T_on = false, T_on_enemy = false;
	Bullet *BULLETS[9];
	
	Bullet obj_bullet_0("bullet.png", 78, 128, 0.15, 0.15);
		BULLETS[0] = &obj_bullet_0;
	Bullet obj_bullet_1("bullet.png", 78, 128, 0.15, 0.15);
		BULLETS[1] = &obj_bullet_1;
	Bullet obj_bullet_2("bullet.png", 78, 128, 0.15, 0.15);
		BULLETS[2] = &obj_bullet_2;
	Bullet obj_bullet_3("bullet.png", 78, 128, 0.15, 0.15);
		BULLETS[3] = &obj_bullet_3;
	Bullet obj_bullet_4("bullet.png", 78, 128, 0.15, 0.15);
		BULLETS[4] = &obj_bullet_4;
	
	Bullet obj_bullet_enemy_0("bullet_enemy.png", 78, 128, 0.15, 0.15);
		BULLETS[5] = &obj_bullet_enemy_0;
	Bullet obj_bullet_enemy_1("bullet_enemy.png", 78, 128, 0.15, 0.15);
		BULLETS[6] = &obj_bullet_enemy_1;
	Bullet obj_bullet_enemy_2("bullet_enemy.png", 78, 128, 0.15, 0.15);
		BULLETS[7] = &obj_bullet_enemy_2;
	Bullet obj_bullet_enemy_3("bullet_enemy.png", 78, 128, 0.15, 0.15);
		BULLETS[8] = &obj_bullet_enemy_3;
	Bullet obj_bullet_enemy_4("bullet_enemy.png", 78, 128, 0.15, 0.15);
		BULLETS[9] = &obj_bullet_enemy_4;
	Player obj_enemy("character.png", 300, 200, 78, 128, 0.5, 0.5);
	Player obj_player("character_enemy.png");
	
	Image map_image;
	map_image.loadFromFile("image/map/pesok.jpg");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	
	window.setVerticalSyncEnabled(true);
	time = clock.getElapsedTime().asMilliseconds();
	clock.restart();
	
    while (window.isOpen())
    {
		time = time / 800;
		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
    		if (event.key.code == sf::Keyboard::Escape)
        		window.close();
    	}
    	
//////////////////////////////////////////Enemy - upravlenie	
        if (Keyboard::isKeyPressed(Keyboard::Left) and obj_enemy.life == true) 
		{
			obj_enemy.dir = 0;
			obj_enemy.Move();
			bullet_enemy_dir = 0;	
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) and obj_enemy.life == true)
		{
			obj_enemy.dir = 1;
			obj_enemy.Move();
			bullet_enemy_dir = 1;	
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up) and obj_enemy.life == true)
		{
			obj_enemy.dir = 2;
			obj_enemy.Move();
			bullet_enemy_dir = 2;	
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) and obj_enemy.life == true)
		{
			obj_enemy.dir = 3;
			obj_enemy.Move();
			bullet_enemy_dir = 3;	
		}
//////////////////////////////////////////Enemy - upravlenie	
//////////////////////////////////////////Player - upravlenie		
		if (Keyboard::isKeyPressed(Keyboard::A) and obj_player.life == true) 
		{
			obj_player.dir = 0;
			obj_player.Move();
			bullet_dir = 0;	
		}
		else if (Keyboard::isKeyPressed(Keyboard::D) and obj_player.life == true)
		{
			obj_player.dir = 1;
			obj_player.Move();
			bullet_dir = 1;	
		}
		else if (Keyboard::isKeyPressed(Keyboard::W) and obj_player.life == true)
		{
			obj_player.dir = 2;
			obj_player.Move();
			bullet_dir = 2;	
		}
		else if (Keyboard::isKeyPressed(Keyboard::S) and obj_player.life == true)
		{
			obj_player.dir = 3;
			obj_player.Move();
			bullet_dir = 3;	
		}
//////////////////////////////////////////Player - upravlenie
//////////////////////////////////////////BULLET
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			BULLETS[e]->dir = bullet_dir;
			if (last == 0 and T == 0 and BULLETS[e]->shoot == false and obj_player.life == true)
			{
				x = obj_player.sprite.getPosition().x + 10;
				y = obj_player.sprite.getPosition().y + 14;
				BULLETS[e]->sprite.setPosition(x,y);
				BULLETS[e]->shoot == true;
				e++;
				T = 0;
				T_on = true;
			}
			if (last == 1 and T == 0 and BULLETS[e]->shoot == false and obj_player.life == true)
			{
				x = obj_player.sprite.getPosition().x + 30;
				y = obj_player.sprite.getPosition().y + 14;
				BULLETS[e]->sprite.setPosition(x,y);
				BULLETS[e]->shoot == true;
				e++;
				T = 0;
				T_on = true;
	    	}
	    	if (last == 2 and T == 0 and BULLETS[e]->shoot == false and obj_player.life == true)
	    	{
	    		x = obj_player.sprite.getPosition().x + 14;
				y = obj_player.sprite.getPosition().y + 10;
				BULLETS[e]->sprite.setPosition(x,y);
				BULLETS[e]->shoot == true;
				e++;
				T = 0;
				T_on = true;
			}
			if (last == 3 and T == 0 and BULLETS[e]->shoot == false and obj_player.life == true)
	    	{
	    		x = obj_player.sprite.getPosition().x + 14;
				y = obj_player.sprite.getPosition().y + 30;
				BULLETS[e]->sprite.setPosition(x,y);
				BULLETS[e]->shoot == true;
				e++;
				T = 0;
				T_on = true;
			}
			if (e > 4) e = 0;
		}
//////////////////////////////////////////BULLET
//////////////////////////////////////////BULLET_enemy
		if (Keyboard::isKeyPressed(Keyboard::Numpad0))
		{
			BULLETS[q]->dir = bullet_enemy_dir;
			if (last_enemy == 0 and T_enemy == 0 and BULLETS[e]->shoot == false and obj_enemy.life == true)
			{
				x = obj_enemy.sprite.getPosition().x + 10;
				y = obj_enemy.sprite.getPosition().y + 14;
				BULLETS[q]->sprite.setPosition(x,y);
				BULLETS[q]->shoot == true;
				T_enemy = 0;
				T_on_enemy = true;
				q++;
			}
			if (last_enemy == 1 and T_enemy == 0 and BULLETS[e]->shoot == false and obj_enemy.life == true)
			{
				x = obj_enemy.sprite.getPosition().x + 30;
				y = obj_enemy.sprite.getPosition().y + 14;
				BULLETS[q]->sprite.setPosition(x,y);
				BULLETS[q]->shoot == true;
				T_enemy = 0;
				T_on_enemy = true;
				q++;
	    	}
	    	if (last_enemy == 2 and T_enemy == 0 and BULLETS[e]->shoot == false and obj_enemy.life == true)
	    	{
	    		x = obj_enemy.sprite.getPosition().x + 14;
				y = obj_enemy.sprite.getPosition().y + 10;
				BULLETS[q]->sprite.setPosition(x,y);
				BULLETS[q]->shoot == true;
				T_enemy = 0;
				T_on_enemy = true;
				q++;
			}
			if (last_enemy == 3 and T_enemy == 0 and BULLETS[e]->shoot == false and obj_enemy.life == true)
	    	{
	    		x = obj_enemy.sprite.getPosition().x + 14;
				y = obj_enemy.sprite.getPosition().y + 30;
				BULLETS[q]->sprite.setPosition(x,y);
				BULLETS[q]->shoot == true;
				T_enemy = 0;
				T_on_enemy = true;
				q++;
			}
			if (q > 9) q = 5;
		}
//////////////////////////////////////////BULLET_enemy
	
	for (int w = 0; w < 9; w++) BULLETS[w]->Move();
	
	if (T_on_enemy == true)
	{
		T_enemy++;
		if (T_enemy > 30)
		{
			T_enemy = 0;
			T_on_enemy = false;
		}
	}
	
	if (T_on == true)
	{
		T++;
		if (T > 30)
		{
			T = 0;
			T_on = false;
		}
	}
	
	for (int en = 0; en < 4; en++) if (BULLETS[en]->sprite.getGlobalBounds().intersects(obj_enemy.sprite.getGlobalBounds())) obj_enemy.life = false;
	for (int en = 5; en < 9; en++) if (BULLETS[en]->sprite.getGlobalBounds().intersects(obj_player.sprite.getGlobalBounds())) obj_player.life = false;
	
	if (obj_player.life == false) obj_player.sprite.setColor(Color::Red);
	if (obj_enemy.life == false) obj_enemy.sprite.setColor(Color::Red);
	
	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		obj_player.life = true;
		obj_player.sprite.setColor(Color::White);
		obj_enemy.sprite.setColor(Color::White);
		obj_enemy.life = true;
	}
	
	window.clear();
	window.draw(s_map);
    window.draw(obj_player.sprite);
    window.draw(obj_enemy.sprite);
	for (int o = 0; o < 9; o++) window.draw(BULLETS[o]->sprite);
	window.display();
	}
	return 0;
}
