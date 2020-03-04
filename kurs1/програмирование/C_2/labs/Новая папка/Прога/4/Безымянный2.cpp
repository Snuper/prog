#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
	float e, pi, i, s, delitel, stepen;
	e=0.00001;
	pi=0;
	s=0;
	delitel=1;
	stepen=0;
	do
	{
		s=s+(1/delitel)*(pow(-1, stepen));
		delitel=delitel+2;
		stepen=stepen+1;
	}
	while ((1/delitel)>e);
	pi=4*s;
	printf("pi=%f ", pi);
	system("PAUSE");
	return 0;
}
