#include <stdlib.h>
#include <stdio.h>
#include <ctime>


int main()
{
	int N = 40, n = 20, C[n], D[n], E[N], j, c, i, d, k, s;
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		C[i] = rand()%21;
		printf("Massiv C[%d] = %d\n", i, C[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		D[i] = rand()%21;
		printf("Massiv D[%d] = %d\n", i, D[i]);
	}
	printf("\n");
	
	
	for(i = 0; i < n-1; i++)
	{
		for(j = n-2; j >= i; j--)
		{
			if(C[j]>C[j+1]) //mas C sort
			{
				c = C[j];
				C[j] = C[j + 1];
				C[j+1] = c;
			}
	
			if(D[j] > D[j+1]) //mas D sort
			{
				c = D[j];
				D[j] = D[j + 1];
				D[j+1] = c;
			}
			
		}
	}
	s = 0;
	d = 0;
	for(i = 0; i < N ; i++) //sliyanie
	{
		while(i < N )
		{
			if (C[s] < D[d] and s < n)
			{
				E[i] = C[s];
				s++;
				break;
				
			}
			else if (d < n)
			{
				E[i] = D[d];
				if (d < n and d < n)

				d++;
				break;
			}	
			else if (s < n)
			{
				E[i] = C[s];
				s++;
				break;
			}
		}
	printf("Full massive E[%d] = %d \n", i, E[i]);
	}
	system("PAUSE");
	return 0;
}
