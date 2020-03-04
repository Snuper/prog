#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{ system("CLS");
int i,N=1000;
float h, a=-2.0, b=5.0, c[N+1], I1=1.0, I2=1.0, x, s,k,l;
h=(b-a)/N;
printf("h= %7.4f", h);
printf("\nMassiv c(funkcia F(x)): ");
for (i=0, x=a; i<=N, x<=b; i++, x+=h) 
	{
	c[i]=pow(x,2)/(10 + pow(x,3));
	printf("%7.4f ", c[i]);
	}
printf("\nIntegral po f-le trapecij:");
    for (i=1, s=c[0]/2; i<N; i++) s+=c[i];
    s+=c[N]/2;
	I1=h*s;
	printf("%7.4f ", I1);
printf("\nIntegral po f-le Simpsona:");
	for (i=1, s=c[0]+c[N],k=0,l=0; i<N; i++) { if (i%2==0) k+=c[i]; else l+=c[i];}
    
    
    I2=(h/3)*(s+4*l+2*k);//( c[0]+c[N] + 4*(c[1]+c[3]+c[5]+c[7]+c[N-1]) +2*(c[2]+c[4]+c[6]+c[N-2]));
	printf("%7.4f ", I2);

system("PAUSE");

return 0;

}
