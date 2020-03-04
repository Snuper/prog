#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int main()
{	
    srand(time(0));
	int i, k, l = 0, N = 20;
	float a = -10, b = 10, A[N];
	
	for (i = 0; i < N; i++) // random chisla ot a do b
	{
		A[i] = (float)rand()*(b-a)/RAND_MAX + a;
		printf("A[%d] = %f\n", i, A[i]);
		if(A[i] > 0) // Kol-vo bolshe 0
		{
			l++;
		}
	}
	float B[l];
	i = -1;
	for (k = 0; k < l; k++)
	{
		i++;
		while (i < N)
		{
			if(A[i] > 0)
			{
				B[k] = A[i];
				printf("B[%d] = %f\n", k, B[k]);
				break;
			}
		i++;
		}
		
	}
	system("PAUSE");
	return 0;
}
