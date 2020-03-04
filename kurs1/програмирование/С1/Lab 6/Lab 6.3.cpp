#include <stdlib.h>
#include <stdio.h>

int main()
{
	int N = 20, i, a = 0, b = 10;
	float  M[N];
	//zapolnenie
	for (i = 0; i < N; i++)
	{
		M[i] = (float)rand()*(b-a)/RAND_MAX + a;
	}

	//vivod
	for (i = 0; i < N; i++)
	{
		printf("M[%d] = %f \n", i, M[i]);
	}
	
	printf("\n"); //minus stroka
	
	//poisk
	for (i = 0; i < N; i++)
	{
		if(M[i] > M[i-1] and M[i] > M[i+1])
		printf("Chislo bolshe sosediy \nM[%d] = %f \n\n", i, M[i]);
	}
	
	system("PAUSE");
	return 0;
}
