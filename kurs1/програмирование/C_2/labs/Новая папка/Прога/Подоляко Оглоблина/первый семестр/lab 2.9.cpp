#include<stdio.h>
#include<math.h>
#include <stdlib.h>
main()
{
     float A, B, C, K, N, M, max, min; 
     printf("Input A,B,C");   scanf("%f%f%f",&A, &B, &C);
     K=A; N=B; M=C;
    if ((A>B)&&(A>C)) max=A; else if ((B>C)) max=B; else max=C;
    if ((A<B)&&(A<C)) min=A; else if ((B<C)) min=B; else min=C;
    if (((A==max)&&(B==min))||((A==min)&&(B==max))) K=B, B=A, A=K;
    if (((B==max)&&(C==min))||((B==min)&&(C==max))) N=C, C=B, B=N;
    if (((A==max)&&(C==min))||((A==min)&&(C==max))) M=A, A=C, C=M;
      printf("A=%2.0f, B=%2.0f, C=%2.0f",A, B, C);
        system("PAUSE");
     return 0;
}
