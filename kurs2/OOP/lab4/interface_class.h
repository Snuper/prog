using namespace std;
using namespace sf;

class Simple 
{
public:
	
	float x, y, w, h, dx, dy, speed = 1;
	int dir = 0;
	String File;
	Texture texture;
	Sprite sprite;
};

class Hards : public Simple{
	public:	
	void Create_romb();
	void Create_triangle();
	void Create_square();
	void Move_where(float ping);
	void Create_elipse();
	void Create_segment();
	void Create_point();
	void Create_circle();
};
