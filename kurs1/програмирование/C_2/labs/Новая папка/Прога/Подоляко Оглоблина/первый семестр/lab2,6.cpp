#include<stdio.h>
#include <stdlib.h>
#include<math.h>
main()
{
     float A, B, C, D, max, min, raz; 
     printf("Input A,B,C,D");   scanf("%f%f%f%f",&A, &B, &C, &D);
     if ((A>B)&&(A>C)&&(A>D)) max=A; else if ((B>C)&&(B>D)) max=B; else if (C>D) max=C; else max=D;
     if ((A<B)&&(A<C)&&(A<D)) min=A; else if ((B<C)&&(B<D)) min=B; else if (C<D) min=C; else min=D;
      printf("max=%2.0f, min=%2.0f \n",max, min);
     raz=max-min;
     printf("raz=%2.0f",raz);
     system("PAUSE");
     return 0;
}
