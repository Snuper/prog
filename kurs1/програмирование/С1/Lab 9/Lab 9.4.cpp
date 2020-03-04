#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int const N = 3;

int main()
{
	int M[N][N], i, j, l = 1, ST[N], STO[N], o;
	srand(time(0));
	
	while (l)
	{
		
	//zapolnyem massiv 
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			M[i][j] = rand()%10;
		}
	}
		//sum strok
		for(i = 0; i < N; i++)
		{
			ST[i] = 0;
			for(j = 0; j < N; j++)
			{
				ST[i] += M[i][j];
			}
		}
		//sum stolbc
		for(j = 0; j < N; j++)
		{
			STO[j] = 0;
			for(i = 0; i < N; i++)
			{
				STO[j] += M[i][j];
			}
		}
		//sravnenie
		if(STO[0] == STO[1] and STO[1] == STO[2] and  ST[0] == ST[1] and ST[1] == ST[2])
		{
			l = 0;
		}
		else
		{
			o++;
		}
	}
	//vivod na ecran magic
	for(i = 0; i < N; i++)
	{
		printf("\n");
		for(j = 0; j < N; j++)
		{
			printf("[%d][%d] = %.2d ", i, j, M[i][j]);
		}
	}	
	printf("\nPopitok: %d\n",o);
system("PAUSE");
return 0;
}
