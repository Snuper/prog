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
//	return y_mas[0];
	return (exp(x) + y_mas[0] + y_mas[1]) / 3.0;
//	return x * y_mas[1] + y_mas[0];
// 	return x + y_mas[0] + x * y_mas[1] - y_mas[2];
}

void du_4(double x_first, double x_last, double h, double *y_mas, int n, double **y_mas_for_chek)
{
//	cout << endl << "Zahli v funciu: -----------------------------------------" << endl;
//	cout << endl << "x_first = " << x_first << endl;
//	cout << endl << "x_last = " << x_last << endl;
	
	int du_step = 1;
	
	double *t_y_mas = nullptr;
	t_y_mas = new double [n];
	
	double *vi_y_mas = nullptr;
	vi_y_mas = new double [n];
	
    double *save_y_mas = nullptr;
	save_y_mas = new double [n];
//	cout << endl << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO EVROPA OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
	for (int i = 0; i < n; i++)
	{
		save_y_mas[i] = y_mas[i];
//		cout << endl << save_y_mas[i] << endl;
	}
//	cout << endl << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO EVROPA OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
//	for(int i = 0; i < n; i++) cout << endl << "y_mas = " << y_mas[i] << endl;
//	for(int i = 0; i < n; i++) cout << endl << "save_y_mas = " << save_y_mas[i] << endl;
	
	for(double x = x_first; x <= x_last; x += h, du_step++)
	{
//		cout << endl << "----------------------------------------|du_Step" << du_step << "|----------------------------------------" << endl;
//		cout << endl << "x =	" << setprecision(8) << x;
		
		if(x == x_first)
		{
			for(int i = 0; i < n; i++)
			{
				y_mas[i] =  save_y_mas[i];
				save_y_mas[i] = y_mas[i];
				y_mas_for_chek[i][du_step - 1] = y_mas[i];
			}
		}
		
		else
		{
			t_y_mas[n - 1] = formula(x, save_y_mas);
			for(int q = 0; q < n - 1; q++) t_y_mas[q] = save_y_mas[q + 1];
			
			for(int i = 0; i < n; i++) vi_y_mas[i] = save_y_mas[i] + (h / 2.0) * t_y_mas[i];
			
			t_y_mas[n - 1] = formula(x + h / 2.0, vi_y_mas);
			for(int q = 0; q < n - 1; q++) t_y_mas[q] = vi_y_mas[q + 1];
			
			for(int i = 0; i < n; i++)
			{
				y_mas[i] = save_y_mas[i] + t_y_mas[i];
				save_y_mas[i] = y_mas[i];
				y_mas_for_chek[i][du_step - 1] = y_mas[i];
			}
		}
		
//		for(int i = 0; i < n; i++) cout << "	|	" << setprecision(8) << y_mas[i] << "	|";
		
//		cout << endl;
	}
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
	
//	cout << endl << "--------Nachalo resheniya---------" << endl;
	
	while(good == false)
	{
//		cout << endl << "mul test000" << endl;
    	double **prev_y_mas = new double* [n];
    	for (int i = 0; i < n; i++) prev_y_mas[i] = new double [n_shag];
//		cout << endl << "mul test000" << endl;
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, prev_y_mas);
		
		step++;
//		cout << endl << "|-/--/--/--/-|Shag [ "<< step << " ] dvoinogo perecheta|--/--/--/--/-|" << endl;
		
		prev_shag = n_shag;
		h /= 2;
		n_shag = (x_last / h) - (x_first / h) + 1;
//		cout << endl << "mul test999" << endl;
		double **next_y_mas = new double* [n];
    	for (int i = 0; i < n; i++) next_y_mas[i] = new double [n_shag + 1];
//		cout << endl << "mul test999" << endl;
		cout << endl << "h = " << h << endl;
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, next_y_mas);
		
//		cout << endl << "ddddddddddddddddddddddddddddddddddd" << endl;
//		for(int i = 0; i < n; i++)
//		{
//			cout << endl << "-----------|" << endl;
//			for(int j = 0; j < prev_shag; j++) cout << endl << prev_y_mas[i][j] << endl;
//		}
//		cout << endl << "dddddddddddddddSSSSSSSSSSSSSSSSSdddddddddddddddddddd" << endl;
//		for(int i = 0; i < n; i++)
//		{
//			cout << endl << "-----------|" << endl;
//			for(int j = 0; j < n_shag; j++) cout << endl << next_y_mas[i][j] << endl;
//		}
//		cout << endl << "ddddddddddddddddddddddddddddddddddd" << endl;
		
//		cout << endl << "NULINULI" << endl;
		for(int i = 0; i < n; i++)
		{
//			cout << endl << "		APAPAPAP" << endl;
			for(int j = 1; j < prev_shag; j++)
			{
//				cout << endl << "		UTUTUTU" << endl;
//				cout << endl << " j = " << j << "  &&  j * 2 = " << j * 2 << "  prev_shag = " << prev_shag << " h =  " << h << endl;
//				cout << endl << "y(h): " << prev_y_mas[i][j] << endl;
//				cout << endl << "y(h/2): " << next_y_mas[i][j * 2] << endl;
//				cout << endl << "Korektirovka: " << fabs(prev_y_mas[i][j] - next_y_mas[i][j * 2]) << " < " << 15 * eps << endl;
				if(fabs((prev_y_mas[i][j] - next_y_mas[i][j * 2])) < (15 * eps)) test_all_mas = true; 
				else
				{
//					cout << endl << "FALSE" << endl;
//					cout << endl << " j = " << j << "  &&  j * 2 = " << j * 2 << "  prev_shag = " << prev_shag << " h =  " << h << endl;
//					cout << endl << "y(h): "  << setprecision(6) << prev_y_mas[i][j] << endl;
//					cout << endl << "y(h/2): " << setprecision(6) << next_y_mas[i][j * 2] << endl;
//					cout << endl << "Korektirovka: " << setprecision(6) << fabs(prev_y_mas[i][j] - next_y_mas[i][j * 2]) << " < " << 15 * eps << endl;
					test_all_mas = false;
					break;
				}
//				cout << endl << "		FFFFFFFFFFFF" << endl;
			}
			if(test_all_mas == false) break;
		}
//		cout << endl << "mul test1" << endl;
		for (int i = 0; i < n; i++)
		{
//			cout << "0";
			delete [] prev_y_mas[i];
			delete [] next_y_mas[i];
		}
//		cout << endl << "mul test1 - 2" << endl;
		delete [] prev_y_mas;
//		cout << endl << "mul test2" << endl;
		delete [] next_y_mas;
//		cout << endl << "mul test2" << endl;
		
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
