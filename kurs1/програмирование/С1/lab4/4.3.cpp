#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float N,a,s,n;
   printf("Vvedite n");
   scanf("%f",&n);
    for (s=0, N=0; N<=n; N++)
			{
			a=tan(N*2);
			s=s+a;
	}
     printf ("n=%.0f s=%.0f",n,s);
    system("PAUSE");
    return 0;
}
