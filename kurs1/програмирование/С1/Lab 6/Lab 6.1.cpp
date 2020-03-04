#include <stdlib.h>
#include <stdio.h>

const int N = 20;
int random (int N) 	//random
{
		return rand() % N;
}
	
	int main()
{
	int i, M[N], a = -10, b = 10;

	
	
	for( i = 0; i < N; i++ )
	{
		M[i] = random(b - a + 1) + a;
		printf("M[%d] = %d \n ",i ,M[i]);
	}
	
	for( i = 0; i < N; i++ ) //++
	{
		if (M[i] >= 0)
		{
		printf("++M[%d] = %d \n ",i ,M[i]);
		}
	}

	for( i = 0; i < N; i++ ) //--
	{
		if (M[i] < 0)
		{
		printf("--M[%d] = %d \n ",i ,M[i]);
		}
	}
	system("PAUSE");
	return 0;
}


