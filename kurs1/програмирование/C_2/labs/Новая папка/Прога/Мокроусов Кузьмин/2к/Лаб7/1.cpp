#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int random (int N) { return rand() % N; }

const int n=1001;
void FillRand(int A[n],int);
void PrintMas(int A[n],int);
void SelectSort(int A[n], int);
int Binar(int A[n], int, int);
int Perebor(int A[n], int, int);

main ()
{ 
int A[n], B[n],max1,max2,s1,s2;

FillRand(A,100);
SelectSort(A,100);
PrintMas(A,100);
printf("Binar - ");
scanf("%d",&max1);
s1=Binar(A,100,max1);
printf("=====%d=====\n",s1);

printf("Perebor - ");
scanf("%d",&max2);
s2=Perebor(A,100,max2);
printf("=====%d=====\n",s2);

printf("\n");

//FillRand(B,1000);
//SelectSort(B,1000);
//PrintMas(B,1000);

  getch();
  return 0;
}  

int Binar(int *A, int n, int k){
	int i,s=0,l=0,r=n,m;
	
	while(l<r){
		m=round((l+r)/2);
		if(A[m]==k) break;
		if(A[m]<k) l=m+1;
		else r=m-1;
		s++;
	}
	for(i=0;i<n;i++){
		if(A[i]==k) s=s;
        else s=0;}
	return s;
}

int Perebor(int *A, int n, int k){
	int i,s=0;
	for(i=0;i<n;i++){
		s++;
		if(A[i]==k) break;}
	for(i=0;i<n;i++){
		if(A[i]==k) s=s;
        else s=0;}
	return s;
	
}

void FillRand(int *A, int n){
	int i;
     for(i=0;i<n;i++) {
		A[i]= rand()%200;
	}
}

void PrintMas(int *A, int n){
     int i;
printf("Elementy massiva: ");
     for (i=0;i<n;i++) {
     printf("%d ", A[i]);}
printf("\n");
}

void SelectSort(int *A, int n){
	int i,j,k,t;
	for(i=0;i<n-1;i++) {
        k=i;
		for(j=i;j<n;j++){
			if(A[j]<A[k]) k=j;
		}
		t=A[k];
		A[k]=A[i];
		A[i]=t;
	}
}


