#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 

using namespace std;

const double eps = 0.00001, e = 2.71828182846;

int opredelitel()
{
	return 2;
}

double formula(double x, double *y_mas)
{
	return (pow(e, x) + y_mas[0] + y_mas[1]) / 3;
//	return x * y_mas[1] + y_mas[0];
// 	return x + y_mas[0] + x * y_mas[1] - y_mas[2];
}

void du_4(double x_first, double x_last, double h, double *y_mas, int n, double *y_mas_for_chek)
{
//	cout << endl << "Zahli v funciu: -----------------------------------------" << endl;
//	cout << endl << "x_first = " << x_first << endl;
//	cout << endl << "x_last = " << x_last << endl;
	
	int du_step = 1;
	double **k_mas;
	k_mas = new double* [4];
    for (int i = 0; i < 4; i++) k_mas[i] = new double [n];
    
    double *save_y_mas = nullptr;
	save_y_mas = new double [n];
//	cout << endl << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO EVROPA OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
	for (int i = 0; i < n; i++)
	{
		save_y_mas[i] = y_mas[i];
//		cout << endl << save_y_mas[i] << endl;
		y_mas[i] = 0;
	}
//	cout << endl << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO EVROPA OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
//	for(int i = 0; i < n; i++) cout << endl << "y_mas = " << y_mas[i] << endl;
//	for(int i = 0; i < n; i++) cout << endl << "save_y_mas = " << save_y_mas[i] << endl;
	
	for(double x = x_first; x <= x_last; x += h, du_step++)
	{
//		cout << endl << "----------------------------------------|du_Step" << du_step << "|----------------------------------------" << endl;
//		cout << endl << "x = " << x << endl;
		
//		cout << endl << "--------\\" << endl;
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
//				for(int i = 0; i < n; i++) cout << endl << "	k1_mas = " << k_mas[0][i] << endl;
			}
			else if(k == 2)
			{
				for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2) * k_mas[0][i];
				for(int q = n - 1, z = 0; q > 0; q--, z++) k_mas[1][z] = y_mas[q];
				k_mas[1][n - 1] = formula(x + h / 2, y_mas);
				for (int i = 0; i < n; i++) y_mas[i] = 0;
//				for(int i = 0; i < n; i++) cout << endl << "	k2_mas = " << k_mas[1][i] << endl;
			}
			else if(k == 3)
			{
				for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2) * k_mas[1][i];
				for(int q = n - 1, z = 0; q > 0; q--, z++) k_mas[2][z] = y_mas[q];;
				k_mas[2][n - 1] = formula(x + h /2, y_mas);
				for (int i = 0; i < n; i++) y_mas[i] = 0;
//				for(int i = 0; i < n; i++) cout << endl << "	k3_mas = " << k_mas[2][i] << endl;
			}
			else if(k == 4)
			{
				for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2) * k_mas[2][i];
				for(int q = n - 1, z = 0; q > 0; q--, z++) k_mas[3][z] = y_mas[q];;
				k_mas[3][n - 1] = formula(x + h, y_mas);
				for (int i = 0; i < n; i++) y_mas[i] = 0;
//				for(int i = 0; i < n; i++) cout << endl << "	k4_mas = " << k_mas[3][i] << endl;
			}
		}
//		cout << endl << "--------/" << endl;
		
		for(int i = 0; i < n; i++)
		{
			y_mas[i] =  save_y_mas[i] + h / 6 * (k_mas[0][i] + 2 * k_mas[1][i] + 2 * k_mas[2][i] + k_mas[3][i]);
			save_y_mas[i] = y_mas[i];
		}
		
//		for(int i = 0; i < n; i++) cout << endl << "y_mas = " << y_mas[i] << endl;
		
//		cout << endl << "JJJJJJJJJJJJJJKKKKKKKKKJJJJJJJJJJJJJJJJJKKKKKKKKKKJJJJJJ" << endl;
		y_mas_for_chek[du_step - 1] = y_mas[0];
//		cout << endl << y_mas_for_chek[du_step - 1] << "    " << y_mas[0] << "      " << du_step - 1 << endl;
//		cout << endl << "JJJJJJJJJJJJJJKKKKKKKKKJJJJJJJJJJJJJJJJJKKKKKKKKKKJJJJJJ" << endl;
//		cout << endl;
	}
	
	delete [] k_mas;
}

main()
{
	double x_first, x_last, h, I1, I2;
	
	cout << endl << "1) x_first\n2) x_last\n3) Shag" << endl;
	cin >> x_first >> x_last >> h;
	
	int n, step = 0, n_shag = (x_last / h) - (x_first / h) + 1;
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
	
	cout << endl << "--------Nachalo resheniya---------" << endl;
	
	while(good == false)
	{
		double *prev_y_mas = nullptr;
		prev_y_mas = new double [n_shag];
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, prev_y_mas);
		
		step++;
//		cout << endl << "|-/--/--/--/-|Shag [ "<< step << " ] dvoinogo perecheta|--/--/--/--/-|" << endl;
		
		h /= 2;
		n_shag = (x_last / h) - (x_first / h) + 1;
		
		double *next_y_mas = nullptr;
		next_y_mas = new double [n_shag];
		
//		cout << endl << "h = " << h << endl;
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, next_y_mas);
		
//		cout << endl << "ddddddddddddddddddddddddddddddddddd" << endl;
//		for(int i = 0; i < n_shag / 2; i++) cout << endl << prev_y_mas[i] << endl;
//		cout << endl << "dddddddddddddddSSSSSSSSSSSSSSSSSdddddddddddddddddddd" << endl;
//		for(int i = 0; i < n_shag; i++) cout << endl << next_y_mas[i] << endl;
//		cout << endl << "ddddddddddddddddddddddddddddddddddd" << endl;
		
			for(int i = 1; i < (n_shag - 1) / 2 ; i++)
			{
//				cout << endl << " i = " << i << "  &&  i * 2 = " << i * 2 << "  n_shag = " << n_shag / 2 << endl;
//				cout << endl << "y(h): " << prev_y_mas[i] << endl;
//				cout << endl << "y(h/2): " << next_y_mas[i * 2] << endl;
//				cout << endl << "Korektirovka: " << fabs(prev_y_mas[i] - next_y_mas[i * 2]) << " < " << 15 * eps << endl;
				if(prev_y_mas[i] - next_y_mas[i * 2] < 15 * eps) test_all_mas = true; 
				else
				{
//					cout << endl << "FALSE" << endl;
					test_all_mas = false;
					break;
				}
			}

		delete [] next_y_mas;
		delete [] prev_y_mas;
		
		if(test_all_mas == true)
		{
			cout << endl << "----------------------------------";
			cout << endl << "Otvet: " << endl;
			for(int i = 0; i < n; i++) cout << endl << "	" << y_mas[i] << endl;
			cout << endl << "Kolvo shagod: " << step << endl;
			cout << endl << "h = : " << h;
			good = true;
		}
	}

	cout << endl << "--------Konec resheniya---------" << endl;
	
	return 0;
}
