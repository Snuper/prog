#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n,i,j,k,t,s,s2;
int random (int N) { return rand()%N;}

void PrintMas(int * x, int size)
{
for(i=0;i<size;i++)
printf("%d ", x[i]);
}

void RandMass(int * x, int size)
{
for(i=0;i<size;i++)
x[i]=random(100);
}

void FillInc(int * x, int size)
{
for(i=0;i<(size-1);i++)
{
k=i;
for(j=(i+1);j<size;j++)
{
if(x[j]<x[k])
k=j;
}
t=x[k];
x[k]=x[i];
x[i]=t;
}
}

void FillDec(int * x, int size)
{
for(i=0;i<(size-1);i++)
{
k=i;
for(j=(i+1);j<size;j++)
{
if(x[j]>x[k])
k=j;
}
t=x[k];
x[k]=x[i];
x[i]=t;
}
}

void FillRand(int * x, int size)
{
for(i=0;i<size;i++)
{
k=random(size);
j=random(size);
t=x[j];
x[j]=x[k];
x[k]=t;
}
}

void CheckSum(int * x, int size)
{
s=0;
for(i=0;i<size;i++)
s=s+x[i];
printf(" K. Summa ravna %d.", s);
}

void RunNumber(int * x, int size)
{
s2=0;
for(i=0;i<size-1;i++)
if(x[i]>x[i+1])
s2=s2+1;
printf("  Kol-vo seriy ravno %d.", s2+1);
}

main()
{
printf("Vvedite razmer massiva\n");
scanf("%d", &n);
int a[n];
RandMass(a,n);
PrintMas(a,n);
CheckSum(a,n);
RunNumber(a,n);
printf("\n");
FillInc(a,n);
PrintMas(a,n);
CheckSum(a,n);
RunNumber(a,n);
printf("\n");
FillDec(a,n);
PrintMas(a,n);
CheckSum(a,n);
RunNumber(a,n);
printf("\n");
FillRand(a,n);
PrintMas(a,n);
CheckSum(a,n);
RunNumber(a,n);
return 0;
}
