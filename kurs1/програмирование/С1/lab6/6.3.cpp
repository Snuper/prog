#include <stdlib.h>
#include <stdio.h>
const int N = 20;
int
 random (int N) { return rand()%N; }
main()
{ system("CLS"); 
  int i, a = 0, b = 10;
  float A[N];
  printf("Elementi massiva\n");
  for ( i = 0; i < N; i ++)
{     
	 printf("A[%d]",i);
	 A[i] = (float)rand()*(b-a)/RAND_MAX + a; //РРандом вещественных чисел
	 printf("=%.2f;\n",A[i]);   
}
printf("Elementi massiva, kotorie bolshe svoih sosedey");
for (i=1; i<N-1; i++)
{
if (A[i-1]<A[i] and A[i]>A[i+1]) //Проверяем соседей 
printf("\nA[%d]=%.2f",i,A[i]);
}
  system("PAUSE");
  return 0;
}
