#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double eps = 0.00001;

double formula(double x, double *y_mas)
{
	return x * y_mas[1] + y_mas[0];
}

double du_4(double x_first, double x_last, double h, double *y_mas, int n)
{
	double **k_mas;
	k_mas = new double* [4];
    for (int i = 0; i < 4; i++) k_mas[i] = new double [n];
    
    double *save_y_mas = nullptr;
	save_y_mas = new double [n];
	for (int i = 0; i < n; i++) save_y_mas[i] = y_mas[i];
	
	for(double x = x_first; x < x_last + h; x += h)
	{
		cout << endl << "x = " << x << endl;
		
		for(int k = 1; k < 5; k++)
		{
			if(k == 1)
			{
				for(int q = n - 2, z = 0; q > 0; q--, z++) k_mas[0][z] = y_mas[q];
				k_mas[0][n - 1] = formula(x, y_mas);
			}
			else if(k == 2)
			{
				for(int q = n - 2, z = 0; q > 0; q--, z++) k_mas[1][z] = y_mas[q];
				k_mas[0][n - 1] = formula(x + h / 2, y_mas);
			}
			else if(k == 3)
			{
				for(int q = n - 2, z = 0; q > 0; q--, z++) k_mas[2][z] = y_mas[q];
				k_mas[0][n - 1] = formula(x + h /2, y_mas);
			}
			else if(k == 4)
			{
				for(int q = n - 2, z = 0; q > 0; q--, z++) k_mas[3][z] = y_mas[q];
				k_mas[0][n - 1] = formula(x + h, y_mas);
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			y_mas[i] = save_y_mas[i] + h / 6 * (k_mas[0][i] + 2 * k_mas[1][i] + 2 * k_mas[2][i] + k_mas[3][i]);
			cout << "	|	" << y_mas[i] << "	|	";
		}
		cout << endl;
	}
	
	delete [] k_mas;
}

int opredelitel()
{
	return 2;
}

main()
{
	double x_first, x_last, h, I1, I2;
	
	cout << endl << "1) x_first\n2) x_last\n3) Shag" << endl;
	cin >> x_first >> x_last >> h;
	
	int n, step = 0;
	string temp_y = "y";
	n = opredelitel();
	double *y_mas = nullptr;
	y_mas = new double [n];
	
	double *save_y_mas = nullptr;
	save_y_mas = new double [n];
	
	cout << endl << "Vvedite nachalnye usloviya: ";
	for(int i = 0; i < n; i++)
	{
		cout << endl << temp_y << " = ";
		cin >> y_mas[n];
		save_y_mas[n] = y_mas[n];
		temp_y += "'";
	}
	
	du_4(x_first, x_last, h, y_mas, n);
	
	bool good = false;
	
	cout << endl << "--------Nachalo resheniya---------" << endl;
	
	while(good == false)
	{
		cout << endl << "--------Shag dvoinogo perecheta---------" << endl;
		step++;
		
		h /= 2;
		
		for(int i = 0; i < n; i++) y_mas[n] = save_y_mas[n];
		
		du_4(x_first, x_last, h, y_mas, n);
		
		cout << endl << "----------Shag----------" << step << endl;
//		fabs(I1 - I2) < eps
		if(step == 3)
		{
			cout << endl << "----------------------------------";
			cout << endl << "Otvet: ";
			cout << endl << "Kolvo shagod: " << step;
			good = true;
		}
	}
	
	cout << endl << "--------Konec resheniya---------" << endl;
	
	return 0;
}
