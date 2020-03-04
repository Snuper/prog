#indef _METERNZIF_H
#define _METERNZIF_H
#include "Silent_class.cpp"

using namespace std;
using namespace sf;

class tPoint 
{
public:
	
	float x, y, w, h, dx, dy, speed = 1;
	int dir = 0;
	String File;
	Texture texture;
	Sprite sprite;
	
	void Move_where(float ping);
	void Create_point();

};
#endif
