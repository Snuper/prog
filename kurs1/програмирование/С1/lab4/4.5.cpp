#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float N,a,s,n;
    for (s=0, N=1, n=0.18; n<=0.36; N++,n=n+0.02)
			{
			a=pow(n,N);
			s=s+a;
			}
     printf ("n=%.0f s=%.3f",n,s);
    system("PAUSE");
    return 0;
}
