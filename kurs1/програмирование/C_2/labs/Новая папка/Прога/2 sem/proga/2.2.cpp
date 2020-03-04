#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int i,n,k2;
int random (int N) { return rand()%N;}

void FillRand(int * x, int size)
{
for(i=0;i<size;i++)
x[i]=random(100)-50;
}

void PrintMas(int * x, int size)
{
for(i=0;i<size;i++)
printf("%d ", x[i]);
}

int rec(int * x, int size,int k,int k2)
{
if ((k == size) and (k2 == 0))
{
k2=1;
k=0;
return rec(x,size,k,k2);
}
if ((k == size) and (k2 == 1))
{
return 0;
}
if ((k != size) and (k2 == 0))
{
if (x[k]>0)
{
printf("%d ",x[k]);
k=k+1;
return rec(x,size,k,k2);
}
if (x[k]<0)
{
k=k+1;
return rec(x,size,k,k2);
}
}
if ((k != size) and (k2 == 1))
{
if (x[k]<0)
{
printf("%d ",x[k]);
k=k+1;
return rec(x,size,k,k2);
}
if (x[k]>0)
{
k=k+1;
return rec(x,size,k,k2);
}
}
}

main()
{
printf("Vvedite razmer massiva\n");
scanf("%d",&n);
int a[n];
int pol[n];
int otr[n];
FillRand(a,n);
PrintMas(a,n);
printf("\n");
rec(a,n,0,0);
}
