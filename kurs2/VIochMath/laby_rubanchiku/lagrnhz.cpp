#include "SFML.hpp"

using namespace std;
using namespace sf;

double x_mas[4] = {1, 2, 3, 4};

double y_mas[4] = {1, 1.4142, 1.7321, 2}, eps = 10000;;

double formula(double x)
{
	return sin(x);
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
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	View view;
	RenderWindow window(VideoMode(720, 720), "lagranhzz", Style::Default, settings);
	
	
	double x_shag;
	
	cout << "Vvedite razmer shaga: ";
	cin >> x_shag;
	
	
	double shag = 1, x = 0, kolvo = 720 * x_shag, la_x, la_y, E_okr = 1, E_us = 1, kolvo_osi = kolvo / 2;
	view.reset(FloatRect(kolvo_osi - 60, kolvo_osi - 60, 120, 120));
	int n;

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
	
	x1_g[0].position = Vector2f(kolvo_osi + x_mas[0] * x_shag, kolvo_osi);
	x1_g[1].position = Vector2f(kolvo_osi + x_mas[0] * x_shag, kolvo_osi - y_mas[0] * x_shag);
	x1_g[0].color = Color::Green;
	x1_g[1].color = Color::Green;
	
	x2_g[0].position = Vector2f(kolvo_osi + x_mas[1] * x_shag, kolvo_osi);
	x2_g[1].position = Vector2f(kolvo_osi + x_mas[1] * x_shag, kolvo_osi - y_mas[1] * x_shag);
	x2_g[0].color = Color::Green;
	x2_g[1].color = Color::Green;
	
	x3_g[0].position = Vector2f(kolvo_osi + x_mas[2] * x_shag, kolvo_osi);
	x3_g[1].position = Vector2f(kolvo_osi + x_mas[2] * x_shag, kolvo_osi - y_mas[2] * x_shag);
	x3_g[0].color = Color::Green;
	x3_g[1].color = Color::Green;
	
	x4_g[0].position = Vector2f(kolvo_osi + x_mas[3] * x_shag, kolvo_osi);
	x4_g[1].position = Vector2f(kolvo_osi + x_mas[3] * x_shag, kolvo_osi - y_mas[3] * x_shag);
	x4_g[0].color = Color::Green;
	x4_g[1].color = Color::Green;
	
	os_x[0].position = Vector2f(kolvo, kolvo_osi);
	os_x[1].position = Vector2f(0, kolvo_osi);
	
	os_y[0].position = Vector2f(kolvo_osi, kolvo);
	os_y[1].position = Vector2f(kolvo_osi, 0);
	
	cout << endl << "Vvedite x: ";
	cin >> la_x;
	la_x = round(la_x * eps) / eps;
	cout << endl << "Vvedite kolvo tochek dlya interpolyacii: ";
	cin >> n;
	la_y = formula_la(la_x, n);
	
	lagranzh[0].position = Vector2f(kolvo_osi + la_x  * x_shag, kolvo_osi);
	lagranzh[1].position = Vector2f(kolvo_osi + la_x  * x_shag, kolvo_osi - la_y  * x_shag);
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
		
		for(int i = 0, x = -1 * kolvo_osi; i < kolvo; i++, x += shag)
		{
			lines[i].position = Vector2f(kolvo_osi + x * x_shag, kolvo_osi - formula(x * x_shag));
			lines_la_4[i].position = Vector2f(kolvo_osi + x * x_shag, kolvo_osi - formula_la(x * x_shag, n));
//			lines_la_3[i].position = Vector2f(kolvo_osi + x, kolvo_osi - formula_la(x, 3));
//			lines_la_2[i].position = Vector2f(kolvo_osi + x, kolvo_osi - formula_la(x, 2));
//			lines_la_1[i].position = Vector2f(kolvo_osi + x, kolvo_osi - formula_la(x, 1));
			lines_la_4[i].color = Color::Red;
//			lines_la_3[i].color = Color::Blue;
//			lines_la_2[i].color = Color::Yellow;
//			lines_la_1[i].color = Color::Cyan;
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
