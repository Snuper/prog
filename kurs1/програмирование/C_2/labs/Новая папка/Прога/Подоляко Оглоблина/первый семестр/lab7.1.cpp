#include <stdlib.h>
#include <stdio.h>
#include <math.h>
const int N=58;
main()
{ system("CLS");
float a=2.14, b=-4.21, c=3.25, xk=-33.5, xn=-4.5, h=0.5,k;
float A[N];
int i, j;
for (i=0; i<N-1;i++)
if (xn>xk)
{
A[i]=a*pow(xn,2)*sin(xn)+xn*b+c;
xn-=h;
}
for ( i = 0; i < N-1; i ++ )
for ( j = N-2; j >= i; j-- )
if ( A[j] < A[j+1] )
{
k = A[j];
A[j] = A[j+1];
A[j+1] = k;
}
printf("\nmassiv:\n");
for ( i = 0; i< N-1; i ++ )
printf("%8.2f\n",A[i]);
system("PAUSE");
return 0;
}

