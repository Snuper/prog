#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int const st = 10;
int const sto = 20;

int main()
{
	
	
	int f, i, j, A[st][sto], temp;
	printf("Matrica do perestanovok:\n");
	for (i = 0; i < st; i++)
	{
		printf("\n");
		for (f=0, j = 0; j < sto; f++, j++)
		{
			A[i][j] = rand()%100;
			if (f<sto)
			printf("%d ",A[i][j] ); 
            else
			{
				printf("\n%d ", i, j, A[i][j]);
                f=0;			 
			 } 
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
		for (f=0, j = 0; j < sto; f++, j++)
		{
	if (f<sto)
			printf("%d ",A[i][j] ); 
            else
			{
				printf("\n%d ", i, j, A[i][j]);
                f=0;			 
			 }	
		}

	}
	system("PAUSE");
	return 0;	
}
