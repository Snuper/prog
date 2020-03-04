/*#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "interface_class.h"

using namespace std;
using namespace sf;

class Funcktion
{
	public:Simple;
	
	void Funcktion::Move_where(float ping)
		{
			switch (dir)
			{
			case 1: sprite.move(-10,0);
					x-=10;
					if (x < 0) dir = 3;
					break; //Left
			case 2: sprite.move(0,10);
					y+=10;
					if (y > 743) dir = 4;
					break; //Down
			case 3: sprite.move(10,0);
					x+=10;
					if (x > 1351) dir = 1;
					break; //Right
			case 4: sprite.move(0,-10);
					y-=10;
					if (y < 0) dir = 2;
					break; //Up
			case 5: sprite.rotate(15);
					break; //Rotate
			}
		}
};

#endif
*/
