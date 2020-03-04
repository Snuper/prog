#include <stdlib.h>
#include <stdio.h>
#include<math.h>
main()
{
system("CLS");
int N;
printf("N=");
scanf("%d",&N);
int i;N;
float a,b,x,y,s,h,c,d,k,m,F1,F2,A[N+1];
a=0.1;b=2.1;s=0;F1=0;c=0;d=0;F2=0;h=(b-a)/float(N);
for (i=0,x=a;i<=N,x<=b+0.001;i++,x=x+h)
{
A[i]=1/((0.5+0.1*x*x*x)*sqrt(x));
printf ("A[%d]=%f\n",i,A[i]);
}
for (i=1;i<=(N-1);i++) {
s=s+A[i];}
F1=h*(s+A[0]/2+A[N]/2);
printf ("F1=%f\n",F1);
N=N+1;
for (i=1;i<(N-1);i=i+2) {
c=c+A[i];}
for (i=2;i<=(N-2);i=i+2) {
d=d+A[i];}
k=4*c;m=2*d;
F2=(h/3)*(A[0]+A[N-1]+k+m);
printf ("F2=%f\n",F2);
system("PAUSE");
return 0;
}
