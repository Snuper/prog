#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int random (int N) { return rand() % N; }
const int n=500;
void FillInc(int A[n],int);
void FillRand(int A[n],int);
void PrintMas(int A[n],int);
void FillDec(int A[n],int);
int CheckSum(int A[n],int);
int RunNumber(int A[n],int);
void SelectSort(int A[n], int);
void BubbleSort(int A[n], int);
void ShakerSort(int A[n], int);
void InsertSort(int A[n], int);
void ShellSort(int A[n], int, int);
void BSearch(int A[n], int);

main(){
int A[n], i,m,z;
float m1;
long long x=0;


printf("\n===========================\n");
printf("        | BSort1 | BSort2 |");
printf("\n===========================\n");

for(m=100;m<=500;m+=100){
	
printf("%7d |", m);
FillRand(A,m);
InsertSort(A,m);
BSearch(A,m);


printf("\n===========================\n");
}

//PrintMas(A,n);
//RunNumber(A,n);
//CheckSum(A,n);

getche();
}



void FillInc(int *A,int n){
     int c;
     c=(n*n-n)/2;
    int i;
	for(i=0;i<n;i++) {
    A[i]=i;
    }
}

void FillDec(int *A,int n){
	int m,c;
	c=(n*n-n)/2;
	m=c*3;
    int i,j;
	for(i=n-1,j=0;i>=0;i--,j++) {
    A[i]=j;
    }
}

void FillRand(int *A, int n){
	int m,a,b,i,c,mc;
	c=(n*n-n)/2;
	m=(c*3)/2;
	mc=m+c;
    for(i=0;i<n;i++) {
	A[i]= random(500);
	}
}


void PrintMas(int A[n],int n){
     int i;
printf("Elementy massiva: ");
     for (i=0;i<n;i++) {
     printf("%d ", A[i]);}
printf("\n");
}


int CheckSum(int A[n],int n){
    int i;
    long long sum=0;
    for (i=0;i<n;i++) {
sum+=A[i];
}
return sum; 

}


int RunNumber(int A[n],int){
     int i,k=0,ser=1;
     for(i=0;i<n-1;i++){
        if (A[i]<A[i+1]) k++;
        else {k=0; ser++;}
        }
return ser; 

}


void SelectSort(int A[n], int){
	int i,j,k,t,m1=0,c1=0,mt,ct,mc;
	for(i=0;i<n-1;i++) {
        k=i;
		for(j=i;j<n;j++){
			c1++;
			if(A[j]<A[k]) k=j;
		}
		t=A[k];
		A[k]=A[i];
		A[i]=t;
		m1+=3;
	}
	mc=m1+c1;
	printf("%7d |", mc);
}


void BubbleSort(int *A, int n){
  int i,j,t,m1=0,c1=0,mc;
  for (i=0;i<n;i++){
    for (j=0;j<n-1-i;j++){
		c1++;
      if (A[j]>A[j+1]){
        t=A[j];
		A[j]=A[j+1];
		A[j+1]=t;
		m1+=3;
      } 
    }
  }
	mc=m1+c1;
	printf("%7d |", mc);
}


void ShakerSort(int *A, int n){
  int j,l=0,r=n-1,k=n,t,m1=0,c1=0,mc;

while(l<r){
	for(j=r;j>l;j--){
		c1++;
      if (A[j-1]>A[j]){
        t=A[j];
		A[j]=A[j-1];
		A[j-1]=t;
		m1+=3;
		k=j;}
	}
	l=k;
	for(j=l;j<r;j++){
		c1++;
      if (A[j]>A[j+1]){
        t=A[j];
		A[j]=A[j+1];
		A[j+1]=t;
		m1+=3;
		k=j;}
	}
	r=k;
}
	mc=m1+c1;
	printf("%7d |", mc);
}

void InsertSort(int *A, int n){
	int i,j,t,m1=0,c1=0,mc;
	for(i=1;i<n;i++){
		t=A[i];
		m1++;
		j=i-1;
		while(j>=0 and t<A[j]){
			m1++;
			c1++;
			A[j+1]=A[j];
			j=j-1;
		}
		m1++;
		A[j+1]=t;
	}
	mc=m1+c1;
	//printf("%7d |", mc);
}

void ShellSort(int *A, int n, int m){
	int i,j,i1,k,t,m1=0,c1=0,mc,h[m];

	h[0]=1;
	for(i=1; i<m;i++)
	h[i]=2*h[i-1]+1;
	printf("%7d |", m);
	for(i1=m;i1>=0;i1--)
		k=h[i1];
		for(i=k;i<n;i++){
			t=A[i];
			m1++;
			j=i-k;
			c1++;
			while(j>0 and t<A[j]){
				A[j+k]=A[j];
				m1++;
				j=j-k;
			}
			m1++;
			A[j+k]=t;
		}
	mc=m1+c1;
	printf("%7d |", mc);
}

void BSearch(int *A, int n){
	int i,l,r,m,c=0,x;
	float c1=0,c2=0,;
	l=1;
	r=n;
	
	for(i=0;i<n;i++){
    x=random(n-1);
	while(l<=r){
		m=round((l+r)/2);
		c1++;
		if(A[m]==x) break;
		c1++;
		if(A[m]<x) l=m+1;
		else r=m-1;
	}
	c1++;
	l=1;
	r=n;
    }
    c1=c1/n;
	//if(A[m]==x) c=1;
	//if(c==0) c1=0;
	printf("%7.3f |", c1);
	
	l=1;
	r=n;
	for(i=0;i<n;i++){
    x=random(n-1);
	while(l<r){
		m=round((l+r)/2);
		c2++;
		if(A[m]<x) l=m+1;
		else r=m;
	}
	c2++;
	l=1;
	r=n;
}
    c2=c2/n;
	printf("%7.3f |", c2);
}
