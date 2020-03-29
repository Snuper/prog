#include "SFML.hpp"

using namespace std;
using namespace sf;

double formula(double x)
{
	return x * x;
}

int main()
{	
	RenderWindow window(VideoMode(720, 720), "lagranhzz");
	double shag = 1, x = 0;
	
	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
//	VertexArray lines(LineStrip, 720);

	os_x[0].position = Vector2f(360, 360);
	os_x[1].position = Vector2f(-360, 360);
	
	os_y[0].position = Vector2f(360, 360);
	os_y[1].position = Vector2f(360, -360);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
//		for(int i = 0, x = -360; i < 720; i++, x += shag)
//		{
//			lines[i].position = Vector2f(360 + x, 360 - formula(x));
//		}
 		
		window.clear();
	 	window.draw(os_x);
	 	window.draw(os_y);
//		window.draw(lines);
		window.display();
	}
	
	return 0;
}
