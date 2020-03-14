#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const int size = 3, eps = 10000;

double A[size][size + 1] = 
{
	{5, -1, 2, 3},
    {-2, -10, 3, -4},
    {1, 2, 5, 12}
};

double B[size];

void printMatrix()
{
	cout << endl << "------Matrix------" << endl;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size + 1; j++)
		{
			cout << " " << round(A[i][j]*eps)/eps << " ";
		}
		cout << endl;
	}
	cout << "------Matrix------" << endl;
}

int n_shagov(double C, double B)
{
	double i, j;	
	int k;
	
	i = (1 - C) / (eps * B);
	i = log(i);
	i /= log(C);
	k = (int)ceil(i+1);
	return k;
}

int main(void)
{
	int i, j, shag;
	double mnozhitel, C_max, B_max = 0, temp = 0;
	
	printMatrix();
	
	for(i = 0; i < size; i++)
	{
		mnozhitel = A[i][i];
		A[i][i] = 0;
		for(j = 0; j < size + 1; j++) A[i][j] /= mnozhitel;
		printMatrix();
	}
	
	for(i = 0; i < size; i++)
	{
		for(j = 0, temp = 0; j < size; j++)
		{
			if(A[i][j] < 0) temp += A[i][j] * -1;
			else temp += A[i][j];
		}
		if(B_max < A[i][j] or B_max < (A[i][j] * -1))
		if(A[i][j] < 0) B_max = A[i][j] * -1;
		else B_max = A[i][j];
		if(temp > C_max) C_max = temp;
	}
	cout << endl << "B = " << B_max << " C = " << C_max << endl;
	
	shag = n_shagov(C_max, B_max);
	cout << endl << "kolvo shagov = " << shag << endl;
	
	for(int temp_shag = 1; temp_shag < shag+1; temp_shag++)
	{
		cout << endl << "Shag: " << temp_shag << endl;
		for(i = 0; i < size; i++)
		{
			for(j = 0, temp = 0; j < size; j++) temp += A[i][j] * B[j];
			B[i] = A[i][size] - temp;
			cout << "x" << i + 1 << " = " << round(B[i]*eps)/eps << endl;
		}
	}
}
