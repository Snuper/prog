#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float N,a,s,n;
    for (s=1, N=0; N<12;)
			{	
			N+=2;
			s=s*N;
	}
     printf ("N=%.0f s=%.0f",N,s);
    system("PAUSE");
    return 0;
}
