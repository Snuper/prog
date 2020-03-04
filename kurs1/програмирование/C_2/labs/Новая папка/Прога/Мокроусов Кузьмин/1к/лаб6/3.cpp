# include <stdio.h>
#include <stdlib.h>
int random (int N) { return rand() % N; }
const int n=20; 

main()
{ system("CLS");
int i, a=0, b=10;
float c[n];
printf("Massiv c=");
for (i=0; i<n; i++)  {
c[i]= (float)rand()*(b - a)/RAND_MAX + a;
printf("%4.2f\n", c[i]);
}
for (i=1; i<n; i++) 
	{
		if (c[i]>c[i+1] && c[i]>c[i-1]) printf("\n %4.2f", c[i]);
	}
system("PAUSE");

return 0;

}
