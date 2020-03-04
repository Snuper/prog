#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	int i,n;
	float S;
	printf("vvedite n ");
	scanf("%d", &n);
	for (S=0, i=2; i<=n*2; i+=2)
	S+=tan(i);
	printf("S=%7.1f ", S);
	system("PAUSE");
	return 0;
}
