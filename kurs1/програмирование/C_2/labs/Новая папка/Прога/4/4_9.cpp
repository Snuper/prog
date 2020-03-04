#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	int i,x,n,factor;
	float S;
	printf("vvedite x ");
	scanf("%d", &x);
	printf("vvedite n ");
	scanf("%d", &n);
	for (factor=1, S=0, i=1; i<=n+1; i++)
{
	S+=pow(x,(i-1))/factor;
	factor=factor*i;
}
	printf("S=%7.2f ", S);
	system("PAUSE");
	return 0;
}
