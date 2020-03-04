#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	int i,P,n;
	printf("vvedite n ");
	scanf("%d", &n);
	for (P=1, i=2; i<=n; i+=2)
	P=P*i;	
	printf("P=%d ", P);
	system("PAUSE");
	return 0;
}
