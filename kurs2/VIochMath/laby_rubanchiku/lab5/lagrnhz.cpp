#include "SFML.hpp"

using namespace std;
using namespace sf;

double x_mas[3] = {1, 2, 4}, eps = 10000;

double y_mas[3] = {1, 1.4142, 2};

double formula(double x)
{
	return sqrt(x);
}

double formula_la(double la_x, int n)
{
	double p = 0, temp_ch, temp_zn;
	for (int i = 0; i < n; i++)
	{
		temp_ch = temp_zn = 1;
		for (int j = 0; j < n; j++)
		{
			if ( i == j ) continue;
			temp_ch *= la_x - x_mas[j];
			temp_zn *= x_mas[i] - x_mas[j];
//			cout << endl << i << " = i - j = " << j << " ch = " << temp_ch << " zn = " << temp_zn;
		}
		p += y_mas[i] * (temp_ch / temp_zn);
	}
	return round(p * eps) / eps;
}

double epsilon(double &E_okr, double &E_us, double la_x, int n)
{
	double temp_ch = 1, temp_zn = 1, M;
	for(int i = 0; i < n; i++)
	{
		temp_ch *= la_x - x_mas[i];
		if(temp_ch < 0) temp_ch *= -1;
		temp_zn *= i + 1;
	}
	M = 3.0/8.0 * pow(x_mas[n-1], -5.0/2.0);
	if(M < 0) M *= -1;

	E_okr = 1 / eps;
	E_us = M * (temp_ch / temp_zn);
}
 
int main()
{	
	double shag;
	cout << endl << "Vvedite razmer shaga: ";
	cin >> shag;
	
	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(720, 720), "lagranhzz", Style::Default, settings);
	int n, i;
	double x = 0, kolvo = 720 / shag, la_x, la_y, E_okr = 1, E_us = 1, temp = 0;

	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);
	VertexArray lines_la_4(LineStrip, kolvo);
//	VertexArray lines_la_3(LineStrip, kolvo);
//	VertexArray lines_la_2(LineStrip, kolvo);
//	VertexArray lines_la_1(LineStrip, kolvo);
	VertexArray lagranzh(LineStrip, 2);
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
	cin >> la_x;
	la_x = round(la_x * eps) / eps;
	cout << endl << "Vvedite kolvo tochek dlya interpolyacii: ";
	cin >> n;
	la_y = formula_la(la_x, n);
	
	lagranzh[0].position = Vector2f(360 + la_x, 360);
	lagranzh[1].position = Vector2f(360 + la_x, 360 - la_y);
	lagranzh[0].color = Color::Red;
	lagranzh[1].color = Color::Red;
	
	cout << endl << "x = " << la_x << " y = " << la_y << endl; 
	
	epsilon(E_okr, E_us, la_x, n);
	cout << "E_okr = " << E_okr << " E_us = " << E_us << " E_real = " << E_us + E_okr << endl;
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		for(i = 0, x = -360 * shag; i < kolvo; i++, x += shag)
		{
			lines[i].position = Vector2f(360 + x, 360 - formula(x));
			lines_la_4[i].position = Vector2f(360 + x, 360 - formula_la(x, n));
//			lines_la_3[i].position = Vector2f(360 + x, 360 - formula_la(x, 3));
//			lines_la_2[i].position = Vector2f(360 + x, 360 - formula_la(x, 2));
//			lines_la_1[i].position = Vector2f(360 + x, 360 - formula_la(x, 1));
			lines_la_4[i].color = Color::Red;
//			lines_la_3[i].color = Color::Blue;
//			lines_la_2[i].color = Color::Yellow;
//			lines_la_1[i].color = Color::Cyan;
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
	 	window.draw(os_x);
	 	window.draw(os_y);
		window.draw(lines);
		window.draw(lines_la_4);
//		window.draw(lines_la_3);
//		window.draw(lines_la_2);
//		window.draw(lines_la_1);
		window.draw(lagranzh);
		window.draw(x1_g);
		window.draw(x2_g);
		window.draw(x3_g);
		window.draw(x4_g);
		window.display();
	}
	
	return 0;
}
