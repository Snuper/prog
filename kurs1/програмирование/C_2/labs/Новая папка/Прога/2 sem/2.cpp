#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,i,j,k,t,s,s2,m,c;

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
printf("Vvedite razmer massiva\n");
scanf("%d", &n);
int a[n];
FillRand(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("\n");
SelectSort(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("  Kol-vo sravneniy %d.", c);
printf("  Kol-vo peresylok %d.", m);
CheckSum(a,n);
RunNumber(a,n);
printf("\n");

FillInc(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("\n");
SelectSort(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("  Kol-vo sravneniy %d.", c);
printf("  Kol-vo peresylok %d.", m);
CheckSum(a,n);
RunNumber(a,n);
printf("\n");

FillDec(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("\n");
SelectSort(a,n);
PrintMas(a,n);
printf(" K. Summa ravna %d.", CheckSum(a,n));
printf("  Kol-vo seriy ravno %d.", RunNumber(a,n));
printf("  Kol-vo sravneniy %d.", c);
printf("  Kol-vo peresylok %d.", m);
CheckSum(a,n);
RunNumber(a,n);
printf("\n");
system("pause");
return 0;
}

