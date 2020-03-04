#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "interface_class.h"

using namespace std;
using namespace sf;


int main()
{
	RenderWindow window(sf::VideoMode(1366, 768), "LAB3", Style::Fullscreen);
	Clock clock;
	srand(time(0));
	
	int point = 10, circle = 10;
	float time;
	
	window.setVerticalSyncEnabled(true);
	time = clock.getElapsedTime().asMilliseconds();
	clock.restart();
	
	Simple obj_square;
		obj_square.Create_square();
	Simple obj_triangle;
		obj_triangle.sprite.setOrigin(25.6, 25.6);
		obj_triangle.Create_triangle();
	Hards obj_segment;
		obj_segment.sprite.setOrigin(64, 3.2);
		obj_segment.Create_segment();
	Hards obj_elipse;
		obj_elipse.sprite.setOrigin(50, 50);
		obj_elipse.Create_elipse();
	Simple obj_romb;
		obj_romb.sprite.setOrigin(32, 32);
		obj_romb.Create_romb();
	
	Hards obj_circle[circle];
	for (int i=0; i<circle; i++)
		obj_circle[i].Create_circle();
	
	Hards obj_point[point];
	for (int i=0; i<point; i++)
		obj_point[i].Create_point();
	
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
        window.clear();
        
        window.draw(obj_square.sprite);
			obj_square.Move_where(time);
			
		window.draw(obj_segment.sprite);
			obj_segment.Move_where(time);
			
		window.draw(obj_romb.sprite);
			obj_romb.Move_where(time);
			
		window.draw(obj_triangle.sprite);
			obj_triangle.Move_where(time);
			
		window.draw(obj_elipse.sprite);
			obj_elipse.Move_where(time);
        
		for (int i=0; i<circle; i++)
        {
			window.draw(obj_circle[i].sprite);
			obj_circle[i].Move_where(time);
		}
		for (int i = 0; i < point; i++)
		{
			window.draw(obj_point[i].sprite);
			obj_point[i].Move_where(time);
		}
		window.display();
    }

    return 0;
}
