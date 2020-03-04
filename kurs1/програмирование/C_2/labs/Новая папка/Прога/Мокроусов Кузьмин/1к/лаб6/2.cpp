#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int random (int N) { return rand() % N; }
main()
{ system("CLS");
int i, n, k, f, g,t;
printf("Vvedite n: ");
scanf("%d", &n);
int c[n];
for (k=1, f=1; k<n; k++) f*=k;



for (i=1; i<=n; i++) { 
	for (k=1, g=1; k<i; k++) g*=k;
	for (k=1, t=1; k<n-i; k++) t*=k;
	c[i]= f/(g*t);
	printf("%d\n", c[i]);
}

system("PAUSE");

return 0;

}
