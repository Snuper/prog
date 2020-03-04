#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <graphics.h>

using namespace std;
void FunkRand (int n, int i);
void FunkInc (int n, int i);
void FunkDec (int n, int i);
void ShakerSort (int A[], int n);
void InsertSort (int A[], int n);
void SelectSort (int A[], int n);
void BubbleSort (int A[], int n);
int *A, *n, i;
int M, C;
int *a1,*a2,*a3,*a4;


void FillInc (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = i+1;
}

void FillDec (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = n-i;
}

void FillRand (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i]= rand() % 50;;
}

void CheckSum (int A[], int n) {
	int i, s;
	for (s=0, i=0; i < n; i++) s+=A[i];
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

void BubbleSort (int A[], int n) {
	M=0, C=0;
	int i,j,t;
	for (i = 0; i < n-1; i++) {
		for (j=n-1; j>i; j--) {
			C++;
			if (A[j]<A[j-1]) {
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				M+=3;
			}
		}
	}
	A[n]=M+C;
}

void TablResult (int n) {
	int i;
	cout<<  " __________________________________________"<<endl;
	cout<<  "|  n  | Select | Bubble | Shaker | Insert |"<<endl;
	cout<<  "|-----|--------|--------|--------|--------|";
	for (; n<=500; n+=100) {
		printf ("\n| %3d |", n);	
		for (i=0; i<4; i++) {
			FunkRand (n, i);
			printf (" %6.d |", M+C);		
		}
		cout<<endl;
		cout<<  "|-----|--------|--------|--------|--------|";
	}
}

void FunkDec (int n, int i) {
	M=0; C=0;
	int A[n];
	FillDec (A, n);
	switch (i) {
		case 0: SelectSort (A, n);
			break;
		case 1: BubbleSort (A, n);
			break;
		case 2: ShakerSort (A, n);
			break;
		case 3: InsertSort (A, n);
			break;
	}
}

void FunkInc (int n, int i) {
	M=0; C=0;
	int A[n];
	FillInc (A, n);
	switch (i) {
		case 0: SelectSort (A, n);
			break;
		case 1: BubbleSort (A, n);
			break;
		case 2: ShakerSort (A, n);
			break;
		case 3: InsertSort (A, n);
			break;
	}
}

void FunkRand (int n, int i) {
	M=0; C=0;
	int A[n];
	FillRand (A, n);
	switch (i) {
		case 0: SelectSort (A, n);
			break;
		case 1: BubbleSort (A, n);
			break;
		case 2: ShakerSort (A, n);
			break;
		case 3: InsertSort (A, n);
			break;
	}
}

void ShakerSort (int A[], int n) {
	M=0, C=0;
	int left,right,i,j,k,w;
	left=0;
	right=n-1;
	k=n-1;
	do {
		for(j=right; j>left; j-- ){ // ot pravogo k levomu
			C++;
			if (A[j]<A[j-1]) { // obmen
				w=A[j];
		  	 	A[j]=A[j-1];
			  	A[j-1]=w;
		  	 	k=j;
		  	 	M+=3;
			}
		}
		left=k;
		for(j=left; j<right; j++ ){ // ot levogo k pravomu
			C++;
	   		if(A[j]>A[j+1]){ // obmen 
	   			w=A[j];
	  	 		A[j]=A[j+1];
	   			A[j+1]=w;
	   			k=j;
	   			M+=3;
			}
		}
		right=k;
	}
	while( left<right );
	A[n]=M+C;
}

void InsertSort (int A[], int n) {
	M=0, C=0;
	int i,t,j;
	for(i=1; i<n; i++) {
		M++;
		t=A[i];
		j=i-1;
		while(j>=0 && (C++, t<A[j])) { // poka element menshe, smeshaem
			M++;
			A[j+1]=A[j];
			j=j-1;
		}
		M++;
		A[j+1]=t;
	}
	A[n]=M+C;
}

void SelectSort (int A[], int n) 
{
	M= 0, C= 0;
	int i,j,k,t;
	for (i = 0; i < n-1; i++ ) { //nachalnoe znachenie min
		k = i;
		for( j=i+1; j<n; j++){ // nahodim index min
			C++;
	   		if (A[j]<A[k])k=j;
		}
		t=A[i];
		A[i]=A[k];
		A[k]=t; //menyaem znacheniya
		M+=3;
	}
	A[n]=M+C;
}
void grafic(int a_1[],int a_2[],int a_3[],int a_4[]){
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
    outtextxy ( 70, 25, (char *)"M+C (fact)" );
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
	line(45,680,55,680);
	outtextxy ( 10, 675, (char *)"5000" );
	line(45,580,55,580);
	outtextxy ( 1, 575, (char *)"20000" );
	line(45,480,55,480);
	outtextxy ( 1, 475, (char *)"40000" );
	line(45,380,55,380);
	outtextxy ( 1, 375, (char *)"80000" );
	line(45,277,55,277);
	outtextxy ( 0, 280, (char *)"120000" );
	
	
	setcolor(4);
    moveto(50,780);
    for(int n = 100, j = 0; n < 701, j < 7; n += 100, j ++){
		lineto(n, (780-(a_2[j]/680)));
    }
    outtextxy ( 550, 100, (char *)"Bubble" );
    setcolor(5);
    moveto(50,780);
    for(int n = 100, j = 0; n < 701, j < 7; n += 100, j ++){
		lineto(n, (780-(a_1[j]/680)));
    }
    outtextxy ( 600, 450, (char *)"Select" );
    setcolor(6);
    moveto(50,780);
    for(int n = 100, j = 0; n < 701, j < 7; n += 100, j ++){
		lineto(n, (780-(a_3[j]/680)));
    }
    outtextxy ( 650, 150, (char *)"Shaker" );
	setcolor(1);
    moveto(50,780);
    for(int n = 100, j = 0; n < 701, j < 7; n += 100, j ++){
		lineto(n, (780-(a_4[j]/700)));
    }
	outtextxy ( 620, 530, (char *)"Insert" );	
  getch();
  closegraph();
}

int main() {
	int n = 10, A[n];
	int a_1 [7];
	int a_2 [7];
	int a_3 [7];
	int a_4 [7];
	srand(time(NULL));
	for (int n = 100, j = 0; n < 701, j < 7; n += 100, j ++) {
    	a1 = new int [n+1]; // rand
    	a2 = new int [n+1]; //inc
    	a3 = new int [n+1]; //dec
    	a4 = new int [n+1]; // ran
    	FillRand(a1, n);
    	FillRand(a2, n);
    	FillRand(a3, n);
    	FillRand(a4, n);
    	SelectSort(a1,n);
    	BubbleSort(a2,n);
    	ShakerSort(a3,n);
    	InsertSort(a4,n);
    	a_1[j] = a1[n];
    	a_2[j] = a2[n];
    	a_3[j] = a3[n];
    	a_4[j] = a4[n];
    	delete a1;
    	delete a2;
    	delete a3;
    	delete a4;
    }
    	
	
	FillRand (A, n);
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	printf ("M(teor)=%d, C(teor)=%d \n", ((n*n-n)/2)+2*n-2, (n*n-n)/2); 
	InsertSort (A,n);
	PrintMas (A, n);
	CheckSum (A, n);
	RunNumber (A, n);
	printf ("M(fact)=%d, C(fact)=%d \n", M, C);
	printf ("\n\n");
	TablResult (100);
	printf ("\n\n\n\n");
    grafic(a_1,a_2,a_3,a_4);
	system("PAUSE");
	return 0;
}

