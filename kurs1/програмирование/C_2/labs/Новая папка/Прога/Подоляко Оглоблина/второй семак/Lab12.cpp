#include"func.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
using namespace sort;
int main()
{
	const int n=10000;
	int A[n];
	double B[n];
	for (int i=0;i<n;i++)
	{	
		A[i]=rand()%1000;
		B[i]=(double)rand()*1000/RAND_MAX;
	}
	printf("Time of sorting of an integer array(Selectsort):%d",timer(SelectSort,A,n));
	printf("\n Time of sorting of an double array(Selectsort):%d",timer(SelectSort,B,n));
	for (int i=0;i<n;i++)
	{	
		A[i]=rand()%1000;
		B[i]=(double)rand()*1000/RAND_MAX;
	}
	printf("\n Time of sorting of an integer array(Bubblesort):%d",timer(BubbleSort,A,n));
	printf("\n Time of sorting of an double array(Bubblesort):%d",timer(BubbleSort,B,n));
	for (int i=0;i<n;i++)
	{	
		A[i]=rand()%1000;
		B[i]=(double)rand()*1000/RAND_MAX;
	}
	printf("\n Time of sorting of an integer array(Shakersort):%d",timer(ShakerSort,A,n));
	printf("\n Time of sorting of an double array(Shakersort):%d",timer(ShakerSort,B,n));
	for (int i=0;i<n;i++)
	{	
		A[i]=rand()%1000;
		B[i]=(double)rand()*1000/RAND_MAX;
	}
	printf("\n Time of sorting of an integer array(Insertsort):%d",timer(InsertSort,A,n));
	printf("\n Time of sorting of an double array(Insertsort):%d",timer(InsertSort,B,n));
	puts("\n");
	system("PAUSE");
	return 0;	
	
}
