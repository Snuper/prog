#include <stdio.h>
#include <ctime>
#include <algorithm>

using namespace std;

extern int N;

template <typename T>
void BubbleSort(T *A){
	bool k;
	do{
		k = false;
		for(int i = 1; i < N; i++){
			if(A[i] < A[i-1]){
				swap(A[i], A[i-1]);
				k = true;
			}
		}
	}while(k);
}

template <typename T>
void QuickSort(T *A, int first, int last){
	T mid;
	int f = first, l = last;
	mid = A[(f+l)/2];
	do{
		while(A[f] < mid) f++;
		while(A[l] > mid) l--;
		if(f <= l){
			swap(A[f], A[l]);
			f++;
			l--;
		}
	}while(f < l);
	if(first < l)
		QuickSort(A, first, l);
	if(f < last)
		QuickSort(A, f, last);
}

template <typename T>
void SelectSort(T *A){
	for( int i = 0; i < N-1; i++){
		bool flag = false;
		int small = i;
		for(int j = i+1; j < N; j++){
			if(A[j] < A[small]){
				small = j;
				flag = true;
			}
			if(flag){
				swap(A[i],A[small]);
			}
		}
	}
}

template <typename T>
void InsertSort(T *A){
	for(int i = 1; i < N; i++){
		T temp;
		temp = A[i];
		int j;
		for(j = i; j > 0 && A[j-1]; j--)
			A[j] = A[j-1];
		A[j] = temp;
	}
}

float timer(int *A, int name){
	float start = clock();
	switch(name){
		case 0:{
			BubbleSort(A);
			break;
		}
		case 1:{
			 	int first = 0, last = N - 1;
				QuickSort(A, first, last);
				break;
		}
		case 2:{
			 	SelectSort(A);
				break;
		}
				
		case 3:{
			 	InsertSort(A);
	 			break;
		}
	}
	float end = clock();
	return (end - start) / 1000;
}

float timer(float *B, int name){
	float start = clock();
	switch(name){
		case 0:{
			BubbleSort(B);
			break;
		}
		case 1:{
			 	int first = 0, last = N - 1;
				QuickSort(B, first, last);
				break;
		}
		case 2:{
			 	SelectSort(B);
				break;
		}

		case 3:{
			 	InsertSort(B);
	 			break;
		}
	}
	float end = clock();
	return (end - start) / 1000;
}
