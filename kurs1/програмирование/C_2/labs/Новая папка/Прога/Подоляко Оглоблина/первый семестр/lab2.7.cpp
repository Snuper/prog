#include<stdio.h>
#include <stdlib.h>
#include<math.h>
main()
{
     float K, M, N, A, C; 
     printf("Input K, M, N");   scanf("%f%f%f",&K, &M, &N);
     C=N; A=K;
     if (M>N) C=M, M=N;
     N=C;
	 if (K>M) A=M, M=K;
	 K=A;
	  if (M>N) C=M, M=N;
     N=C;
     printf("K=%2.0f, M=%2.0f, N=%2.0f",K,M,N);
     system("PAUSE");
     return 0;
}

