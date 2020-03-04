#include <stdlib.h>
#include <stdio.h>
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ system("CLS"); 
  float i, A[N], a = 0, b = 10;
  printf("Elementi massiva\n");
  for ( i = 0; i < N; i ++)
{     
	 printf("A[%.0f]",i);
	 A[i] = (float)rand()*(b-a)/RAND_MAX + a;
	 printf("=%f;\n");   
}
printf("Otricatelnie elementi massiva: ");
for(i=0; i<N; i++)
{
	if(A[i]<0)
	printf("%f ",A[i]);
}
printf("\nPolozitelnie elementi massiva: ");
for(i=0; i<N; i++)
{
	if(A[i]>0)
	printf("%f ",A[i]);
}
  system("PAUSE");
  return 0;
}
