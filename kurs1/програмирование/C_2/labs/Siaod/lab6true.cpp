#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void shell(int *num, int size);
void Shell_Sort (int *A,int n);
void FillRand(int *A, int n);
void PrintMas(int *A, int n);
void FillInc (int *A, int n);
void FillDec (int *A, int n);
void TablBuild (int *A, int n);

const int n = 10;
int S,C,M,T,Ct,Mt,Tt;
int main()
{	
    int *A;
    A= new int [n];
     FillInc (A,n);
     shell(A,n);
     Shell_Sort (A, n);
     PrintMas (A, n);
     T=C+M;
     printf ("Summa peresilok i sravnenii real for Inc = %d \n",T);
     
     FillDec (A,n);
     shell(A,n);
     Shell_Sort (A, n);
     PrintMas (A, n);
     T=C+M;
     printf ("Summa peresilok i sravnenii real for Dec = %d \n",T);
     
     FillRand (A, n);
     shell(A,n);
     Shell_Sort (A, n);
     PrintMas (A, n);
     //Ct=3*(n-1);
     //Mt=(n*n)-n;
     //Tt=Ct+Mt;
     //printf ("Summa peresilok i sravnenii teor = %d \n",Tt);
     T=C+M;
     printf ("Summa peresilok i sravnenii real for rand = %d \n",T);
     TablBuild (A, n);
    system ("PAUSE");
    return 0;
}

void Shell_Sort(int *A, int n)
{

	int i,j,t,h,kk=n;
	kk/=3;
	S=0;
	while(kk>0){
		S++;
		//printf("%d",kk);
    for(i=kk;i<n;i++){
    	t=A[i];
		j=i-kk; C++; M++;
    	while((j>0)&&(t<A[j])){
    		A[j+kk]=A[j-1]; C++; M++;
	        j-=kk;
		}
	}

	A[j]=t;  M++;

	if(kk==1) break;
	if(kk<3) kk=1;
	else kk/=3;
}

}

void shell(int *A, int n)
{
  int increment = 3;
  while (increment > 0)
  {
    for (int i = 0; i < n; i++)
    {
      int j = i;
      int temp = A[i];C++; M++;

      while ((j >= increment) && (A[j - increment] > temp))
      {
        A[j] = A[j - increment];
        j = j - increment;     C++; M++;
      }
      A[j] = temp; M++;
    }
    if (increment > 1)
      increment = increment / 2;
    else if (increment == 1)
      break;
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
	printf ("____________________________________________________________________________ \n");
	printf ("|              |                                |                           | \n");
	printf ("|              |      Shell_sort                |       Incert_sort         | \n");
	printf ("|______________|___INK___|__DEC______|__RAND____|__INK__|__DEC______|__RAND_| \n");
	printf ("|      100     |   1340  |  4640     |  2832    | 198   |  10098    | 4930  | \n");
	printf ("|______________|_________|___________|__________|_______|___________|_______| \n");
	printf ("|      200     |   3085  |  16353    |  9339    | 398   |  40198    | 18670 | \n");
	printf ("|______________|_________|___________|__________|_______|___________|_______| \n");	
	printf ("|      300     |   4589  |  34889    |  19513   | 598   |  90298    | 40300 | \n");
	printf ("|______________|_________|___________|__________|_______|___________|_______| \n");	
	printf ("|      400     |   6153  |  59353    |  31809   | 798   |  160398   | 72180 | \n");
	printf ("|______________|_________|___________|__________|_______|___________|_______| \n");	
	printf ("|      500     |   8688  |  91856    |  47378   | 998   |  250498   | 121580| \n");
	printf ("|______________|_________|___________|__________|_______|___________|_______| \n");	
}
