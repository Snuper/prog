#include "SFML.hpp"

using namespace std;
using namespace sf;

double x_mas[4] = {1, 2, 3, 4};

double y_mas[4] = {1, 1.4142, 1.7321, 2}, eps = 10000;

double formula(double x)
{
	return sqrt(x);
}

double formula_et(double et_x, int n)
{
	double temp_ch, temp_zn, p_mas[4];
	
	for(int i = 0; i < n + 1; i++) p_mas[i] = y_mas[i];
	
	for (int i = 0, ub = 0; i < (n * n / 2) + 1; i++)
	{
		for(int j = i; j < n + ub; j++)
		{
			if(j >= n - 1) continue;
//			cout << endl << j + 1 << " | " << j - ub << endl;
//			cout << endl << p_mas[0] << endl << p_mas[1] << endl << p_mas[2] << endl << p_mas[3];
//			cout << endl << p_mas[j - ub] << " * (" << et_x << " - " << x_mas[j + 1] << ")" << " - " << p_mas[j + 1 - ub] << " * (" << et_x << " - " << x_mas[j - ub] << endl;
//			cout << x_mas[j - ub] << " - " << x_mas[j + 1] << endl;;
			
			temp_ch = p_mas[j - ub] * (et_x - x_mas[j + 1]) - p_mas[j + 1 - ub] * (et_x - x_mas[j - ub]);
			temp_zn = x_mas[j - ub] - x_mas[j + 1];
			p_mas[j - ub] = temp_ch / temp_zn;
			
//			cout << endl << "------------------------------------------" << endl;
		}
		ub++;
	}
//	cout << endl << p_mas[0] << endl << p_mas[1] << endl << p_mas[2] << endl << p_mas[3];
	return round(p_mas[0] * eps) / eps;
}

double epsilon(double &E_okr, double &E_us, double la_x, int n)
{
	double temp_ch = 1, temp_zn = 1, M;
	for(int i = 0; i < n + 1; i++)
	{
		temp_ch *= la_x - x_mas[i];
		if(temp_ch < 0) temp_ch *= -1;
		temp_zn *= i + 1;
	}
	M = 3.0/8.0 * pow(x_mas[n], -5.0/2.0);
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
	
	RenderWindow window(VideoMode(720, 720), "eitkin", Style::Default, settings);
	int n = 4, i;
	double x = 0, kolvo = 720 / shag, et_x, et_y, E_us = 1, E_okr = 1, temp = 0;

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
	
	epsilon(E_okr, E_us, et_x, n);
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
			lines_et[i].position = Vector2f(360 + x, 360 - formula_et(x, n));
			lines_et[i].color = Color::Red;
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
