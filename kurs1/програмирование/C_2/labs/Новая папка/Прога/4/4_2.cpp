#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	int i,n;
	float S,sinus;
	printf("vvedite n ");
	scanf("%d", &n);
	for (S=0, i=1; i<=n; i++)
{
	sinus=sin(i);
	S+=sinus;
}
	printf("S=%7.3f ", S);
	system("PAUSE");
	return 0;
}
