#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 60;
main()
{
float a=2.14,b=-4.21,c=3.25,d,xn=-4.5,xb=-33.5,m[N];
int i,j;
for(i=0;i<=N;i++)
{m[i]=a*pow(xn,2)*sin(xn)+b*xn+c;
xn-=0.5;
}
for ( i = 0; i < N-1; i ++ )
for ( j = N-2; j >= i; j -- ) 
if ( m[j] < m[j+1] ) 
{
d = m[j];
m[j] = m[j+1];
m[j+1] = d;
}
for ( i = 0; i < N; i ++ )
printf("%7.2f \n", m[i]);
system("PAUSE");
return 0;
}

