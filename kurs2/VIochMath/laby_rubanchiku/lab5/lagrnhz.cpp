#include "SFML.hpp"

using namespace std;
using namespace sf;

double formula(double x)
{
	return sqrt(x);
}

int main()
{	
	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(720, 720), "lagranhzz", Style::Default, settings);
	double shag = 1, x = 0, kolvo = 720 / shag;
	
	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);

	os_x[0].position = Vector2f(720, 360);
	os_x[1].position = Vector2f(0, 360);
	
	os_y[0].position = Vector2f(360, 720);
	os_y[1].position = Vector2f(360, 0);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		for(int i = 0, x = -360; i < kolvo; i++, x += shag)
		{
			lines[i].position = Vector2f(360 + x, 360 - formula(x));
		}
		
		if (Keyboard::isKeyPressed(Keyboard::D)) view.move(0.01, 0);
		else if (Keyboard::isKeyPressed(Keyboard::S)) view.move(0, 0.01);
		else if (Keyboard::isKeyPressed(Keyboard::A)) view.move(-0.01, 0);
		else if (Keyboard::isKeyPressed(Keyboard::W)) view.move(0, -0.01);
		else if (Keyboard::isKeyPressed(Keyboard::E)) view.zoom(1.001f);
		else if (Keyboard::isKeyPressed(Keyboard::Q)) view.zoom(0.999f);
		 		
		window.clear();
		window.setView(view);
	 	window.draw(os_x);
	 	window.draw(os_y);
		window.draw(lines);
		window.display();
	}
	
	return 0;
}
