#include "Interface_class.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(600, 600), "LAB3");
	Clock clock;
	srand(time(0));
	int n = 100;
	float time;
	window.setVerticalSyncEnabled(true);
	time = clock.getElapsedTime().asMilliseconds();
	clock.restart();
	
	tPoint obj[n];
	for (int i=0; i<100; i++)
		obj[i].Create_point();
	
    while (window.isOpen())
    {
		time = time / 800;
		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 100; i++)
		{
			window.draw(obj[i].sprite);
			obj[i].Move_where(time);
		}
		window.display();
    }

    return 0;
}
