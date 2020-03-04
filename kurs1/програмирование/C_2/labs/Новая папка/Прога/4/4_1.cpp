#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	int S,i,n;
	printf("vvedite n ");
	scanf("%d", &n);
	for (S=0, i=1; i<=n; i++)
	S+=i;
	printf("S=%d ", S);
	system("PAUSE");
	return 0;
}
