#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	float i,S,n,stepen;
	printf("vvedite n ");
	scanf("%f", &n);
	for (S=0, i=1, stepen=2; i<=n; i++, stepen++)
	S+=i*(pow(-1,stepen));
	printf("S=%7.3f ", S);
	system("PAUSE");
	return 0;
}
