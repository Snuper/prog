#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

int n,i,j,k,l,r,t,s,s2,m,c,m1,m2;
int mcrands[501];
int mcrandb[501];
int mcrandsh[501];
int mcrandin[501];
int mcrandshe[501];
int k1[501];

int random (int N) { return rand()%N;}

void PrintMas(int * x, int size)
{
for(i=0;i<size;i++)
printf("%d ", x[i]);
}

void FillRand(int * x, int size)
{
for(i=1;i<size;i++)
x[i]=random(100);
}

void FillInc(int * x, int size)
{
x[0]=random(100);
for(i=1;i<size;i++)
x[i]=x[i-1]+random(30)+1;
}

void FillDec(int * x, int size)
{
x[0]=random(100);
for(i=1;i<size;i++)
x[i]=x[i-1]-random(30)-1;
}

void SelectSort(int * x, int size)
{
m=0;
c=0;
for(i=0;i<(size-1);i++)
{
k=i;
for(j=(i+1);j<size;j++)
{
c=c+1;
if(x[j]<x[k])
k=j;
}
m=m+3;
t=x[k];
x[k]=x[i];
x[i]=t;
}
}

void BubbleSort(int * x, int size)
{
m=0;
c=0;
for(i=0;i<size;i++)
{
for(j=size-1;j>i-1;j=j-1)
{
c=c+1;
if(x[j]<x[j-1])
{
m=m+3;
t=x[j];
x[j]=x[j-1];
x[j-1]=t;
}
}
}
}

void ShakerSort(int * x, int size)
{
m=0;
c=0;
l=1;r=size;k=size;
while(l<r)
{
for(j=r;j>l;j--)
{
c=c+1;
if(x[j]<x[j-1])
{
m=m+3;
t=x[j];
x[j]=x[j-1];
x[j-1]=t;
k=j;
}
}
l=k;
for(j=l;j<r;j++)
{
c=c+1;
if(x[j]<x[j-1])
{
m=m+3;
t=x[j];
x[j]=x[j-1];
x[j-1]=t;
k=j;
}
}
r=k;
}
}

void ShakerSort2(int *A, int n){
  int j,l=0,r=n-1,k=n,t,mc;
m=0;c=0;
while(l<r){
	for(j=r;j>l;j--){
 c++;
      if (A[j-1]>A[j]){
        t=A[j];
		A[j]=A[j-1];
		A[j-1]=t;
		m+=3;
		k=j;}
	}
	l=k;
	for(j=l;j<r;j++){
		c++;
      if (A[j]>A[j+1]){
        t=A[j];
		A[j]=A[j+1];
		A[j+1]=t;
		m+=3;
		k=j;}
	}
	r=k;
}
}

void InsertSort(int *A, int n){
	int i,j,t,mc;
	m=0; c=0;
	for(i=1;i<n;i++){
		t=A[i];
		m++;
		j=i-1;
		while(j>=0 and t<A[j]){
			m++;
			c++;
			A[j+1]=A[j];
			j=j-1;
		}
		if (j>=0) c++;
		m++;
		A[j+1]=t;
	}
}

void ShellSort(int *A, int n, int m1){
	int i1,mc,h[m1];
   m=0;
   c=0;
	h[0]=1;
	for(i=1; i<m;i++)
	h[i]=2*h[i-1]+1;
	
	for(i1=m;i1>=0;i1--)
		k=h[i1];
		for(i=k;i<n;i++){
			t=A[i];
			m++;
			j=i-k;
			c++;
			while(j>0 and t<A[j]){
				A[j+k]=A[j];
				m++;
				j=j-k;
			}
			m++;
			A[j+k]=t;
		}
}

int CheckSum(int * x, int size)
{
s=0;
for(i=0;i<size;i++)
s=s+x[i];
return s;
}

int RunNumber(int * x, int size)
{
s2=1;
for(i=0;i<size-1;i++)
if(x[i]>x[i+1])
s2=s2+1;
return s2;
}

main()
{   
	
for(n=100;n<501;n=n+100)
{
int a[n];
FillRand(a,n);
printf("\n");
SelectSort(a,n);
mcrands[n]=m+c;
printf("\n");
}	
	
for(n=100;n<501;n=n+100)
{
int a[n];
FillRand(a,n);
printf("\n");
BubbleSort(a,n);
mcrandb[n]=m+c;
printf("\n");
}

for(n=100;n<501;n=n+100)
{
int a[n];
FillRand(a,n);
printf("\n");
ShakerSort(a,n);
mcrandsh[n]=m+c;
printf("\n");
}

for(n=100;n<501;n=n+100)
{
int a[n];
FillRand(a,n);
printf("\n");
InsertSort(a,n);
mcrandin[n]=m+c;
printf("\n");
}

for(n=100;n<501;n=n+100)
{
int a[n];
FillRand(a,n);
m1=log2(n);
m1=round(m1-0.5);
m2=int(m1);
printf("\n");
ShellSort(a,n,m2);
mcrandshe[n]=m+c;
k1[n]=m2;
printf("\n");
}

printf("\n|    n   |  k  |shell       | insert   |");
printf("\n|  100   |  %d  |  %d      | %d     |",k1[100],mcrandshe[100],mcrandin[100] );
printf("\n|  200   |  %d  |  %d     | %d    |",k1[200],mcrandshe[200],mcrandin[200] );
printf("\n|  300   |  %d  |  %d     | %d    |",k1[300],mcrandshe[300],mcrandin[300] );
printf("\n|  400   |  %d  |  %d     | %d    |",k1[400],mcrandshe[400],mcrandin[400] );
printf("\n|  500   |  %d  |  %d     | %d   |",k1[500],mcrandshe[500],mcrandin[500] );

system("pause");
return 0;
}
