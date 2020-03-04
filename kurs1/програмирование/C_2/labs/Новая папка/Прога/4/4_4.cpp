#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	float i,S;
	for (S=0, i=0.1; i<=1.91; i+=0.2)
	S+=logf(i);
	printf("S=%7.3f ", S);
	system("PAUSE");
	return 0;
}
