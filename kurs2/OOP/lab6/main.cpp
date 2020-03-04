#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Interface_point.h"
#include "Point.h"
#include "Triangle.h"
#include "Romb.h"
#include "Square.h"
#include "Elipse.h"
#include "Segment.h"
#include "Circle.h"

using namespace std;
using namespace sf;

const int point = 10, circle = 10, M = 6;

int main()
{
	RenderWindow window(sf::VideoMode(1366, 768), "LAB6", Style::Fullscreen);
	Clock clock;
	srand(time(0));
	
	
	float time;
	
	window.setVerticalSyncEnabled(true);
	time = clock.getElapsedTime().asMilliseconds();
	clock.restart();
	
	Square obj_square(0.6, 0.3);
	Square obj_square2;
	Triangle obj_triangle;
	Segment obj_segment;
	Elipse obj_elipse;
	Romb obj_romb;
	
	Figure *ALL[M];
	
//	ALL = new Figure [];

//	obj_square
	ALL[0] = &obj_square;
	
	ALL[0]->Create_figure();
	
	ALL[5] = &obj_square2;
	ALL[5]->Create_figure();
	
	
//	obj_triangle;
	ALL[1] = &obj_triangle;
	
	ALL[1]->sprite.setOrigin(25.6, 25.6);
	ALL[1]->Create_figure();
	
//	obj_segment;
	ALL[2] = &obj_segment;
	
	ALL[2]->sprite.setOrigin(64, 3.2);
	ALL[2]->Create_figure();
	
//	obj_elipse;
	ALL[3] = &obj_elipse;

	ALL[3]->sprite.setOrigin(50, 50);
	ALL[3]->Create_figure();
	

//	obj_romb;
	ALL[4] = &obj_romb;
	
	ALL[4]->sprite.setOrigin(32, 32);
	ALL[4]->Create_figure();

	Circle obj_circle[circle];
	for (int i=0; i<circle; i++) obj_circle[i].Create_figure();
	
	Point obj_point[point];
	for (int i=0; i<point; i++) obj_point[i].Create_figure();
	
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
        
		window.draw(ALL[0]->sprite);
			ALL[0]->Move_where(time);
		
		window.draw(ALL[2]->sprite);
			ALL[2]->Move_where(time);
		
		window.draw(ALL[4]->sprite);
			ALL[4]->Move_where(time);
		
		window.draw(ALL[1]->sprite);
			ALL[1]->Move_where(time);
		
		window.draw(ALL[3]->sprite);
			ALL[3]->Move_where(time);
			
		window.draw(obj_square2.sprite);
			obj_square2.Move_where(time);
		
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
