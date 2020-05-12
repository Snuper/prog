#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double formula(double x)
{
	return 1 / x;
}

main()
{
	int n, i;
	double left, right, h, otvet, per, vto, tre;
	
	cout << endl << "Vvedite granicy[Left][Right]: ";
	cin >> left >> right;
	
	cout << endl << "Vvedite shag: ";
	cin >> h;
	
	n = (right / h) - (left / h) + 1;
	
	double x_mas[n], y_mas[n];
	
	x_mas[0] = left;
	y_mas[0] = formula(x_mas[0]);

	for(i = 1; i < n; i++)
	{
		x_mas[i] = x_mas[i - 1] + h;
		y_mas[i] = formula(x_mas[i]);
	}
	
	otvet =  h / 3;
	per = y_mas[0] + y_mas[n - 1];
	
	for(i = 1; i < n - 1; i += 2) vto += y_mas[i];
	for(i = 2; i < (n - 2); i += 2) tre += y_mas[i];

	vto *= 4;
	tre *= 2;
	
	otvet *= per + vto + tre;
	
	cout << endl << "Otvet: " << otvet;
	
	return 0;
}
