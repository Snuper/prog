#include <stdio.h>
#include <iostream>
#include <cmath>
//0.6931471805599453

using namespace std;

const double eps = 0.00001;

double formula(double x)
{
	return 1 / x;
}

double ch_in(double h, int n, double *y_mas, int flag)
{
	double otvet, per = y_mas[0] + y_mas[n - 1], vto = 0, tre = 0;
	if(flag == 1)
	{
		otvet = h / 3;
		
		for(int i = 1; i < n - 1; i += 2) vto += y_mas[i];
		for(int i = 2; i < n - 2; i += 2) tre += y_mas[i];
	
		vto *= 4;
		tre *= 2;
		
		otvet *= per + vto + tre;
	}
	else
	{
		otvet = h;	
		per *= 1.0/2.0;
				
		for(int i = 1; i < n - 1; i ++) vto += y_mas[i];
		
		otvet *= per + vto;
	}

	return otvet;
}

void pogreshnost(double h, double b, double a, int flag)
{
	double E_us, temp_h = h, M, E_okr = eps, E_real;
	
	if(flag == 1)
	{
		for(int i = 0; i < 3; i++) h *= temp_h;
		
		M = 24;
		
		E_us = h / 180 * (b - a) * M;
		
		E_real = E_us + E_okr;
	}
	else
	{
		for(int i = 0; i < 1; i++) h *= temp_h;
		
		M = 2;
		
		E_us = h / 12 * (b - a) * M;
		
		E_real = E_us + E_okr;
	}
	
	cout << endl << "E_usechenaya: " << E_us;
	cout << endl << "E_okruglenie: " << E_okr;
	cout << endl << "E_realnaya: " << E_real << endl;
}

main()
{
	int n, i;
	double left, right, h, I1, I2;
	
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
	
	int flag;
	cout << endl << "Simson - 1\nTrapeciya - 2" << endl;
	cin >> flag;
	if(flag < 1 or flag > 2) return 1;
	
	I1 = ch_in(h, n, y_mas, flag);
	cout << endl << "Otvet: " << I1;
	
	cout << endl << "Pogrshnost: " << endl;
	pogreshnost(h, x_mas[n - 1], x_mas[0], flag);
	
	cout << endl << "---------------Dvoinoi perechet-----------------" << endl;
	
	bool good = false;
	int step = 0;

	while(good == false)
	{
		h /= 2;
		cout << endl << "SHAG DROB : " << h;
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
		
		I2 = ch_in(h, n, y_mas, flag);
		
		step++;
		cout << endl << "Shag " << step;
		cout << endl << "Korektirovke " << I1 - I2 << " < " << eps;
		cout << endl << "I1 " << I1;
		cout << endl << "I2 " << I2 << endl;
		
		if(fabs(I1 - I2) < eps)
		{
			cout << endl << "----------------------------------";
			cout << endl << "Otvet: " << I2;
			cout << endl << "Kolvo shagod: " << step;
			good = true;
		}
		
		I1 = ch_in(h, n, y_mas, flag);
	}
	
	return 0;
}
