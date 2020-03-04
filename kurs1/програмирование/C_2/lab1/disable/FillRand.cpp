#include <stdlib.h>
#include <stdio.h>
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ system("CLS"); 
  int sum=0, i, A[N], a = -100, b = 100;//a и b область значений
  printf("Elementi massiva\n");
  for ( i = 0; i < N; i ++)
{     
	 printf("A[%d]",i);
	 A[i] = random(b-a+1) + a; 
	 printf("=%d;\n",A[i]);   
}
  system("PAUSE");
  return 0;
}
