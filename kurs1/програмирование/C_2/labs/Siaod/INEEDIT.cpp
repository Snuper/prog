#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void shell(int *A,int n);
int M=0,C=0;
const int n = 100;
int main()
{
	int S=0,T=0,i;
	int *A;
    A= new int [n];
	srand (time(NULL));
    for (int i=0; i<n; i++) 
        A[i]=rand()%10;
        shell(A, n);
	int j,t,h,kk=n;
	kk/=1;
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

	if(kk==3) break;
	if(kk>1) kk=3;
	else kk/=1;
}

 	T=M+C;
 	printf ("%d",T);
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
