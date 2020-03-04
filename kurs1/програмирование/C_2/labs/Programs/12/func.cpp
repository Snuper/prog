#include <stdio.h>
#include <ctime>
#include <algorithm>

extern int N;
using namespace std;

template <typename T>
void BubbleSort(T *A)
{
	bool k;
	do
	{
		k = false;
		for(int i = 1; i < N; i++)
		{
			if(A[i] < A[i-1])
			{
				swap(A[i], A[i-1]);
				k = true;
			}
		}
	}while(k);
}

template <typename T>
void ShakerSort (T *A)
{	
	int L=0,R=N-1,i,K=N,temp;
	do
	{
		for(i=L;i<R;i++){
		if(A[i]>A[i+1])
		{
			temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
	}
	R--;

	for(i=R;i>L;i--)
		{
			if(A[i]<A[i-1])
			{
				temp=A[i];
				A[i]=A[i-1];
				A[i-1]=temp;
			}
		}
	L++;
	}
	while(L<R);
}

template <typename T>
void SelectSort(T *A)
{
	for( int i = 0; i < N; i++)
	{
		bool flag = false;
		int small = i;
		for(int j = i+1; j < N; j++)
		{
			if(A[j] < A[small])
			{
				small = j;
				flag = true;
			}
			if(flag)
			{
				swap(A[i],A[small]);
			}
		}
	}
}

template <typename T>
void InsertSort(T *A)
{
	for(int i = 1; i < N; i++)
	{
		T temp;
		temp = A[i];
		int j;
		for(j = i; j > 0 and A[j-1]; j--)
			A[j] = A[j-1];
		A[j] = temp;
	}	
}

float timer(int *A, int name)
{
	float start = clock();
	switch(name)
	{
		case 0:
			{
				SelectSort(A);
				break;
			}
		case 1:
			{
				BubbleSort(A);
				break;
			}
		case 2:
			{
				ShakerSort(A);
				break;
			}
		case 3:
			{
				InsertSort(A);
				break;
			}
	}
	float end = clock();
	float need = (end - start)/1000;
	return need;
}

float timer(float *B, int name)
{
	float start = clock();
	switch(name)
	{
		case 0:
			{
				SelectSort(B);
				break;
			}
		case 1:
			{
				BubbleSort(B);
				break; 
			}
		case 2:
			{
				ShakerSort(B);
				break;
			}
		case 3:
			{
				InsertSort(B);
				break;
			}
	}
	float end = clock();
	float need = (end - start)/1000;
	return need;
}

