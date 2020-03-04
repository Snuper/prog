#include<stdio.h>
#include<math.h>
#include <stdlib.h>
main()
{
     float A, B, C, D, max, max1, max2, max3, max4, max5; 
     printf("Input A,B,C,D");   scanf("%f%f%f%f",&A, &B, &C, &D);
     if ((A>B)&&(A>C)&&(A>D)) max=A; else if ((B>C)&&(B>D)) max=B; else if (C>D) max=C; else max=D;
     printf("max=%2.0f\n", max);max2=-100000000;
     if (((A>B)||(A>C)||(A>D))&&(A<max)&&(max2<A)) max2=A;
     if (((B>A)||(B>C)||(B>D))&&(B<max)&&(max2<B)) max2=B;
        if (((C>D)||(C>B)||(C>A))&&(C<max)&&(max2<C)) max2=C;
          if (((D>B)||(D>C)||(D>A))&&(D<max)&&(max2<D)) max2=D;
          printf("max=%2.0f, max2=%2.0f \n", max, max2);
      system("PAUSE");
     return 0;
}
