#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int main()
{
	int N, i, j;
	printf("Input N: ");
	scanf("%d",&N);
	
	float A[N][N], D[N];
	srand(time(0));
	
	//zapolnenie matrix
	printf("\n Matrix do deleniya: \n");
	for (i = 1; i <= N; i++)
	{
		printf("\n");
		for (j = 1; j <= N; j++)
		{
			A[i][j] = (float)rand()/RAND_MAX;
			printf(" [%d][%d] = %f ", i, j, A[i][j]);
		}
	}
	//poisk summi stroki
	for (i = 0; i <= N; i++)
	{
		D[i] = 0;
		printf("\n");
		for (j = 1; j <= N; j++)
		{
			D[i] += A[i][j];
		}
		printf("Summa stroki %d = %f", i, D[i]);
	}
	//delenie everyone
	printf("\n Matrix posle deleniya: \n");
	for (i = 1; i <= N; i++)
	{
		printf("\n");
		
		for (j = 1; j <= N; j++)
		{
			A[i][j] /= D[i];
			printf(" [%d][%d] = %f ", i, j, A[i][j]);
		}
	}
			printf("\n");
	system("PAUSE");
    return 0;
}
