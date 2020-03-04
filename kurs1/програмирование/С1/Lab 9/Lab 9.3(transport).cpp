#include <stdlib.h>
#include <stdio.h>
#include <ctime>
int main()
{
	srand(time(0));
	int N, K, i, j; //N - stroka, K - stolbec
	printf("Input razmer matrix stok / stolbcov: ");
	scanf("%d%d",&N, &K);
	
	int M[N][K], T[K][N], choose, t;
	printf("Choose: vvod matrix v konsol = 1, random matrix = 0 \n");
	scanf("%d",&choose);
	if(choose != 0)
	{
		for(i = 1; i < N + 1; i++)
		{
			printf("Input %d stroku:",i);
			for (j = 1; j < K + 1; j++)
			{
				scanf("%d",&M[i][j]);
			}
		}
	}
	else
	{
		//zapolnenie matrix - random
		for(i = 1; i < N + 1; i++)
		{
			printf("\n");
			for(j = 1; j < K + 1; j++)
			{
				M[i][j] = rand() % 10;
				T[i][j] = 0;
				printf(" [%d][%d] = %d ", i, j, M[i][j]);
			}
		}
	}
	
	//transonirovanie
	printf("\nMatrix do/Matrix posle\n");
	for(i = 1; i < N + 1; i++)
	{
		for(j = 1 ; j < K + 1; j++)
		{
			T[j][i] = M[i][j];
		}
	}
	
	
	//vivod transponirovanoy
		for(i = 1; i < K + 1; i++)
	{
		printf("\n");
		for(j = 1; j < N + 1; j++)
		{
			printf(" [%d][%d] = %d ", i, j, T[i][j]);
		}
	}
	
	printf("\n");
	
	system("PAUSE");
	return 0;
}
