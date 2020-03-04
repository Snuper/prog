#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int const st = 10;
int const sto = 20;

int main()
{
	
	
	int i, j, A[st][sto], temp;
	printf("Matrica do perestanovok:\n");
	for (i = 0; i < st; i++)
	{
		printf("\n");
		for (j = 0; j < sto; j++)
		{
			A[i][j] = rand()%100;
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
  }

	}
	//perestanovka
	for (i = 0; i < st; i += 2)
	{
		for (j = 0; j < sto; j++)
		{
			temp = A[i][j];
			A[i][j] = A[i+1][j];
			A[i+1][j] = temp;
		}
	}
	
	
	printf("\nMatrica posle perestanovok:\n");
		for (i = 0; i < st; i++)
	{
		printf("\n");
		for (j = 0; j < sto; j++)
		{
			printf("A[%d][%d] = %d\n", i, j, A[i][j]);
		}

	}
	system("PAUSE");
	return 0;
	
}
