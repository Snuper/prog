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
for(i=0;i<size;i++)
x[i]=random(100);
}

void FillInc(int * x, int size)
{
x[0]=random(100);
for(i=1;i<size;i++)
x[i]=x[i-1]+random(30);
}

void FillDec(int * x, int size)
{
x[0]=random(100);
for(i=1;i<size;i++)
x[i]=x[i-1]-random(30);
}

void BubbleSort(int * x, int size)
{
m=0;
c=0;
for(i=1;i<size;i++)
{
for(j=size;j>i-1;j=j-1)
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
int a[n];
{
FillRand(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("\n");
BubbleSort(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("  Kol-vo sravneniy %d.", c);
printf("  Kol-vo peresylok %d.", m);
CheckSum(a,n);
RunNumber(a,n);
mcrand[n]=m+c;
printf("\n");

FillInc(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("\n");
BubbleSort(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("  Kol-vo sravneniy %d.", c);
printf("  Kol-vo peresylok %d.", m);
CheckSum(a,n);
RunNumber(a,n);
mcinc[n]=m+c;
printf("\n");

FillDec(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("\n");
BubbleSort(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("  Kol-vo sravneniy %d.", c);
printf("  Kol-vo peresylok %d.", m);
CheckSum(a,n);
RunNumber(a,n);
mcdec[n]=m+c;
printf("\n");
}

system("pause");
return 0;
}

