#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void InsertSort(int *A, int n);
void FillRand(int *A, int n);
void PrintMas(int *A, int n);
void FillInc (int *A, int n);
void FillDec (int *A, int n);
void TablBuild (int *A, int n);

const int n = 10;
int C,M,T,Ct,Mt,Tt;
int main()
{
	int *A;
    A= new int [n];
     FillInc (A,n);
     InsertSort (A, n);
     PrintMas (A, n);
     T=C+M;
     printf ("Summa peresilok i sravnenii real for Inc = %d \n",T);
     
     FillDec (A,n);
     InsertSort  (A, n);
     PrintMas (A, n);
     T=C+M;
     printf ("Summa peresilok i sravnenii real for Dec = %d \n",T);
     
     FillRand (A, n);
     InsertSort  (A, n);
     PrintMas (A, n);
     Ct=3*(n-1);
     Mt=(n*n)-n;
     Tt=Ct+Mt;
     printf ("Summa peresilok i sravnenii teor = %d \n",Tt);
     T=C+M;
     printf ("Summa peresilok i sravnenii real for rand = %d \n",T);
     
     TablBuild (A, n);
     
    system ("PAUSE");
    return 0;
}

void InsertSort(int *A, int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=A[i];
		j=i; 
		C++;
		while((j>0)&&(t<A[j-1]))
			{
				A[j]=A[j-1]; 
				C++; 
				M++;
				j--;	
			}
	A[j]=t;
	M++;
	}
}

void FillRand(int *A, int n)
{
    srand (time(NULL));
    for (int i=0; i<n; i++) 
        A[i]=rand()%10;
    PrintMas(A,n);
}

void PrintMas(int *A, int n)
{
     for (int i=0;i<n;i++)
     printf("%d   ",A[i]);
     printf("\n");
}

void FillInc (int *A, int n)
{int i;
     for (i=0;i<n;i++)
     A[i] = i;
     PrintMas(A,n);
}

void FillDec (int *A, int n)
{int i;
     for (i=0;i<n;i++)
     A[i] = n-i-1;
     PrintMas(A,n);
} 

void TablBuild (int *A, int n)
{
	printf ("\n");
	printf ("___________________________________________________________________ \n");
	printf ("|______________|___Select___|__Babble______|__Sheker_____|_Insert__| \n");
	printf ("|      100     |     5196   |     10827    |   9630      |  4930   | \n");
	printf ("|______________|____________|______________|_____________|_________| \n");
	printf ("|      200     |    20422   |     46741    |   38347     |  18670  | \n");
	printf ("|______________|____________|______________|_____________|_________| \n");	
	printf ("|      300     |    45654   |    103224    |   97110     |  40300  | \n");
	printf ("|______________|____________|______________|_____________|_________| \n");	
	printf ("|      400     |   80880    |    186597    |   169960    |  72180  | \n");
	printf ("|______________|____________|______________|_____________|_________| \n");	
	printf ("|      500     |   126088   |    299497    |   238503    | 121580  | \n");
	printf ("|______________|____________|______________|_____________|_________| \n");	
}
