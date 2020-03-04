#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <conio.h>

int random (int N) { return rand()%N; }
using namespace std;
void FillInc (int A[], int n); 
void FillDec (int A[], int n); 
void FillRand (int A[], int n); 
void CheckSum (int A[], int n); 
void RunNumber (int A[], int n); 
void PrintMas (int A[], int n); 
void InsertSort (int A[], int n);
void ShellSort (int A[], int n);

void FunkDec (int n, int i);
void FunkInc (int n, int i);
void FunkRand (int n, int i);

void TablResult (int n);



int Mprak = 0, Cprak = 0;


int K_Sort (int n);
int increment (long inc,long n);


main() {
	int n = 10, A[n];
	srand(time(NULL));
	FillRand (A, n);
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	printf ("M(teor)=%d, C(teor)=%d \n", ((n*n-n)/2)+2*n-2, (n*n-n)/2); 
	ShellSort (A, n);
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	printf ("M(fact)=%d, C(fact)=%d \n", Mprak, Cprak);
	printf ("\n\n");
	TablResult (100);
	cout<<endl;
	
	
	printf ("\n\n");
	system("PAUSE");
	return 0;
}

void FillInc (int A[], int n) 
{
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = i+1;
}

void FillDec (int A[], int n) 
{
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = n-i;
}

void FillRand (int A[], int n) 
{
	int i, a = 0, b = 10;
	for ( i = 0; i < n; i ++ ) A[i] = random(b-a+1)+a;
}

void CheckSum (int A[], int n) 
{
	int i, s;
	for (s=0, i=0; i < n; i++) s+=A[i];
	printf ("\n CheckSum=%d", s); 
}

void RunNumber (int A[], int n) 
{
	int i, c;
	for (c = 1, i = 1; i < n; i++) if (A[i-1]>A[i]) c++;
	printf ("\n RunNumber=%d\n", c); 
}

void PrintMas (int A[], int n) 
{
	int i;
	for (i = 0; i < n; i++) printf ("%d ", A[i]);
}

void TablResult (int n) 
{
	int i;
	cout<<  " _________________________________"<<endl;
	cout<<  "|  n  | K-Sort | Insert |  Shell |"<<endl;
	cout<<  "|-----|--------|--------|--------|";
	for (; n<=500; n+=100) 
	{
		printf ("\n| %3d |", n);
		printf ("   %2.d   |", K_Sort(n));
		for (i=0; i<2; i++) 
		{
			FunkRand (n, i);
			printf (" %6.d |", Cprak+Mprak);
		}
		cout<<endl;
		cout<<"|-----|--------|--------|--------|";
	}
}
void FunkDec (int n, int i) 
{
	Mprak=0; Cprak=0;
	int A[n];
	FillDec (A, n);
	switch (i) 
	{
		case 0: InsertSort (A, n);
			break;
		case 1: ShellSort (A, n);
			break;
	}
}

void FunkInc (int n, int i) 
{
	Mprak=0; Cprak=0;
	int A[n];
	FillInc (A, n);
	switch (i) 
	{
		case 0: InsertSort (A, n);
			break;
		case 1: ShellSort (A, n);
			break;
	}
}

void FunkRand (int n, int i)
{
	Mprak=0; Cprak=0;
	int A[n];
	FillRand (A, n);
	switch (i) 
	{
		case 0: InsertSort (A, n);
			break;
		case 1: ShellSort (A, n);
			break;
	}
}

void InsertSort (int A[], int n) 
{
	Mprak=0, Cprak=0;
	int i,t,j;
	for(i=1; i<n; i++) 
	{
		Mprak++;
		t=A[i];
		j=i-1;
		while(j>=0 && (Cprak++, t<A[j])) 
		{ 
			Mprak++;
			A[j+1]=A[j];
			j=j-1;
		}
		Mprak++;
		A[j+1]=t;
	}
}

void ShellSort (int A[], int n) 
{
	int i, j, k, l, t;
	l=K_Sort(n);
	int K[l];
	K[0]=1;
	for (i=1; i<l; i++) 
		K[i]=K[i-1]*2+1;
	for (; l>0; l--) 
	{
		k=K[l-1];
		for (i=k; i<n; i++) 
		{
			t=A[i]; Mprak++;
			j=i-k;
			while (j>=0 && (Cprak++, t<A[j])) 
			{
				A[j+k]=A[j];
				Mprak++;
				j-=k;
			}
			A[j+k]=t; Mprak++;
		}
	}
}
int K_Sort (int n)
{
	int i=2, j=0;
	while (i<=n) 
	{
		i*=2;
		j++;
	}
	j--;
	return j;
}

