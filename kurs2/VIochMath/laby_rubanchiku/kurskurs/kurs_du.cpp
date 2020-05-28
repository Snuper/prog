#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double eps = 0.00001;

double formula(double x, double *y_mas)
{
//	return x * y_mas[1] + y_mas[0];
 	return x + y_mas[0] + x * y_mas[1] - y_mas[2];
}

double du_4(double x_first, double x_last, double h, double *y_mas, int n)
{
//	cout << endl << "Zahli v funciu: -----------------------------------------" << endl;
	int du_step = 1;
	double **k_mas;
	k_mas = new double* [4];
    for (int i = 0; i < 4; i++) k_mas[i] = new double [n];
    
    double *save_y_mas = nullptr;
	save_y_mas = new double [n];
	for (int i = 0; i < n; i++)
	{
		save_y_mas[i] = y_mas[i];
		y_mas[i] = 0;
	}
//	for(int i = 0; i < n; i++) cout << endl << "y_mas = " << y_mas[i] << endl;
//	for(int i = 0; i < n; i++) cout << endl << "save_y_mas = " << save_y_mas[i] << endl;
	
	for(double x = x_first; x <= x_last + h; x += h, du_step++)
	{
		cout << endl << "----------------------------------------|du_Step" << du_step << "|----------------------------------------" << endl;
		cout << endl << "x = " << x << endl;
		
		cout << endl << "--------\\" << endl;
		for(int k = 1; k < 5; k++)
		{
			if(k == 1)
			{
				for(int q = n - 1, z = 0; q > 0; q--, z++)
				{
					k_mas[0][z] = save_y_mas[q];
//					cout << endl << "Neochen test y_mas = " << save_y_mas[q] << "  i konechno je q = " << q;
//					cout << endl << "Neochen test k_mas = " << k_mas[0][z] << "  i konechno je z = " << z;
				}
				k_mas[0][n - 1] = formula(x, save_y_mas);
				for(int i = 0; i < n; i++) cout << endl << "	k1_mas = " << k_mas[0][i] << endl;
			}
			else if(k == 2)
			{
				for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2) * k_mas[0][i];
				for(int q = n - 1, z = 0; q > 0; q--, z++) k_mas[1][z] = y_mas[q];
				k_mas[1][n - 1] = formula(x + h / 2, y_mas);
				for (int i = 0; i < n; i++) y_mas[i] = 0;
				for(int i = 0; i < n; i++) cout << endl << "	k2_mas = " << k_mas[1][i] << endl;
			}
			else if(k == 3)
			{
				for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2) * k_mas[1][i];
				for(int q = n - 1, z = 0; q > 0; q--, z++) k_mas[2][z] = y_mas[q];;
				k_mas[2][n - 1] = formula(x + h /2, y_mas);
				for (int i = 0; i < n; i++) y_mas[i] = 0;
				for(int i = 0; i < n; i++) cout << endl << "	k3_mas = " << k_mas[2][i] << endl;
			}
			else if(k == 4)
			{
				for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2) * k_mas[2][i];
				for(int q = n - 1, z = 0; q > 0; q--, z++) k_mas[3][z] = y_mas[q];;
				k_mas[3][n - 1] = formula(x + h, y_mas);
				for (int i = 0; i < n; i++) y_mas[i] = 0;
				for(int i = 0; i < n; i++) cout << endl << "	k4_mas = " << k_mas[3][i] << endl;
			}
		}
		cout << endl << "--------/" << endl;
		
		for(int i = 0; i < n; i++)
		{
			y_mas[i] = save_y_mas[i] + h / 6 * (k_mas[0][i] + 2 * k_mas[1][i] + 2 * k_mas[2][i] + k_mas[3][i]);
			save_y_mas[i] = y_mas[i];
		}
		for(int i = 0; i < n; i++) cout << endl << "y_mas = " << y_mas[i] << endl;
		cout << endl;
	}
	
	return y_mas[0];
	delete [] k_mas;
}

int opredelitel()
{
	return 3;
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
	
	I1 = du_4(x_first, x_last, h, y_mas, n);
	
	bool good = false;
	
	cout << endl << "--------Nachalo resheniya---------" << endl;
	
	while(good == false)
	{
		step++;
		cout << endl << "|-/\--/\--/\--/\-|Shag [ "<< step << " ] dvoinogo perecheta|--/\--/\--/\--/\-|" << endl;
		
		h /= 2;
		cout << endl << "h = " << h << endl;
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		
		I2 = du_4(x_first, x_last, h, y_mas, n);
		
		
		cout << endl << "I1: " << I1 << endl;
		cout << endl << "I2: " << I2 << endl;
		cout << endl << "Korektirovka: " << fabs(I1 - I2) << " < " << eps << endl;
		
		if(fabs(I1 - I2) < eps)
		{
			cout << endl << "----------------------------------";
			cout << endl << "Otvet: " << endl;
			for(int i = 0; i < n; i++) cout << endl << "	" << y_mas[i] << endl;
			cout << endl << "Kolvo shagod: " << step;
			good = true;
		}
		
		I1 = du_4(x_first, x_last, h, y_mas, n);
	}

	cout << endl << "--------Konec resheniya---------" << endl;
	
	return 0;
}
