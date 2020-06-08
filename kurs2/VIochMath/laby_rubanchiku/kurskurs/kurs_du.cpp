#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> 

using namespace std;

const double eps = 0.000001;

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

void du_4(double x_first, double x_last, double h, double *y_mas, int n, double **y_mas_for_chek, int n_shag)
{
//	cout << endl << "Zahli v funciu: -----------------------------------------" << endl;
//	cout << endl << "x_first = " << x_first << endl;
//	cout << endl << "x_last = " << x_last << endl;
	
	int du_step = 1;
	
	double **k_mas = new double* [4];
    for (int i = 0; i < 4; i++) k_mas[i] = new double [n];
	
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
	
	for(double x = x_first; du_step - 1 < n_shag; x += h, du_step++)
	{
//		cout << endl << "----------------------------------------|du_Step" << du_step << "|----------------------------------------" << endl;
//		cout << endl << "x =	" << setprecision(15) << x;
		
//		if(x == x_first)
//		{
//			for(int i = 0; i < n; i++)
//			{
//				y_mas[i] =  save_y_mas[i];
//				save_y_mas[i] = y_mas[i];
//				y_mas_for_chek[i][du_step - 1] = y_mas[i];
//			}
//		}
//		else
//		{
//				cout << endl << "--------\\" << endl;
			for(int q = 0; q < n - 1; q++)
			{
				k_mas[0][q] = save_y_mas[q + 1];
		//					cout << endl << "Neochen test y_mas = " << save_y_mas[q] << "  i konechno je q = " << q;
		//					cout << endl << "Neochen test k_mas = " << k_mas[0][z] << "  i konechno je z = " << z;
			}
			k_mas[0][n - 1] = formula(x, save_y_mas);
		//		k_mas[0][n - 1] = round((formula(x, save_y_mas) / eps)) * eps;
//				for(int i = 0; i < n; i++) cout << endl << "	k1_mas = " << k_mas[0][i] << endl;
		
			for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2.0) * k_mas[0][i];
			for(int q = 0; q < n; q++) k_mas[1][q] = y_mas[q + 1];
			k_mas[1][n - 1] = formula(x + (h / 2.0), y_mas);
		//		k_mas[1][n - 1] = round((formula(x + h / 2, y_mas)) / eps) * eps;
//				for(int i = 0; i < n; i++) cout << endl << "	k2_mas = " << k_mas[1][i] << endl;
		
			for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + (h / 2.0) * k_mas[1][i];
			for(int q = 0; q < n; q++) k_mas[2][q] = y_mas[q + 1];
			k_mas[2][n - 1] = formula(x + (h / 2.0), y_mas);
		//		k_mas[2][n - 1] = round((formula(x + h /2, y_mas)) / eps) * eps;
//				for(int i = 0; i < n; i++) cout << endl << "	k3_mas = " << k_mas[2][i] << endl;
		
			for(int i = 0; i < n; i++) y_mas[i] = save_y_mas[i] + h * k_mas[2][i];
			for(int q = 0; q < n; q++) k_mas[3][q] = y_mas[q + 1];
			k_mas[3][n - 1] = formula(x + h, y_mas);
		//		k_mas[3][n - 1] = round((formula(x + h, y_mas)) / eps) * eps;
//				for(int i = 0; i < n; i++) cout << endl << "	k4_mas = " << k_mas[3][i] << endl;
//				cout << endl << "--------/" << endl;
			
		for(int i = 0; i < n; i++)
		{
			y_mas[i] =  save_y_mas[i] + (h / 6.0) * (k_mas[0][i] + (2.0 * k_mas[1][i]) + (2.0 * k_mas[2][i]) + k_mas[3][i]);
	//			y_mas[i] =  round((save_y_mas[i] + h / 6 * (k_mas[0][i] + 2 * k_mas[1][i] + 2 * k_mas[2][i] + k_mas[3][i])) / eps) * eps;
			save_y_mas[i] = y_mas[i];
	//			if(chek == 1)
	//			{
	//				chek = 0;
	//				step = 1;
	//			}
			y_mas_for_chek[i][du_step - 1] = y_mas[i];
	//			cout << endl << "LOLOLOLOLO i = " << i << endl;
	//			cout << endl << "LOLOLOLOLO du_step - 1 = " << du_step - 1 << endl;
	//			cout << endl << "LOLOLOLOLO = " << y_mas_for_chek[i][du_step - 1] << endl;
	//			cout << endl << "JJJJJJJJJJJJJJKKKKKKKKKJJJJJJJJJJJJJJJJJKKKKKKKKKKJJJJJJ" << endl;
	//			cout << endl << y_mas_for_chek[i][du_step - 1] << "    " << y_mas[0] << "      " << du_step - 1 << endl;
	//			cout << endl << "JJJJJJJJJJJJJJKKKKKKKKKJJJJJJJJJJJJJJJJJKKKKKKKKKKJJJJJJ" << endl;
		}
		
//		for(int i = 0; i < n; i++) cout << "	|	" << setprecision(15) << y_mas[i] << "	|";
		
//		cout << endl;
//		}
	}
	
	for (int i = 0; i < 4; i++) delete [] k_mas[i];
	delete [] k_mas;
}

main()
{
	double x_first, x_last, h;
	
	cout << endl << "1) x_first\n2) x_last\n3) Shag" << endl;
	cin >> x_first >> x_last >> h;
	
	int n, step = 1, n_shag = (x_last / h) - (x_first / h), prev_shag;
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
		du_4(x_first, x_last, h, y_mas, n, prev_y_mas, n_shag);
		
		step++;
//		cout << endl << "|-/--/--/--/-|Shag [ "<< step << " ] dvoinogo perecheta|--/--/--/--/-|" << endl;
		
		prev_shag = n_shag;
		h /= 2;
		n_shag = (x_last / h) - (x_first / h);
//		cout << endl << "mul test999" << endl;
		double **next_y_mas = new double* [n];
    	for (int i = 0; i < n; i++) next_y_mas[i] = new double [n_shag];
//		cout << endl << "mul test999" << endl;
		cout << endl << "h = " << h << endl;
		
		for(int i = 0; i < n; i++) y_mas[i] = temp_y_mas[i];
		du_4(x_first, x_last, h, y_mas, n, next_y_mas, n_shag);
		
//		cout << endl << "ddddddddddddddddddddddddddddddddddd" << endl;
//		for(int i = 0; i < n; i++)
//		{
//			cout << endl << "-----------|" << endl;
//			for(int j = 0; j < prev_shag; j++) cout << endl << setprecision(15) << prev_y_mas[i][j] << endl;
//		}
//		cout << endl << "dddddddddddddddSSSSSSSSSSSSSSSSSdddddddddddddddddddd" << endl;
//		for(int i = 0; i < n; i++)
//		{
//			cout << endl << "-----------|" << endl;
//			for(int j = 0; j < n_shag; j++) cout << endl << setprecision(15) << next_y_mas[i][j] << endl;
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
//				cout << endl << "y(h): " << setprecision(15) << prev_y_mas[i][j] << endl;
//				cout << endl << "y(h/2): " << setprecision(15) << next_y_mas[i][j * 2 + 1] << endl;
//				cout << endl << "Korektirovka: " << setprecision(15) << fabs(prev_y_mas[i][j] - next_y_mas[i][j * 2 + 1]) << " < " << 15 * eps << endl;
				if(fabs((prev_y_mas[i][j] - next_y_mas[i][j * 2 + 1])) < (15 * eps)) test_all_mas = true; 
				else
				{
//					cout << endl << "FALSE" << endl;
//					cout << endl << " j = " << j << "  &&  j * 2 = " << j * 2 << "  prev_shag = " << prev_shag << " h =  " << h << endl;
//					cout << endl << "y(h): "  << setprecision(15) << prev_y_mas[i][j] << endl;
//					cout << endl << "y(h/2): " << setprecision(15) << next_y_mas[i][j * 2 + 1] << endl;
//					cout << endl << "Korektirovka: " << setprecision(15) << fabs(prev_y_mas[i][j] - next_y_mas[i][j * 2 + 1]) << " < " << 15 * eps << endl;
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
