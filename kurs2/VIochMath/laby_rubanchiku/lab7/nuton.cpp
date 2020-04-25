#include "SFML.hpp"

using namespace std;
using namespace sf;

double formula(double x)
{
	return sqrt(x);
}

double formula_nu_1(double nu_x, double h, int n, double **raznost, double *x_mas, double eps)
{
	int i;
	double temp_ch, temp_zn, q, p = raznost[0][0], temp_q;
	
	q = (nu_x - x_mas[0]) / h;
	
	p += q * raznost[0][1];
	for(i = 2, temp_q = 1; i < n; i++)
	{
		for(int proiz = 1; proiz < i; proiz++) temp_q *= q - proiz;
		temp_ch = raznost[0][i] * (q * temp_q);
		temp_zn = 1;
		for(int proiz = 1; proiz < i + 1; proiz++) temp_zn *= proiz;
		p += temp_ch / temp_zn;
	}

	return round(p * eps) / eps;
}
	
double formula_nu_2(double nu_x, double h, int n, double **raznost, double *x_mas, double eps)
{
	int i;
	double temp_ch, temp_zn, q, p = raznost[n - 1][0], temp_q;

	q = (nu_x - x_mas[n - 1]) / h;
	p += q * raznost[n - 2][1];
	for(i = 2, temp_q = 1; i < n; i++)
	{
		for(int proiz = 1; proiz < i + 1; proiz++) temp_q *= q + proiz;
		temp_ch = raznost[n - i - 1][i] * (q * temp_q);
		temp_zn = 1;
		for(int proiz = 1; proiz < i + 1; proiz++) temp_zn *= proiz;
		p += temp_ch / temp_zn;
	}
	
	return round(p * eps) / eps;
}

void tabl_raznostey(int n, double **raznost, double *y_mas, double *x_mas)
{
	for(int i = 0; i < n; i++) raznost[i][0] = y_mas[i];
	cout << endl << "Tablica raznostey nutona" << endl;
	
	for(int i = 1; i < n; i++)
		for(int j = n - i; j > -1; j--)
		{
//			cout << endl << i << " -- " << j;
			if(j == n - i) raznost[j][i] = 0;
			else raznost[j][i] = raznost[j + 1][i - 1] - raznost[j][i - 1];
//			if(raznost[j][i] < 0) raznost[j][i] *= -1;
		}
	
	for(int i = 0; i < n; i++)
	{
		cout << endl << x_mas[i] << "	";
		for(int j = 0; j < n; j++) cout << raznost[i][j] << "	";
	}
}

double epsilon(double &E_okr, double &E_us, double nu_x, int n, double *y_mas,double *x_mas, double **raznost, double eps, double h)
{
	double temp_ch = raznost[n - 1][0], temp_zn = 1, temp_q, q = (nu_x - x_mas[0]) / h;

	temp_q = q;
	for(int proiz = 1; proiz < n + 1; proiz++) temp_zn *= proiz;
	for(int proiz = 1; proiz < n; proiz++) temp_q *= q - proiz;
	
	E_okr = 1 / eps;
	E_us = (temp_ch / temp_zn) * q;
}

int main()
{
	int i, kr = -1, jz = -1, ll = -1, n, temp_i;
	
	cout << endl << "Vvedite kolvo tochek interpolyacii: ";
	cin >> n;
	
	double shag = 0.01, h, eps = 10000, x_mas[n], y_mas[n];
	double **raznost = new double* [n];
	for (i = 0; i < n; i++) raznost[i] = new double [n];
	
	cout << endl << "Vvedite shag interpolyacii: ";
	cin >> h;
	
	cout << endl << "Vvedite nachalnuy tochku interpolyacii: ";
	cin >> x_mas[0];
	
	VertexArray x_g(LineStrip, n*3);
	for(temp_i = 0, i = 0; temp_i < n; temp_i++, i += 3)
	{
		if(temp_i == 0);
		else x_mas[temp_i] = x_mas[temp_i - 1] + h;
		cout << endl << "x[" << temp_i << "] = " << x_mas[temp_i]; 
		y_mas[temp_i] = formula(x_mas[temp_i]);
		cout << " y = " << y_mas[temp_i];
		
		x_g[i].position = Vector2f(360 + x_mas[temp_i], 360);
		x_g[i + 1].position = Vector2f(360 + x_mas[temp_i], 360 - y_mas[temp_i]);
		x_g[i].color = Color::Green;
		x_g[i + 1].color = Color::Green;
		x_g[i + 2].position = Vector2f(360 + x_mas[temp_i], 360);
		x_g[i + 2].color = Color::Green;
	}
	
	tabl_raznostey(n, raznost, y_mas, x_mas);

	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(720, 720), "nuton", Style::Default, settings);
	double x = 0, kolvo = 720 / shag, nu_x, nu_y, E_us = 1, E_okr = 1, temp = 0;

	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);
	VertexArray lines_nu_1(LineStrip, kolvo);
	VertexArray lines_nu_2(LineStrip, kolvo);
	VertexArray nuton_1(LineStrip, 2);
	VertexArray nuton_2(LineStrip, 2);
	
	os_x[0].position = Vector2f(720, 360);
	os_x[1].position = Vector2f(0, 360);
	
	os_y[0].position = Vector2f(360, 720);
	os_y[1].position = Vector2f(360, 0); 
	
	cout << endl << "Vvedite x: ";
	cin >> nu_x;
	
	nu_y = formula_nu_1(nu_x, h, n, raznost, x_mas, eps);
	nuton_1[0].position = Vector2f(360 + nu_x, 360);
	nuton_1[1].position = Vector2f(360 + nu_x, 360 - nu_y);
	nuton_1[0].color = Color::Red;
	nuton_1[1].color = Color::Red;
	cout << endl << "1-Formula Nutona: " << "x = " << nu_x << " y = " << nu_y << endl;
	
	nu_y = formula_nu_2(nu_x, h, n, raznost, x_mas, eps);
	nuton_2[0].position = Vector2f(360 + nu_x, 360);
	nuton_2[1].position = Vector2f(360 + nu_x, 360 - nu_y);
	nuton_2[0].color = Color::Yellow;
	nuton_2[1].color = Color::Yellow;
	cout << endl << "2-Formula Nutona: " << "x = " << nu_x << " y = " << nu_y << endl; 
	
	epsilon(E_okr, E_us, nu_x, n, y_mas, x_mas, raznost, eps, h);
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
			lines_nu_1[i].position = Vector2f(360 + x, 360 - formula_nu_1(x, h, n, raznost, x_mas, eps));
			lines_nu_1[i].color = Color::Red;
			lines_nu_2[i].position = Vector2f(360 + x, 360 - formula_nu_2(x, h, n, raznost, x_mas, eps));
			lines_nu_2[i].color = Color::Yellow;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::D)) view.move(0.001 + temp, 0);
		else if (Keyboard::isKeyPressed(Keyboard::S)) view.move(0, 0.001 + temp);
		else if (Keyboard::isKeyPressed(Keyboard::A)) view.move(-0.001 - temp, 0);
		else if (Keyboard::isKeyPressed(Keyboard::W)) view.move(0, -0.001 - temp);
		else if (Keyboard::isKeyPressed(Keyboard::E))
		{
			temp -= 0.001;
			view.zoom(1.001f + temp);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			temp += 0.001;
			view.zoom(0.999f - temp);
		}
		
		if(Keyboard::isKeyPressed(Keyboard::K)) kr *= -1;
		if(Keyboard::isKeyPressed(Keyboard::J)) jz *= -1;
		if(Keyboard::isKeyPressed(Keyboard::L)) ll *= -1;
		
		window.clear();
		window.setView(view);
		if(kr == 1) window.draw(nuton_1);
		if(jz == 1) window.draw(nuton_2);
		window.draw(x_g);
	 	window.draw(os_x);
	 	window.draw(os_y);
		window.draw(lines);
		if(ll == 1)
		{
		window.draw(lines_nu_1);
		window.draw(lines_nu_2);
		}
		window.display();
	}
	
	return 0;
}
