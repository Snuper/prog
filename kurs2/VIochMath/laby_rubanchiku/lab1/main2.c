#include <stdio.h>

#define size 3

float A[size * size][size * size + 1];

float mymod(float num)
{
	if (num < 0)
		num *= (-1);
	return num;
}

void printmatrix()
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 1 + size; j++)
		{
			if (j == size)
				printf("   = ");
			printf("%7.2f\t", A[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	FILE *f;
	int n, i, j, k, x;
	float B[size * size + 1], max, posledn, z;
	f = fopen("Matrix1.txt", "r");
	n = size + 1;
	for (i = 0; i < size; i++)
		for (j = 0; j < n; j++)
			fscanf(f, "\t%f", &A[i][j]);
	fclose(f);
	printf("Входная матрица:\n");
	printmatrix();


	for (k = 0; k < size - 1; k++)
	{
		x = k;
		max = A[k][k];
		for (j = k; j < size; j++)
			if (mymod(A[j][k]) > max)
				x = j;
		if (k != x)
		{
			printf("%d<=>%d\n", k + 1, x + 1);
			for (i = 0; i < n; i++)
			{
				B[i] = A[k][i];
				A[k][i] = A[x][i];
				A[x][i] = B[i];
			}
		}
		else
			printf("#Пропуск\n");
		for (i = k + 1; i < size; i++)
		{
			z = A[i][k] / A[k][k];
			for (j = k; j < n; j++)
				B[j] = A[k][j] * z;
			for (j = k; j < n; j++)
			{
				A[i][j] -= B[j];
			}
		}
		printmatrix();
	}
	for (i = 0; i < n; i++)
		B[i] = 0;
	for (k = size - 1; k >= 0; k--)
	{
		posledn = A[k][n - 1];
		for (i = (n - 2); i > k; i--)
			posledn = (posledn - (A[k][i] * B[i]));
		B[i] = posledn / A[k][k];
	}
	int r = 1;
	for (i = 0; i < size; ++i)
		r *= A[i][i];
	if (r)
	{
		printf("Ответ:\n");
		for (i = 0; i < size; i++)
			printf("%c = %2.2f;  ", 'A' + i, B[i]);
		printf("\n");
	}
	else
	{
		printf("СЛАУ без решения\n");
	}
	return (0);
}
