#include <stdlib.h>
#include <stdio.h>
#include <time.h>
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ system("CLS");
int i, j=0, k=0, a = -10, b = 10;
float A[N], B[k];
srand(time(NULL));
for ( i = 0; i < N; i ++ )
A[i] = (float)rand()*(b-a)/RAND_MAX + a;
for ( i = 0; i < N; i ++ )
printf("\nA[%d]=%6.2f",i,A[i]);
printf("\n\n");
for(i=0; i<N; i++)
if (A[i]>0) printf("\nB[%d]=%6.2f",i,A[i]);
system("PAUSE");
return 0;
}
