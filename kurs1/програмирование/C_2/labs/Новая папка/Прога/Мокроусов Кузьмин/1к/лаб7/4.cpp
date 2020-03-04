#include <stdio.h>
#include <stdlib.h>

int random (int N) { return rand() % N; }
const int N = 20;
main()
{
int i, c[N], d[N], b=20, a=0, j, k;
printf("Massiv c: ");
for ( i = 0; i < N; i ++ ) {
	c[i] = random( b - a + 1 ) + a;
	printf("%d ", c[i]);
}
printf("\nMassiv d: ");
for ( i = 0; i < N; i ++ ) {
	d[i] = random( b - a + 1 ) + a;
	printf("%d ", d[i]);
}

 for ( i = 0; i < N-1; i ++ ) 
 for ( j = N-2; j >= i; j -- ) 
 if ( c[j] > c[j+1] ) 
 {
 k = c[j];
 c[j] = c[j+1]; 
 c[j+1] = k;
 }
printf("\nMassiv C2: ");
for (i=0; i<N; i++) printf("%d ", c[i]);

 for ( i = 0; i < N-1; i ++ ) 
 for ( j = N-2; j >= i; j -- ) 
 if ( d[j] > d[j+1] ) 
 {
 k = d[j];
 d[j] = d[j+1]; 
 d[j+1] = k;
 }
printf("\nMassiv D2: ");
for (i=0; i<N; i++) printf("%d ", d[i]);

int e[2*N];
printf("\nMassiv E: ");
for (i=0,j=0,k=0;k<N*2,i<N,j<N;)
{
while((c[i]==d[j])&&(i<N)&&(j<N))
{e[k]=c[i];
e[k+1]=d[j];

i++;
j++;
k+=2;
}
while((c[i]>d[j])&&(i<N)&&(j<N))
{e[k]=d[j];

k++;
j++;
}
while((c[i]<d[j])&&(i<N)&&(j<N))
{e[k]=c[i];	

k++;
i++;}}
if(c[N-1]==d[N-1])
	{
		e[N*2-1]=c[N-1];
	}

for ( i = 0; i < N*2; i++ ) printf("%d ",e[i]);
system("PAUSE");
return 0;
}
