#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	int i, n, fi, fn, fin, k;
	printf("Input n > 0: ");
	scanf("%d", &n);
	int C[n];
	for (i = 0; i < n; i++)
	{
		for (k = 1, fn = 1;k <= n; k++) //fact n
		{
			fn *= k;
		}
		for (k = 1, fi = 1; k < (i+1); k++) //fact i
		{
			fi *= k;
		}
		for (k = 1, fin = 1;k <= (n - i); k++) //fact (n-i)
		{
			fin *= k;
		}
		C[i] = fn/(fi*fin);
	}
	for(i = 0; i < n; i++)
	{	
		printf ("C[%d] = %d\n", i, C[i]);
	}
	system("PAUSE");
	return 0;
}

