#include <stdlib.h>
#include <stdio.h>
#include <time.h>
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ system("CLS"); 
  int i;
  float A[N], a = 0, b = 10;
  srand(time(NULL));
  for ( i = 0; i < N; i ++ )
     A[i] = (float)rand()*(b-a)/RAND_MAX + a; 
  for ( i = 0; i < N; i ++ )
     printf("  %4.2f",A[i]);
     printf("\n\n");
   for ( i = 1; i < N; i ++ )
  if ((A[i-1]<A[i])&&(A[i]>A[i+1]))
  printf("  %4.2f",A[i]);
  system("PAUSE");
  return 0;
}
