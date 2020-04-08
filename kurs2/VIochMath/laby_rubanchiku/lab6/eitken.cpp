#include "SFML.hpp"

using namespace std;
using namespace sf;

double x_mas[4] = {1, 2, 3, 4};

double y_mas[4] = {1, 1.4142, 1.7321, 2};

double formula(double x)
{
	return sqrt(x);
}

double formula_et(double et_x, int n)
{
	double temp_ch, temp_zn, p_mas[4];
	
	for(int i = 0; i < n + 1; i++) p_mas[i] = y_mas[i];
	
	for (int i = 0; i < n; i++)
	{
		for(int j = i; j < n - i; j++)
		{
			temp_ch = p_mas[j] * (et_x - x_mas[j + 1]) - p_mas[j + 1] * (et_x - x_mas[j]);
			temp_zn = x_mas[j] - x_mas[j + 1];
			p_mas[j] = temp_ch / temp_zn;
		}
	}
//	cout << endl << p_mas[0] << endl << p_mas[1] << endl << p_mas[2] << endl << p_mas[3];
	return p_mas[0];
}
 
int main()
{	
	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(720, 720), "lagranhzz", Style::Default, settings);
	int n = 3;
	double shag = 1, x, kolvo = 720 / shag, et_x, et_y;

	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);
	VertexArray lines_et(LineStrip, kolvo);
	VertexArray etkin(LineStrip, 2);
	VertexArray x1_g(LineStrip, 2);
	VertexArray x2_g(LineStrip, 2);
	VertexArray x3_g(LineStrip, 2);
	VertexArray x4_g(LineStrip, 2);
	
	x1_g[0].position = Vector2f(360 + x_mas[0], 360);
	x1_g[1].position = Vector2f(360 + x_mas[0], 360 - y_mas[0]);
	x1_g[0].color = Color::Green;
	x1_g[1].color = Color::Green;
	
	x2_g[0].position = Vector2f(360 + x_mas[1], 360);
	x2_g[1].position = Vector2f(360 + x_mas[1], 360 - y_mas[1]);
	x2_g[0].color = Color::Green;
	x2_g[1].color = Color::Green;
	
	x3_g[0].position = Vector2f(360 + x_mas[2], 360);
	x3_g[1].position = Vector2f(360 + x_mas[2], 360 - y_mas[2]);
	x3_g[0].color = Color::Green;
	x3_g[1].color = Color::Green;
	
	x4_g[0].position = Vector2f(360 + x_mas[3], 360);
	x4_g[1].position = Vector2f(360 + x_mas[3], 360 - y_mas[3]);
	x4_g[0].color = Color::Green;
	x4_g[1].color = Color::Green;
	
	os_x[0].position = Vector2f(720, 360);
	os_x[1].position = Vector2f(0, 360);
	
	os_y[0].position = Vector2f(360, 720);
	os_y[1].position = Vector2f(360, 0); 
	
	cout << endl << "Vvedite x: ";
	cin >> et_x;
	et_y = formula_et(et_x, n);
	
	etkin[0].position = Vector2f(360 + et_x, 360);
	etkin[1].position = Vector2f(360 + et_x, 360 - et_y);
	etkin[0].color = Color::Red;
	etkin[1].color = Color::Red;
	
	cout << endl << "x = " << et_x << " y = " << et_y << endl; 
	
	
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
			lines_et[i].position = Vector2f(360 + x, 360 - formula_et(x, n));
			lines_et[i].color = Color::Red;
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
		window.draw(lines_et);
		window.draw(etkin);
		window.draw(x1_g);
		window.draw(x2_g);
		window.draw(x3_g);
		window.draw(x4_g);
		window.display();
	}
	
	return 0;
}
