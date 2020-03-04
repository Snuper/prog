#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <graphics.h>

int n,i,j,k,t,s,s2,m,c;
int mcdec[501],mcrand[501],mcinc[501];

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

printf("\n|     n   |     M+C teor |  dec          |rand              | inc        |");
printf("\n|   100   |     12375    |  %d        | %d            |  %d      |", mcdec[100], mcrand[100], mcinc[100]);
printf("\n|   200   |     49750    |  %d        | %d            |  %d     |", mcdec[200], mcrand[200], mcinc[200]);
printf("\n|   300   |    112125    |  %d       |  %d          |  %d     |", mcdec[300], mcrand[300], mcinc[300]);
printf("\n|   400   |    199500    |  %d       |  %d          |  %d     |", mcdec[400], mcrand[400], mcinc[400]);
printf("\n|   500   |    311875    |  %d       |  %d          |  %d    |", mcdec[500], mcrand[500], mcinc[500]);
system("pause");
return 0;
}

