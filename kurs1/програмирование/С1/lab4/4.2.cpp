#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{   float a,s,n;
    for (s=0, n=0; n<=25; n++)
			{
			a=sin(n);
			s=s+a;
	}
     printf ("n=%.0f s=%.3f",n,s);
    system("PAUSE");
    return 0;
}
