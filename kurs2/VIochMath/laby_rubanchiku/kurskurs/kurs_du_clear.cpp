#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 

using namespace std;

const double eps = 0.00001;

int opredelitel()
{
	return 2;
}

double formula(double x, double *y_mas)
{
	return (exp(x) + y_mas[0] + y_mas[1]) / 3.0;
}

void du_4(double x_first, double x_last, double h, double *y_mas, int n, double **y_mas_for_chek)
{
	int du_step = 1;
	
	double **k_mas = new double* [4];
    for (int i = 0; i < 4; i++) k_mas[i] = new double [n];
	
    double *save_y_mas = nullptr;
	save_y_mas = new double [n];
	for (int i = 0; i < n; i++) save_y_mas[i] = y_mas[i];
	
	for(double x = x_first; x < x_last + h; x += h, du_step++)
	{
//		cout << endl << "x =	" << setprecision(8) << x;
		
		for(int q = 0; q < n - 1; q++) k_mas[0][q] = save_y_mas[q + 1];
		k_mas[0][n - 1] = formula(x, save_y_mas);
	
		for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2.0) * k_mas[0][i];
		for(int q = 0; q < n - 1; q++) k_mas[1][q] = y_mas[q + 1];
		k_mas[1][n - 1] = formula(x + (h / 2.0), y_mas);
	
		for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2.0) * k_mas[1][i];
		for(int q = 0; q < n - 1; q++) k_mas[2][q] = y_mas[q + 1];
		k_mas[2][n - 1] = formula(x + (h / 2.0), y_mas);

		for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + h * k_mas[2][i];
		for(int q = 0; q < n - 1; q++) k_mas[3][q] = y_mas[q + 1];
		k_mas[3][n - 1] = formula(x + h, y_mas);
		
		if(x == x_first)
		{
			for(int i = 0; i < n; i++)
			{
				y_mas[i] =  save_y_mas[i];
				save_y_mas[i] = y_mas[i];
			}
		}
		
		else
		{
			for(int i = 0; i < n; i++)
			{
				y_mas[i] =  save_y_mas[i] + (h / 6.0) * (k_mas[0][i] + (2.0 * k_mas[1][i]) + (2.0 * k_mas[2][i]) + k_mas[3][i]);
				save_y_mas[i] = y_mas[i];
				y_mas_for_chek[i][du_step - 2] = y_mas[i];
			}
		}
//		for(int i = 0; i < n; i++) cout << "	|	" << setprecision(8) << y_mas[i] << "	|";
	}
	
	for (int i = 0; i < 4; i++) delete [] k_mas[i];
	delete [] k_mas;
}

main()
{
	double x_first, x_last, h;
	
	cout << endl << "1) x_first\n2) x_last\n3) Shag" << endl;
	cin >> x_first >> x_last >> h;
	
	int n, step = 1, n_shag = (x_last / h) - (x_first / h) + 1, prev_shag;
	string temp_y = "y";
	n = opredelitel();
	
	double *y_mas = nullptr;
	y_mas = new double [n];
	
	double *temp_y_mas = nullptr;
	temp_y_mas = new double [n];
	
	cout << endl << "Vvedite nachalnye usloviya: ";
	for(int i = 0; i < n; i++)
	{
		cout << endl << temp_y << " = ";
		cin >> y_mas[i];
		temp_y_mas[i] = y_mas[i];
		temp_y += "'";
	}
	
	bool good = false, test_all_mas = false;
	
	while(good == false)
	{
    	double **prev_y_mas = new double* [n];
    	for (int i = 0; i < n; i++) prev_y_mas[i] = new double [n_shag];
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, prev_y_mas);
		
		step++;
		
		prev_shag = n_shag;
		h /= 2;
		n_shag = (x_last / h) - (x_first / h) + 1;
		double **next_y_mas = new double* [n];
    	for (int i = 0; i < n; i++) next_y_mas[i] = new double [n_shag];
		cout << endl << "h = " << h << endl;
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, next_y_mas);
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 1; j < prev_shag; j++)
			{
				if(fabs((prev_y_mas[i][j] - next_y_mas[i][j * 2])) < (15 * eps)) test_all_mas = true; 
				else
				{
					cout << endl << "FALSE" << endl;
					cout << endl << " j = " << j << "  &&  j * 2 = " << j * 2 << "  prev_shag = " << prev_shag << " h =  " << h << endl;
					cout << endl << "y(h): "  << setprecision(6) << prev_y_mas[i][j] << endl;
					cout << endl << "y(h/2): " << setprecision(6) << next_y_mas[i][j * 2] << endl;
					cout << endl << "Korektirovka: " << setprecision(6) << fabs(prev_y_mas[i][j] - next_y_mas[i][j * 2]) << " < " << 15 * eps << endl;
					test_all_mas = false;
					break;
				}
			}
			if(test_all_mas == false) break;
		}

		for (int i = 0; i < n; i++)
		{
			delete [] prev_y_mas[i];
			delete [] next_y_mas[i];
		}
		delete [] prev_y_mas;
		delete [] next_y_mas;
		
		if(test_all_mas == true)
		{
			cout << endl << "----------------------------------";
			cout << endl << "Otvet: " << endl;
			for(int i = 0; i < n; i++) cout << endl << "	" << setprecision(8) << y_mas[i] << endl;
			cout << endl << "Kolvo shagod: " << step << endl;
			cout << endl << "h = : " << h;
			good = true;
		}
	}

	cout << endl << "--------Konec resheniya---------" << endl;
	
	return 0;
}
