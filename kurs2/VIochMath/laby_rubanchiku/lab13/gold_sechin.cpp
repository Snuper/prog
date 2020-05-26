#include "SFML.hpp"

using namespace std;
using namespace sf;

const double eps = 0.0000001;
const double gold = (1 + sqrt(5)) / 2;

double formula(double x)
{
	return sin(x);
}

main()
{
	int i, n, vibor;	
	double shag = 0.125, a, b, save_a, save_b;
	
	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	cout << endl << "Vvedite [left] i [right]: ";
	cin >> a >> b;
	
	save_a = a;
	save_b = b;
	
	cout << endl << "Chto ishem? 1 - minimum\n2 - maximum" << endl;
	cin >> vibor;
	
	RenderWindow window(VideoMode(720, 720), "Yaiduna3", Style::Default, settings);
	double x = 0, kolvo = 720 / shag, temp = 0, rez, x1, x2;

	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray os_gold(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);
	
	
	os_x[0].position = Vector2f(720, 360);
	os_x[1].position = Vector2f(0, 360);
	
	os_y[0].position = Vector2f(360, 720);
	os_y[1].position = Vector2f(360, 0);
	
	for(int step = 1; fabs(b - a) > eps; step++)
	{
		cout << endl << "Shag = " << step << endl;
		x1 = b - (b - a) / gold;
		x2 = a + (b - a) / gold;
		cout << endl << "	x1 = " << x1 << " x2 = " << x2 << endl; 
		if(formula(x1) >= formula(x2) and vibor == 1) a = x1;
		else if(formula(x1) <= formula(x2) and vibor == 2) a = x1;
		else b = x2;
		cout << endl << "	a = " << a << " b = " << b << endl;
	}
	
	for(i = 0, x = -360 * shag; i < kolvo; i++, x += shag)
	{
		lines[i].position = Vector2f(360 + x, 360 - formula(x));
		if(x > save_a + shag and x < save_b + shag) lines[i].color = Color::Red;
	}
	
	os_gold[0].position = Vector2f(360 + (a + b) / 2, 360 - formula((a + b) / 2));
	os_gold[1].position = Vector2f(360 + (a + b) / 2, 360);
	os_gold[0].color = Color::Green;
	os_gold[1].color = Color::Green;
	
	cout << "tochka = " << (a + b) / 2 << endl << "otvet = " << formula((a + b) / 2);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	
		
		if (Keyboard::isKeyPressed(Keyboard::D)) view.move(0.001 + temp, 0);
		else if (Keyboard::isKeyPressed(Keyboard::S)) view.move(0, 0.001 + temp);
		else if (Keyboard::isKeyPressed(Keyboard::A)) view.move(-0.001 - temp, 0);
		else if (Keyboard::isKeyPressed(Keyboard::W)) view.move(0, -0.001 - temp);
		else if (Keyboard::isKeyPressed(Keyboard::E))
		{
			temp -= 0.0001;
			view.zoom(1.001f + temp);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			temp += 0.0001;
			view.zoom(0.999f - temp);
		}
		
		window.clear();
		window.setView(view);
		window.draw(os_gold);
		window.draw(os_x);
	 	window.draw(os_y);
		window.draw(lines);
		window.display();
	}
	
	return 0;
}
