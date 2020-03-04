#include "func.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
int N = 50000;

char NameSort[4][20] =
{
	"SelectSort",
	"BubbleSort",
	"ShakerSort",
	"insertSort",
};

int main()
{
	srand(time(0));
	printf("Int:\n");
	int A[N];
	for(int j = 0; j < 4; j++)
	{
		for(int i = 0; i < N; i++)
		{
			A[i] = rand()% N;
		}
		printf("%s: %.3f sec.\n", NameSort[j], timer(A, j));
	}
	printf("Float:\n");
	float B[N];
	for(int j = 0; j < 4; j++)
	{
		for(int i = 0; i < N; i++)
		{
			B[i] = (float)rand()/RAND_MAX;
		}
		printf("%s: %.3f sec.\n", NameSort[j], timer(B, j));
	}
	system("PAUSE");
	return 0;
}
