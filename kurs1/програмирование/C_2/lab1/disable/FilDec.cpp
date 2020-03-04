#include <stdlib.h>
#include <stdio.h>
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ system("CLS"); 
  int e, i, A[N], q, a = -100, b = 100;//a и b область значений
  printf("Elementi massiva\n");
  for ( i = 0; i < N; i ++)
{     
	 printf("A[%d]",i);
	 A[i] = random(b-a+1) + a; 
	 printf("=%d;\n",A[i]);   
}
  for (q=0;q<N-1;q++)
  {
  for (i=0;i<N;i++)
  {
  if (A[i] > A[i+1])	
  ;
  else
  {
  e=A[i];
  A[i]=A[i+1];
  A[i+1]=e;
  }
  }
  }
  printf("\nPo vozrastaniu");
  for (i=0;i<N;i++)
  printf("\nA[%d]=%d",i,A[i]);
  system("PAUSE");
  return 0;
}
