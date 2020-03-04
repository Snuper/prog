#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int Stepen(int number)
{
	int stepen;
	if (number == 1) return 0;
	if (number == 2) return 1;
	for (stepen = 0; number > 0; stepen++) number = number / 2;
	return stepen;
}

void Perevod(int number, int q)
{
	if (number > q)
	{
	Perevod(number / 2, q);
	cout << number % 2;
	}
}

void Fixed_Variable(int number, int stepen)
{
	Perevod(stepen, 0);
	cout << " ";
	Perevod(number, 1);
}

void Alias_g(int number, int stepen)
{
	for (int i = 1; i < stepen; i++) cout << "0";
	cout << " 1 ";
	Perevod(number, 1);
}

void Alias_o(int number, int stepen)
{
	for(int i = stepen - 1; i < stepen; i++)
	{	
		cout << "1";	
		Perevod(i+1, i/2+1);
		cout << " ";
		Perevod(i, 0);
		cout << " ";
	} 
	Perevod(number, 0);
}

int main()
{
	int number, i_in = 0, i;
	cout << "Number: " << endl;
	cin >> number;
	cout << "| N | " << "  FV  | " << "  AG  | " << "  AO  |" << endl;
	int stepen = Stepen(number);
	for (i = 0; i < stepen; i++)
	{
		for (; i_in < pow(2, i); i_in++)
		{
			cout << "| " << i_in << " | ";
			if (i_in == 0) cout << "0000";
			else if (i_in == 1) cout << "000";
			else if (i_in < 8) cout << "00";
			else if (i_in < 128) cout << "0";
			Fixed_Variable(i_in, i);
			cout << " |";
			Alias_g(i_in, i); 
			cout << "|";
			Alias_o(i_in, i);
			cout << " 0|" << endl;
		}
	}
	for (; i_in < number+1; i_in++)
	{
		cout << "| " << i_in << " | ";
		if (i_in < 128) cout << "0";
		Fixed_Variable(i_in, i);
		cout << " |";
		Alias_g(i_in, i); 
		cout << "|";
		Alias_o(i_in, i);
		cout << " 0|" << endl;
	}
	return 0;
}
