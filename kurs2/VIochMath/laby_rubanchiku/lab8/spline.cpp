#include "SFML.hpp"

using namespace std;
using namespace sf;

double formula(double x)
{
	return sqrt(x);
}

int main()
{
//	ќбъ€вл€ем
	int i, n, temp_i, swap_1, swap_2;	
	double shag = 0.01;
	
	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(720, 720), "spline", Style::Default, settings);
	double x = 0, kolvo = 720 / shag, sp_x, sp_y, temp = 0;

	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);
	
	VertexArray sp_g(LineStrip, 2);
//	ќбъ€вл€ем
//	»ницилизируем массивы и заполн€ем массивы
	cout << endl << "Vvedite kolvo tochek interpolyacii: ";
	cin >> n;
	
	double y_mas[n], x_mas[n], h_mas[n - 1], eps = 10000, raznost[n][n];
	
	VertexArray x_g(LineStrip, n*3);
	for(temp_i = 0; temp_i < n; temp_i++, i += 3)
	{
		cout << endl << "x[" << temp_i << "] = "; 
		cin >> x_mas[temp_i];
		y_mas[temp_i] = formula(x_mas[temp_i]);
		cout << " y = " << y_mas[temp_i];
		
		x_g[i].position = Vector2f(360 + x_mas[temp_i], 360);
		x_g[i + 1].position = Vector2f(360 + x_mas[temp_i], 360 - y_mas[temp_i]);
		x_g[i].color = Color::Green;
		x_g[i + 1].color = Color::Green;
		x_g[i + 2].position = Vector2f(360 + x_mas[temp_i], 360);
		x_g[i + 2].color = Color::Green;
	}
	
	cout << endl << "Shagi interpolyacii ";

	for(i = 0; i < n - 1; i++)
	{
		h_mas[i] = x_mas[i + 1] - x_mas[i];
		if(h_mas[i] < 0) h_mas[i] *= -1;
		cout << endl << "h[" << i << "] = " << h_mas[i];
	}	
	
	os_x[0].position = Vector2f(720, 360);
	os_x[1].position = Vector2f(0, 360);
	
	os_y[0].position = Vector2f(360, 720);
	os_y[1].position = Vector2f(360, 0);
//	»ницилизируем массивы и заполн€ем массивы
	
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
		window.draw(x_g);
	 	window.draw(sp_g);
		window.draw(os_x);
	 	window.draw(os_y);
		window.draw(lines);
		window.display();
	}
	
	return 0;
}
