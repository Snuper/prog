#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

int n,i,j,k,l,r,t,s,s2,m,c;
int mcdec[501],mcrand[501],mcinc[501];
int mcdecs[501],mcrands[501],mcincs[501];

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

void BubbleSort(int * x, int size)
{
m=0;
c=0;
for(i=1;i<size;i++)
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
do
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
x[j]=x[j+1];
x[j-1]=t;
k=j;
}
}
r=k;
}
while(l<r);
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
BubbleSort(a,n);
mcrand[n]=m+c;
printf("\n");

FillInc(a,n);
printf("\n");
BubbleSort(a,n);
mcinc[n]=m+c;
printf("\n");

FillDec(a,n);
printf("\n");
BubbleSort(a,n);
mcdec[n]=m+c;
printf("\n");
}

for(n=100;n<501;n=n+100)
{
int a[n];
FillRand(a,n);
printf("\n");
ShakerSort(a,n);
mcrands[n]=m+c;
printf("\n");

FillInc(a,n);
printf("\n");
ShakerSort(a,n);
mcincs[n]=m+c;
printf("\n");

FillDec(a,n);
printf("\n");
ShakerSort(a,n);
mcdecs[n]=m+c;
printf("\n");
}

printf("\n|    n  |  dec(b)  |rand(b)   | inc(b)     | dec(s)       |rand(s)    | inc(s) |");
printf("\n|  100  |  %d   | %d    |  %d      |  %d       | %d      | %d   |", mcdec[100], mcrand[100], mcinc[100],mcdecs[100], mcrands[100], mcincs[100]);
printf("\n|  200  |  %d   | %d    |  %d     |  %d       | %d     |  %d |", mcdec[200], mcrand[200], mcinc[200],mcdecs[200], mcrands[200], mcincs[200]);
printf("\n|  300  |  %d  |  %d  |  %d     |  %d      | %d     |  %d |", mcdec[300], mcrand[300], mcinc[300],mcdecs[300], mcrands[300], mcincs[300]);
printf("\n|  400  |  %d  |  %d  |  %d     |  %d       | %d    |  %d |", mcdec[400], mcrand[400], mcinc[400],mcdecs[400], mcrands[400], mcincs[400]);
printf("\n|  500  |  %d  |  %d  |  %d    |  %d       | %d    |  %d |", mcdec[500], mcrand[500], mcinc[500],mcdecs[500], mcrands[500], mcincs[500]);

system("pause");
return 0;
}

