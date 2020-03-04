#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <iostream>
int random (int N) { return rand()%N; }
using namespace std;
void FillInc (int A[], int n);
void FillDec (int A[], int n); 
void FillRand (int A[], int n);
int CheckSum (int A[], int n); 
int RunNumber (int A[], int n); 
void PrintMas (int A[], int n); 
void BubbleSort (int A[], int n);
void FunkDec (int n, int i);
void FunkInc (int n, int i);
void FunkRand (int n, int i);
void TablResult (int n);

int *A;
int Mprak = 0, Cprak = 0;

main() 
{
 int n,x,y;
    cout<<"Input N: ";
    cin>>n;
    A = new int [n];
    srand(time(NULL));
    
    while (1){
    int ch = getch();
    switch(ch){
             case 49: cout<<"Sum = "<<CheckSum(A, n)<<endl<<"Series: "<<RunNumber(A, n)
             <<endl; break;  //1
             case 50: FillRand(A, n); break; //2
             case 51: FillInc(A, n); break; //3
             case 52: FillDec(A, n); break; //4
             case 53: PrintMas(A, n); break; //5
             case 54: cout<<"Fact: "<<endl<<"M = "<<Mprak<<endl<<"C = "<<Cprak<<endl; break; //6
             case 55: cout<<"Theor: "<<endl<<"M = "<<3 * (n - 1)<<endl<<"C = "<<(n * n - n) / 2<<endl; break; //7
             case 56: BubbleSort(A, n); break; //8
             case 57: TablResult (n); break; //9      
             case 27: exit(0); //esc
             }
    }
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
	int i, a = -20, b = 20;
	srand(time(NULL));
	for ( i = 0; i < n; i ++ ) A[i] = random(b-a+1)+a;
}

int CheckSum (int A[], int n){
     int sum = 0;
     for (int i = 0; i < n; i++)
         sum += A[i];
     return sum;
}

int RunNumber (int A[], int n){
     int sum_ser = 1;
         for (int i = 0; i < n-1; i++)
                 if (A [i] > A[i+1]){
                    sum_ser += 1;
                    }
     return sum_ser;
     }

void PrintMas (int A[], int n){
     for (int i = 0; i < n; i++)
         cout<<A[i]<<" ";
     cout<<endl;
     } 

void BubbleSort (int A[], int n) {
	Mprak=0, Cprak=0;
	int i,j,t;
	for (i = 0; i < n-1; i++) 
	{ 
		for (j=n-1; j>i; j--) 
		{ 
			Cprak++; 
			if (A[j]>A[j-1]) 
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				Mprak+=3; 
			}
		}
	}
}
void TablResult (int n) 
{
	int i;
	printf ("___________________________________________________________________");
	printf ("\n|     n    | M+C (theor) |                M+C (fact)               |");
	printf ("\n|          |             |-----------------------------------------|");
	printf ("\n|          |             |     dec     |     rand    |     inc     |");
	printf ("\n|----------|-------------|-------------|-------------|-------------|");
	for (int n=100; n<=500; n+=100) 
	{
		printf ("\n|    %3d   |", n);
		for (i=0; i<1; i++) 
		{
			printf ("    %6.d   |", (3*(n-1))+((n*n-n)/2));
			FunkDec (n, i);
			printf ("    %6.d   |", Cprak+Mprak);
			FunkRand (n, i);
			printf ("    %6.d   |", Cprak+Mprak);
			FunkInc (n, i);
			printf ("    %6.d   |", Cprak+Mprak);
			
			
			
		}
	} 
	printf ("\n|------------------------------------------------------------------|");
	puts("\n");
}

void FunkDec (int n, int i) 
{
	Mprak=0; Cprak=0;
	int A[n];
	FillDec (A, n);
	switch (i) 
	{
		case 0: BubbleSort (A, n);
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
		case 0: BubbleSort (A, n);
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
		case 0: BubbleSort (A, n);
			break;
	}
}

