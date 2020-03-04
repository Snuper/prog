#include <stdlib.h>
#include <stdio.h>
#include <time.h>
const int N = 20;
int random (int N) { return rand()%N; }
main()
{ system("CLS"); 
  int i, A[N], a = -10, b = 10;
  srand(time(NULL));
  for ( i = 0; i < N; i ++ )
     A[i] = random(b-a+1) + a;   
  for ( i = 0; i < N; i ++ )
     printf("%4d",A[i]);
      printf("polozhitelnue \n");
  for ( i = 0; i < N; i ++ )
     if (A[i]>0) 
  printf("%4d", A[i]);
  printf("\notricatelnue \n");
  for ( i = 0; i < N; i ++ )
     if (A[i]<0) 
  printf("%4d", A[i]);
  system("PAUSE");
  return 0;
}
