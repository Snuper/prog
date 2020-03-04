#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void FillInc (int r ,int k[])
{
for(int s=0;s<r;s++)
k[s]=s;
}

void FillDec (int r ,int k[])
{int m=r;
m--;
for(int s=0;s<r;s++,m--)
k[s]=m;
}

void PrintMas (int r ,int k[])
{
for (int s=0;s<r;s++)
printf ("%d ",k[s]);
}

int CheckSum (int r ,int k[])
{int sum=0;
for (int s=0;s<r;s++)
sum=k[s]+sum;
//printf ("\n sum =%d ",sum);
return sum;
}

int RunNumber (int r ,int k[])
{int ser=1;
r--;
for(int s=0;s<r;s++)
if (k[s]>k[s+1])
ser++;
return ser;
}

void FillRand (int r ,int k[])
{
for(int s=0;s<r;s++)
k[s]= rand() % (21)-10;
}

float dop (int r ,int k[])
{int s; float res;
	s=RunNumber(r,k);
	res=1.*r/s;
	return res;
}








int main ()
{srand(time(0));
    int const c=20;
    int b[c];
    float i;
  
    
   FillRand(c,b);
   PrintMas(c,b);
   i=dop(c,b);
   printf("%f",i);
   
    
    system("PAUSE");
}
