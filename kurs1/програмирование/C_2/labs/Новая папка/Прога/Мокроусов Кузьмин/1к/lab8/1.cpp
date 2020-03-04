#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{ system("CLS");
int i,N=10;
float h, a=-2.0, b=5.0, c[N+1], I1=1.0, I2=1.0, x;
h=(b-a)/N;
printf("h= %5.2f", h);
printf("\nMassiv c(funkcia F(x)): ");
for (i=0, x=a; i<=N, x<=b; i++, x+=h) 
	{
	c[i]=pow(x,2)/(10 + pow(x,3));
	printf("%5.2f ", c[i]);
	}
printf("\nIntegral po f-le trapecij:");
	I1=h*(c[0]/2+c[1]+c[2]+c[3]+c[4]+c[5]+c[6]+c[7]+c[8]+c[9]+c[N]/2);
	printf("%5.2f ", I1);
printf("\nIntegral po f-le Simpsona:");
	I2=h/3*(c[0]+c[N]+4*(c[1]+c[3]+c[5]+c[7]+c[9])+2*(c[2]+c[4]+c[6]+c[8]));
	printf("%5.2f ", I2);

system("PAUSE");

return 0;

}
