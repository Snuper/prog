#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funk.h"


int random (int N) { return rand() % N; }
const int n=10000;
void FillRand(int A[n],int);
void FillRand2(float B[n],int);

main(){
int A[n], i;
float B[n];


FillRand(A,n);
clock_t start = clock();
  BubbleSort(A, n);
clock_t end = clock();
double seconds = (double)(end - start) / CLOCKS_PER_SEC;
printf("BubbleSort - %5.3f\n",seconds);


FillRand(A,n);
clock_t start1 = clock();
  InsertSort(A, n);
clock_t end1 = clock();
double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
printf("InsertSort - %5.3f\n",seconds1);

FillRand2(B,n);
clock_t start2 = clock();
  BubbleSort2(B, n);
clock_t end2 = clock();
double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
printf("Float BubbleSort - %5.3f\n",seconds2);


FillRand2(B,n);
clock_t start12 = clock();
  InsertSort2(B, n);
clock_t end12 = clock();
double seconds12 = (double)(end12 - start12) / CLOCKS_PER_SEC;
printf("Float InsertSort - %5.3f\n",seconds12);

getche();
}

void FillRand(int *A, int n){
	int i;
    for(i=0;i<n;i++) {
	A[i]= random(15);
	}
}

void FillRand2(float *B, int n){
	int i;
    for(i=0;i<n;i++) {
	B[i]= rand()*20/RAND_MAX+1;
	}
}
