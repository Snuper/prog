#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const double eps = 10000000;

double formula(double x)
{
	return 1 / x;
}

double ch_in(double h, int n, double *y_mas)
{
	double otvet = h / 3, per = y_mas[0] + y_mas[n - 1], vto = 0, tre = 0;

	for(int i = 1; i < n - 1; i += 2) vto += y_mas[i];
	for(int i = 2; i < (n - 2); i += 2) tre += y_mas[i];

	vto *= 4;
	tre *= 2;
	
	otvet *= per + vto + tre;
	
	return  round(otvet * eps) / eps;
}

void pogreshnost(double h, double b, double a)
{
	double E_us, temp_h = h, M, E_okr = 1 / eps, E_real;
	
	for(int i = 0; i < 3; i++) h *= temp_h;
	
	M = 24;
	
	E_us = h / 180 * (b - a) * M;
	
	E_real = E_us + E_okr;
	
	cout << endl << "E_usechenaya: " << E_us;
	cout << endl << "E_okruglenie: " << E_okr;
	cout << endl << "E_realnaya: " << E_real << endl;
}

main()
{
	int n, i;
	double left, right, h, I1, I2, toch_otvet = 0.6931471805599453;
	
	cout << endl << "Vvedite granicy[Left][Right]: ";
	cin >> left >> right;
	
	cout << endl << "Vvedite shag: ";
	cin >> h;
	
	n = (right / h) - (left / h) + 1;
	
	double *x_mas = nullptr;
	x_mas = new double [n];
	
	double *y_mas = nullptr;
	y_mas = new double [n];
	
	x_mas[0] = left;
	y_mas[0] = formula(x_mas[0]);

	for(i = 1; i < n; i++)
	{
		x_mas[i] = x_mas[i - 1] + h;
		y_mas[i] = formula(x_mas[i]);
	}
	
	I1 = ch_in(h, n, y_mas);
	cout << endl << "Otvet: " << I1;
	
	cout << endl << "Pogrshnost: " << endl;
	pogreshnost(h, x_mas[n - 1], x_mas[0]);
	
	cout << endl << "---------------Dvoinoi perechet-----------------" << endl;
	
	bool good = false;

	while(good == false)
	{
		h /= 2;
		
		delete [] x_mas;
		delete [] y_mas;
		
		n = (right / h) - (left / h) + 1;
		
		double *x_mas = nullptr;
		x_mas = new double [n];
		
		double *y_mas = nullptr;
		y_mas = new double [n];
		
		x_mas[0] = left;
		y_mas[0] = formula(x_mas[0]);
		for(i = 1; i < n; i++)
		{
			x_mas[i] = x_mas[i - 1] + h;
			y_mas[i] = formula(x_mas[i]);
		}
		
		I2 = ch_in(h, n, y_mas);
		
		if(I1 - I2 < eps * 3)
		{
			cout << endl << "Otvet: " << I2;
			cout << endl << "Tochny Otvet: " << round(toch_otvet * eps) / eps;
			good = true;
		}
	}
	
	return 0;
}
