#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float b,N,a,s,n;
   printf("Vvedite chislo ");
   scanf("%f",&n);
    for (s=0, N=0, b=0; N<n; N++)
			{
			b++	;
			a=pow(-1,N);
			s=s+b*a;
	}
     printf ("n=%.0f s=%.0f",n,s);
    system("PAUSE");
    return 0;
}
