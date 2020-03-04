/*
4 2 -1 ] 1
5 3 -2 ] 2
3 2 -2 ] 0  

-1 3 1
*/

//Метод гаусса(Обычный + с выбором ведущего элемента)
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <math.h>

using namespace std;

int main ()
{
	double **matrix;
	double *res;
	int i , j , k , m , n ;
	
	
	cout << "Matrix size ";
	cin >> m;
	
	matrix = new double* [m];
	res = new double[m];
	
	for (i = 0 ; i < m ; i++ )
	{
		matrix[i] = new double[m+1];
	}
	
	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j <= m ; j++ )
		{
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	
	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < m+1 ; j++ )
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "-----------------------" << endl; 
	for ( k = 0 ; k < ( m - 1 ) ; k++ )
	{
		cout << " Test k = " << k << endl;
		for ( i = k+1 ; i < m ; i++ )
		{
			cout << " Test i = " << i << endl;
			for ( j = 0 ; j < m+1 ; j++ )
			{
				matrix[i][j] = matrix[i][j] - ( matrix[i - 1][j] * ( matrix [i][k] / matrix [k][k] ) ); 
				cout << " Test j = " << j << endl;
			}
		}
		cout << endl;
	}
	
	for ( i = 0 ; i < m ; i++ )
	{
		res[i] = 0;
	}
	
	for ( i = m - 1 ; i >= 0 ; i-- )
	{
		n = 0;
		for ( j = m - 2 ; j >= 0 ; j-- )
		{
			n += matrix[i][j];
		}
		res [i] = matrix[i][m - 1] / n;
	}
	
	for ( i = 0 ; i < m ; i++ )
	{
		for ( j = 0 ; j < m+1 ; j++ )
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "------------result-------------" << endl;
	
	for ( i = 0 ; i < m ; i++ ) cout << res[i] << " ";
	
	return 0;
}
