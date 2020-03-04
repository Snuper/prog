#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

const int eps = 1000, size = 3;

float matrix [size][size + 1], B[size], C[size][size];

void printmatrix()
{
	int i, j;
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= size; j++)
		{
			if (j == size) printf("   = ");
			printf("%7.3f\t", matrix[i][j]);
		}
		printf("\n");
	}
}

float mymode(float a)
{
	if (a < 0) a*= -1;
		
	return a;
}

float maximumB()
{	
	float max = mymode(B[0]);
	
	for (int i = 1; i < size; i++ )
	{
		if (mymode(B[i]) > max) max = mymode(B[i]);
	}
	
	return max;
}

float maximumC()
{	
	float max = 0, temp = 0;
	int i,j;
	
	for (i = 0; i< size; i++) max += mymode(C[0][i]);	
	
	for ( i = 1; i < size; i++ )
	{	
		temp = 0;
		for ( j = 0; j < size; j++) temp+=mymode(C[i][j]);
		if(max < temp) max = temp;
	}
	
	return max;
}

int kolvoshagov(float A, float B)
{	
	float i,j;	
	int k;
	
	i = (1-A)/(eps*B);
	i = logf(i);
	j = logf(A);
	i = i / j;
	k = (int)ceil(i+1);
	
	return k;	
}

int main (void)
{
	
	float tempest[size], result[size], last[size];
	int k, i, j, n, temp;
	FILE* f;
	float Cc, Bb;
	
	f = fopen("Matrix1.txt", "r");
	for (i = 0; i < size; i++) for (j = 0; j < size + 1; j++) fscanf(f, "\t%f", &matrix[i][j]);
	fclose(f);
	printf("Start matrix:\n");
	printmatrix();
	
	for ( k = 0; k < size; k++) cout << k + 1 << " /: " << matrix[k][k] << endl;
	
	for ( k = 0; k < size; k++ )
	{
		temp = matrix[k][k];
		for (j = 0; j < size + 1; j++ )
		{
			matrix[k][j] = matrix[k][j] / temp;
		}
	}
	
	cout << "Prepare" << endl;
	
	printmatrix();
	
	for (i = 0; i < size; i++ )
	{
		for (j = 0; j < size; j++)
		{
			C[i][j] = matrix[i][j];
			if (i == j) C[i][j] = 0;
		}
	}
	
	for (i = 0; i < size; i++) B[i] = matrix[i][size];
	
	cout << "C matrix" << endl;
	
	for (i = 0; i < size; i++ )
	{
		for (j = 0; j < size; j++)
		{
			printf("%7.3f\t", C[i][j]);
		}
		cout << endl;
	}
	
	cout << "B matrix" << endl;
	
	for (i = 0; i < size; i++ )
	{
		printf("%7.3f\n", B[i]);
	}
	
	int step = 1;

	
	for (i = 0; i < size; i++)
	{
		tempest[i] = 0;
	}
	
	Bb = maximumB();
	Cc = maximumC();
	
	n = kolvoshagov(Cc,Bb);
	
	cout << "||C|| = " << Cc << endl;
	cout << "||B|| = " << Bb << endl;
	cout << "N = " << n << endl;
	
	while (step <= n)
	{
		for(i = 0 ; i < size; i++ ) last[i] = tempest[i];
		
		cout << "Step " << step << endl;
		
		for (i = 0; i < size; i++) result[i] = 0;
		
		for (i = 0; i < size; i++)
		{
			for ( j = 0; j < size; j++)
			{
				cout << "vector["<<i << "] += " << C[i][j] << " * " << tempest[j] << " = " << round((result[i]+C[i][j]*tempest[j])*eps)/eps << endl;
				result[i] += round(C[i][j]*tempest[j]*eps)/eps;
			}
		}
		
		cout << "---------------------------" << endl;
		
		for (i = 0; i < size; i++)
		{
			cout << "vector["<< i << "] = " << B[i] << " - " << result[i] << " = " << round((B[i] - result[i]) *eps)/eps << endl;
			tempest[i] = round((B[i] - result[i]) *eps)/eps; 
		}
		step++;
		cout << "___________________________" << endl;
	}
	return 0;
}
