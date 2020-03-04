#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <graphics.h>

using namespace std;
void FillInc (int A[], int n); 
void FillDec (int A[], int n); 
void FillRand (int A[], int n); 
void CheckSum (int A[], int n); 
void RunNumber (int A[], int n); 
void PrintMas (int A[], int n); 
void ShellSort (int A[], int n);
void FunkDec (int n, int i);
void FunkInc (int n, int i);
void FunkRand (int n, int i);
void TablResult (int n);
void BSearch1 (int A[], int n, int X);
void BSearch2 (int A[], int n, int X);

int Mprak = 0, Cprak = 0;
int K_Sort (int n);
int *a1,*a2;



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
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = rand()%10;
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
	cout<< " ____________________________"<<endl;
	cout<<("|  n   | BSearch1 | BSearch2 |")<<endl;
	cout<< "|------|----------|----------|";
	for (; n<=1000; n+=100) 
	{
		printf ("\n| %4d |", n);
		for (i=0; i<2; i++) 
		{
			FunkRand (n, i);
			printf (" %8.d |", Cprak);
		}
		cout<<endl;
		cout<< "|------|----------|----------|";
	}
}

void FunkDec (int n, int i) 
{
	Mprak=0; Cprak=0;
	int A[n], X=3;
	FillDec (A, n);
	ShellSort (A, n);
	switch (i) 
	{
		case 0: {;
		BSearch1 (A, n, X);
			break; }
		case 1: {;
		BSearch2 (A, n, X);
			break;	}
	}
}

void FunkInc (int n, int i) 
{
	Mprak=0; Cprak=0;
	int A[n], X;
	FillInc (A, n);
	ShellSort (A, n);
	switch (i) 
	{
		case 0: {
		BSearch1 (A, n, X);
			break; }
		case 1: {
		BSearch2 (A, n, X);
			break;	}
	}
}

void FunkRand (int n, int i)
{
	Mprak=0; Cprak=0;
	int A[n], X;
	FillRand (A, n);
	ShellSort (A, n);
	switch (i) 
	{
		case 0: {
		BSearch1 (A, n, X);
			break; }
		case 1: {
		BSearch2 (A, n, X);
			break;	}
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

void BSearch1 (int A[], int n, int X)
{
	Cprak=0;
	int L=1, R=n, Find=0, m;
	while (L<=R)
	{
		m=(int)((L+R)/2);
		Cprak++;
		if (A[m]==X) 
		{
		Find=1;
		break;
		} 
		Cprak++;
		if (A[m]<X) L=m+1;
		else R=m-1;
	}
}
int BSearch11 (int A[], int n, int X)
{
	Cprak=0;
	int L=1, R=n, Find=0, m;
	while (L<=R)
	{
		m=(int)((L+R)/2);
		Cprak++;
		if (A[m]==X) 
		{
		Find=1;
		break;
		} 
		Cprak++;
		if (A[m]<X) L=m+1;
		else R=m-1;
	}
	return Cprak;
}


void BSearch2 (int A[], int n, int X)
{
	Cprak=0;
	int L=1, R=n, Find=0, m;
	while (L<R)
	{
		m=(int)((L+R)/2);
		Cprak++;
		if (A[m] < X) L=m+1;
		else R=m;
	}
	Cprak++;
	if (A[R]=X) Find = 1;
	else Find = 0;
}
int BSearch22 (int A[], int n, int X)
{
	Cprak=0;
	int L=1, R=n, Find=0, m;
	while (L<R)
	{
		m=(int)((L+R)/2);
		Cprak++;
		if (A[m] < X) L=m+1;
		else R=m;
	}
	Cprak++;
	if (A[R]=X) Find = 1;
	else Find = 0;
	return Cprak;
}
void grafic(int a_1[],int a_2[]){
	initwindow (800, 800);
	char in[10];
	setcolor(WHITE); 
	moveto(50,20); 
	lineto(50, 780); 
	moveto(50,780);
	lineto(780,780);
	line(780,780,770,770);
	line(780,780,770,790);
    outtextxy ( 770, 750, (char *)"n" );
    line(50,20,40,30);
    line(50,20,60,30);
    outtextxy ( 70, 25, (char *)"C (fact)" );
    outtextxy ( 40, 775, (char *)"0" );
    line(150,785,150,775);
    outtextxy ( 135, 760, (char *)"100" );
	line(250,785,250,775);
	outtextxy ( 235, 760, (char *)"200" );
	line(350,785,350,775);
	outtextxy ( 335, 760, (char *)"300" );
	line(450,785,450,775);
	outtextxy ( 435, 760, (char *)"400" );
    line(550,785,550,775);
	outtextxy ( 535, 760, (char *)"500" );
	line(650,785,650,775);
	outtextxy ( 635, 760, (char *)"600" );
	line(750,785,750,775);
	outtextxy ( 735, 760, (char *)"700" );

	
	setcolor(4);
    moveto(50,780);
    for(int n = 100, j = 0; n <=1000, j <10; n += 100, j ++){
		lineto(n, (770-5*a_1[j]));
    }
    outtextxy ( 670, 750, (char *)"BSearch1" );	
    setcolor(6);
    moveto(50,780);
    for(int n = 100, j = 0; n <=1000, j <10; n += 100, j ++){
	lineto(n, (770-5*a_2[j]));
    }
	outtextxy ( 730, 690, (char *)"BSearch2" );	
  getch();
  closegraph();
}
main() {
	int n = 10, A[n], X=3;
	srand(time(NULL));
	int a_1 [10];
	int a_2 [10];
	srand(time(NULL));
	for (int n = 100, j = 0; n <=1000, j < 10; n += 100, j ++) {
    	a1 = new int [n+1]; // rand
    	a2 = new int [n+1]; //inc
    	FillRand(a1, n);
    	FillRand(a2, n);
    	ShellSort(a1,n);
    	ShellSort(a2,n);
    	a_1[j]=BSearch11 (a1, n, X);
    	a_2[j]=BSearch22 (a2, n, X);
    	delete a1;
    	delete a2;
    }
	FillRand (A, n);
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	ShellSort (A, n);
	printf ("\n"); 
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	printf ("\n");
	BSearch1 (A, n, X);
	printf ("C1(prak)=%d \n", Cprak);
	BSearch2 (A, n, X);
	printf ("C2(prak)=%d \n", Cprak);
	
	TablResult(100);
	printf ("\n\n");
	grafic(a_1,a_2);
	system("PAUSE");
	return 0;
}
