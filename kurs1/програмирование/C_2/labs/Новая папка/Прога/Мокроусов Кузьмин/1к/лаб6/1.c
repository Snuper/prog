# include <stdio.h>
#include <stdlib.h>

const int n=20; 
int random (int N) { return rand() % N; }
main()
{
int i, c[n], a=-10, b=10;
printf("Massiv c : %d");
for (i=0; i<n; i++)  {
c[i]= random(b-a+1)+a;
printf(" %d ", c[i]);
}
printf("\nElementy >0: ");
for (i=0; i<n; i++) 
	{
		if (c[i]>0) printf("%d ", c[i]);
		}
printf("\n Elementy <0: ");
for (i=0; i<n; i++) 
	{
		if (c[i]<0) printf( "%d ", c[i]);
	}
	printf( "\n");
system("PAUSE");

return 0;

}
