#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float N,a,s,n;
	for (s=0, n=-0.1, N=0; n<=1.9; N++)
			{
			n=n+0.2;
			a=log(n);
			s=s+a;
	}
     printf ("N=%.0f s=%.3f",N,s);
    system("PAUSE");
    return 0;
}
