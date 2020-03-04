#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int main()
{
	srand(time(0));
	int n = 15, A[n], i, j, k = 0;
	for(i = 0; i < n; i++)
	{
		A[i] = (rand()) % 5 ;
		printf("A[%d] = %d\n", i, A[i]);
	}
	printf("massive bez povtorov: \n");
	
	for(i = 0; i < n; i++)
	{
		j = 0;
		/*if (i == 0)
		{
			printf("A[%d] = %d\n",i ,A[i]);
		}*/

		while (j < i)
		{
			if(A[i] == A[j])
			{
				k++;
			}
			j++;
		}
		if (k == 0 )
		{
			printf("A[%d] = %d\n",i ,A[i]);
		}
		k = 0;
		
	}

	system("PAUSE");
	 return 0;
}

