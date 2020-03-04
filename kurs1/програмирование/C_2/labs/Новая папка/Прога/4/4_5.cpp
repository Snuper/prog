#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	float i,S,x,stepen;
	printf("vvedite x ");
	scanf("%f", &x);
	for (S=0, i=0.18, stepen=1; i<=0.361; i+=0.02, stepen++)
	S+=powf(i*x, stepen);
	printf("S=%7.3f ", S);
	system("PAUSE");
	return 0;
}
