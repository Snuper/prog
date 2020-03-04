#include<stdio.h>
#include<stdlib.h>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
	float a,b,c,x0,xk,h,min,max,y;
	min=1000000; max=-1000000; a=2.14;  b=-4.21;  c=3.25; x0=-4.5; xk=-13.5; 
	while (x0>=xk)
	{ y=(a*x0*x0+b*x0+c)*sin(x0);
	x0=x0-0.5;
	if (y>max) max=y;
	if (y<min) min=y;
	printf("y=%5.3f\n",y);
	}
	printf("\n  max=%5.3f\n  min=%5.3f\n",max,min);
system("PAUSE");
return 0;
}
