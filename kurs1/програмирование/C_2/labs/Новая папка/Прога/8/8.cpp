#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main(){
float c[1000];
int i, d;
float x, n, i1, i2, h, s, sc, sn;
printf("vvedite h ");
scanf("%f", &h);
for (i=1, n=-2; n<=5; n=n+h, i++)
c[i]=(n*n)/(10+n*n*n);
for (i=1, n=-2; n<=5; n=n+h, i++)
printf(" %f ", c[i]);
s=0;
for (i=2, n=-2; n<=5-h; n=n+h, i++)
s=s+c[i];
d=7/h;
i1=h*(c[1]+s+c[d]);
printf("i1=%f ", i1);
sn=0;
sc=0;
for (i=2, n=-2; n<=5-h; n=n+h, i++)
{
if(i%2==1) sn=sn+c[i];
if(i%2==0) sc=sc+c[i];
}
i2=h/3*(c[1]+c[d]+sn+sc);
printf("i2=%f ", i2);
system("PAUSE");
}
