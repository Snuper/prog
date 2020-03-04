#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <conio.h>
int mp=0, cp=0;
int *a1,*a2;
using namespace std;
void FillInc (int A[], int n);
void FillDec (int A[], int n);
void FillRand (int A[], int n);
void CheckSum (int A[], int n);
void RunNumber (int A[], int n);
void PrintMas (int A[], int n);
void PrintMasRevers (int A[], int n);
void Swap (int &x, int &y);
void ResultOld (int n);
void ResultTabl (int n);
void HeapSort (int A[], int n);
void WorkDec (int n, int i);
void WorkInc (int n, int i);
void WorkRand (int n, int i);
void Heap (int A[], int l, int r);

main() {
	int a_1 [10];
	int a_2 [10];
	srand(time(NULL));
	for (int n = 100, j = 0; n <1001, j < 10; n += 100, j ++) {
    	a1 = new int [n+1]; // rand
    	a2 = new int [n+1]; //inc
    	FillRand(a1, n);
    	FillRand(a2, n);
    	HeapSort(a2,n);
    	a_1[j]=a1[n];
    	a_2[j]=a2[n];
    	delete a1;
    	delete a2;
    }
	int n, m, x;
	printf ("Input N: ");
	scanf("%d", &n);
	int A[n];
	FillRand (A, n);
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	HeapSort (A, n);
	PrintMasRevers (A, n);
	CheckSum (A, n);
	ResultOld (n);
	printf ("\n\n");
	ResultTabl (100);
	printf ("\n\n");
	system("PAUSE");
	return 0;
}

void FillInc (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = i+1;
}

void FillDec (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = n-i;
}

void FillRand (int A[], int n) {
	int i, a=0, b=2*n;
	srand(time(NULL));
	for ( i = 0; i < n; i ++ ) A[i] = rand()%10;;
}

void CheckSum (int A[], int n) {
	int i, s;
	for (s=0, i=0; i< n; i++) s+=A[i];
	printf ("\n CheckSum=%d", s);
}

void RunNumber (int A[], int n) {
	int i, c;
	for (c = 1, i = 1; i < n; i++) if (A[i-1]>A[i]) c++;
	printf ("\n RunNumber=%d\n", c);
}

void PrintMas (int A[], int n) {
	int i;
	for (i = 0; i < n; i++) printf ("%d ", A[i]);
}

void PrintMasRevers (int A[], int n) {
	int i;
	for (i=n-1; i>=0; i--) {
		printf ("%d ", A[i]);
	}
}

void Swap (int &x, int &y) {
	int t=x; x=y; y=t;
}

void ResultOld (int n) {
	printf ("\nC(teor)=%.3f, M(teor)=%.3f", 2*n*log2(n)+n+2, n*log2(n)+6.5*n-4);
	//printf ("\nC(fact)=%d, M(fact)=%d, T(p)=%d", cp, mp, cp+mp);
}

int Result (int n) {
	int ct=(n*n-n)/2, mt=ct+2*n-2;
	return ct+mt;
}


void Heap (int A[], int l, int r) {
	int i=l, j, x=A[l];
	mp++;
	while (1) {
		j=2*i;
		if (j>r) break;
		if (j<r && (cp++, A[j+1]<=A[j])) j++;
		if (cp++, x<=A[j]) break;
		A[i]=A[j];
		mp++;
		i=j;
	}
	A[i]=x;
	mp++;
}


void ResultTabl (int n) {
	int i;
	cout<< " __________________________________"<<endl;
	cout<< "|  n   |   HeapSort (M(f)+C(f))   |"<<endl;
	cout<< "|      |--------------------------|"<<endl;
	cout<< "|      |   Inc  |   Dec  |  Rand  |"<<endl;
	cout<< "|------|--------|--------|--------|";
	
	for (; n<=500; n+=100) {
		printf ("\n| %4d |", n);
		WorkDec (n, 0);
		printf (" %6.d |", cp+mp);
		WorkInc (n, 0);
		printf (" %6.d |", cp+mp);
		WorkRand (n, 0);
		printf (" %6.d |", cp+mp);
		cout<<endl;
		cout<< "|------|--------|--------|--------|";
	}

}

void HeapSort (int A[], int n) {
	int l=n/2, r=n;
	while (l+1>0) {
		Heap (A, l, r);
		l--;
	}
	while (r>1) {
		Swap (A[0], A[r-1]);
		mp+=3;
		r--;
		Heap (A, 0, r-1);
	}
	A[n]=mp+cp;
}

void WorkDec (int n, int i) {
	mp=0; cp=0;
	int A[n];
	FillDec (A, n);
	switch (i) {
		case 0: HeapSort (A, n);
			break;
	}
}

void WorkInc (int n, int i) {
	mp=0; cp=0;
	int A[n];
	FillInc (A, n);
	switch (i) {
		case 0: HeapSort (A, n);
			break;
	}
}

void WorkRand (int n, int i) {
	mp=0; cp=0;
	int A[n];
	FillRand (A, n);
	switch (i) {
		case 0: HeapSort (A, n);
			break;
	}
}
