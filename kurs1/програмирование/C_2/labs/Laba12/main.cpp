#include "func.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
int N = 50000;

char NameSort[4][20] =
{
	"BubbleSort",
	"QuickSort",
	"SelectSort",
	"insertSort",
};

int main()
{
	srand(time(0));
	cout << "Int mass: " << endl;
	int A[N];
	for(int j = 0; j < 4; j++)
	{
		for(int i = 0; i < N; i++)
		{
			A[i] = rand()%N;
		}

		cout << NameSort[j] << " worked " << timer(A, j) << " sec. " << endl;
	}
	cout << "Float mass: " << endl;
 	float B[N];
	for(int j = 0; j < 4; j++)
	{
		for(int i = 0; i < N; i++)
		{
			B[i] = (float)rand()/RAND_MAX;
		}
		cout << NameSort[j] << " worked " << timer(B, j) << " sec. " << endl;
	}
	system("PAUSE");
	return 0;
}
