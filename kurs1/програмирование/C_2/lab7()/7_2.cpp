#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
int N;
int Sum (int **Arr, int n, int i)
{
	int sum = 0;
	for (int j = 0; j < n; j ++)
	{
		if(j != 0) 
		sum += Arr[i][j];
	}
	return sum;
}

main()
{
	srand(time(NULL));
	int M, N, i, j;
	cout << "M = ";
	cin >> M;
	cout << endl;
	int ** A;
	A = new int *[M];
	if (A == NULL)
    {
		puts("Error");
     	return 1;
    }
    for (i = 0; i < M; i ++)
    {
    	N = 1 + rand() % 15;
    	A[i] = new int[N + 1];
    	for (j = 0; j < N + 1; j ++)
    	{
    		if (j == 0) A[i][j] = N ;
    		else A[i][j] = rand() % 30;
    		cout << setw(4) << A[i][j];
		}
		cout << setw(75 - N * 4 - 10) <<"Sum["<< i <<"] = "<< Sum(A, N + 1, i);
		cout << endl;
	}
}
