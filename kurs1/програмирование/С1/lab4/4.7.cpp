#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   int N = 1,s,n;
   printf("Vvedite n");
   scanf("%d",&n);
    for (s=1; N<=n; N++)
			{	
			s*=N;
	}
     printf ("S=%d",s);
    system("PAUSE");
    return 0;
}
