#include "SFML.hpp"

using namespace std;
using namespace sf;

double formula(double x)
{
	return sqrt(x);
}

void c_matrix(double **c_mas, double *h_mas, int n)
{
	cout << endl << endl;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) c_mas[i][j] = 0;
	for(int i = 0, temp = 3; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				c_mas[i][j] = (h_mas[i] + h_mas[i + 1]) / 3;
				c_mas[i][j + 1] = h_mas[temp] / 6;
				c_mas[i + 1][j] = h_mas[i + 2] / 6;
			}
			cout << "	" << c_mas[i][j];
		}
		cout << endl;
	}
}

void d_vector(double *y_mas, double *h_mas, double *d_mas, int n)
{
	cout << endl;
	for(int i = 1; i < n + 1; i++)
	{
		d_mas[i - 1] = ((y_mas[i + 1] - y_mas[i]) / h_mas[i]) - ((y_mas[i] - y_mas[i - 1]) / h_mas[i - 1]);
		cout << endl << "d[" << i - 1 << "] = " << d_mas[i - 1];
	}
}

void gaus(double **c_mas, double *d_mas, int size, double *m_mas)
{
	double **A = new double* [size];
	for(int i = 0; i < size; i++) A[i] = new double [size];
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++) A[i][j] = c_mas[i][j];
		 A[i][size] = d_mas[i];
	}
	
	float mnozhitel;
	int i, j, dioganal, temp;
	
	cout << endl << endl << "------Matrix - A------" << endl;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size + 1; j++)
		{
			cout << " " << round(A[i][j]*100)/100 << " ";
		}
		cout << endl;
	}
	cout << "------Matrix - A------" << endl;
	
	for(dioganal = 0; dioganal < size-1; dioganal++)
	{
		cout << endl << " dioganal = " << dioganal << endl;
		for(i = 1 + dioganal; i < size; i++)
		{
			j = 0;
			mnozhitel = A[i][dioganal] / A[dioganal][dioganal];
			cout << "  mnozhitel= " << mnozhitel << "   A[dioganal][dioganal] = " << A[dioganal][dioganal] << "   A[i][dioganal]=" << A[i][dioganal] << endl;
			for(j = 0; j < size + 1; j++)
			{
				A[i][j] -= mnozhitel * A[dioganal][j];
				if(A[i][j] == 0) if(A[dioganal][j] != 0) cout << "  A[" << i << "][" << j << "] = " << A[i][j] << endl;
			}
		}
		cout << endl << "------Matrix - A------" << endl;
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size + 1; j++)
			{
				cout << " " << round(A[i][j]*100)/100 << " ";
			}
			cout << endl;
		}
		cout << "------Matrix - A------" << endl;
	}
	
	for(dioganal = 1, mnozhitel = 1; dioganal < size + 1; dioganal++)
	{
		for(temp = dioganal - 1; temp > 0; temp--) A[size - dioganal][size] -= A[size - dioganal][size - temp];
		mnozhitel = A[size - dioganal][size] / A[size - dioganal][size - dioganal];
		for(temp = size - 1; temp >= 0; temp--) A[temp][size - dioganal] *= mnozhitel;
		cout << "x" << size - dioganal + 1 << " = " << mnozhitel << endl;
		m_mas[size-dioganal + 1] = mnozhitel; 
	}
}

double s_formula(double sp_x, double *x_mas, double *h_mas, double *y_mas, double *m_mas, int i, double &rez)
{
	double sk1, sk2, sk3, sk4 ,sk5 ,sk6, temp_ch, temp_zn;
	
	temp_ch = pow((x_mas[i] - sp_x), 3);
	temp_zn = 6 * h_mas[i];
	sk1 = m_mas[i - 1] * temp_ch / temp_zn;
	
	temp_ch = pow((sp_x - x_mas[i - 1]), 3);
	temp_zn = 6 * h_mas[i];
	sk2 = m_mas[i] * temp_ch / temp_zn;
	
	temp_ch = y_mas[i - 1] * m_mas[i - 1] * pow(h_mas[i], 2);
	temp_zn = 6;
	sk3 = temp_ch / temp_zn;
	
	temp_ch = x_mas[i] - sp_x;
	temp_zn = h_mas[i];
	sk4 = temp_ch / temp_zn;
	
	temp_ch = y_mas[i] * m_mas[i] * pow(h_mas[i], 2);
	temp_zn = 6;
	sk5 = temp_ch / temp_zn;
	
	temp_ch = sp_x - x_mas[i - 1];
	temp_zn = h_mas[i];
	sk6 = temp_ch / temp_zn;
	
	rez = sk1 + sk2 + sk3 * sk4 + sk5 * sk6;
}

int main()
{
	int i, n, temp_i, swap_1, swap_2;	
	double shag = 0.01;
	
	View view;
	view.reset(FloatRect(300, 300, 120, 120));
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(720, 720), "spline", Style::Default, settings);
	double x = 0, kolvo = 720 / shag, sp_x, sp_y, temp = 0, rez;

	VertexArray os_x(LineStrip, 2);
	VertexArray os_y(LineStrip, 2);
	VertexArray lines(LineStrip, kolvo);
	VertexArray lines_sp(LineStrip, kolvo);
	VertexArray sp_g(LineStrip, 2);
	
	cout << endl << "Vvedite kolvo tochek interpolyacii: ";
	cin >> n;
	
	double s, d_mas[n - 2], y_mas[n], x_mas[n], h_mas[n - 1], m_mas[n - 2], eps = 10000, raznost[n][n];
	double **c_mas = new double* [n - 2];
	for (i = 0; i < n - 1; i++) c_mas[i] = new double [n - 2];
	
	VertexArray x_g(LineStrip, n*3);
	for(temp_i = 0, i = 0; temp_i < n; temp_i++, i += 3)
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
	
	cout << endl << "Vvedite x: ";
	cin >> sp_x;
	
//	
	c_matrix(c_mas, h_mas, n - 2);
	d_vector(y_mas, h_mas, d_mas, n - 2);
	gaus(c_mas, d_mas, n - 2, m_mas);
	s_formula(sp_x, x_mas, h_mas, y_mas, m_mas, 2, rez);
	sp_y = rez;
	cout << endl << "y = " << rez;
	sp_g[0].position = Vector2f(360 + sp_x, 360);
	sp_g[1].position = Vector2f(360 + sp_x, 360 - sp_y);
	sp_g[0].color = Color::Red;
	sp_g[1].color = Color::Red;
//	
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
			s_formula(x, x_mas, h_mas, y_mas, m_mas, 2, rez);
			lines_sp[i].position = Vector2f(360 + x, 360 - rez);
			lines_sp[i].color = Color::Red;
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
		window.draw(lines_sp);
		window.display();
	}
	
	return 0;
}
