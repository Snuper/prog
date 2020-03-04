#include <stdio.h>
#include <stdlib.h>

const int N = 20;
main()
{
int i,j,c[N],d[N],e[40],o,p,v;

for(i=0;i<=N;i++)
{c[i]=rand()%20;
printf("%d ",c[i]);}
printf("\n");
for ( i = 0; i < N-1; i ++ )
for ( j = N-2; j >= i; j -- ) 
if (c[j] > c[j+1] ) 
{
o = c[j];
c[j] = c[j+1];
c[j+1] = o;
}

for(i=0;i<=N;i++)
{d[i]=rand()%20;
printf("%d ",d[i]);}
printf("\n");
for ( i = 0; i < N-1; i ++ )
for ( j = N-2; j >= i; j -- ) 
if ( d[j] > d[j+1] ) 
{
o = d[j];
d[j] = d[j+1];
d[j+1] = o;
}
p=0;
v=0;
for(i=0;i<40;i++){
	if(c[p]<d[v]) 
	{e[i]=c[p];
	p++;}
	else {
	e[i]=d[v];
	v++;
	}
	printf("%d ",e[i]);}
system("PAUSE");
return 0;
}

