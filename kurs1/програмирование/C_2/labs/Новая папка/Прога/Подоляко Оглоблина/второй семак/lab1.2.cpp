#include <stdio.h>
#include <conio.h>
#include <math.h>
double cosinus( double x);
main( )
{
	float a,m,z;

	printf("input a ");
	scanf ( "%f",&a);
	printf("cosx=%f\n",cos(a));
	z=cosinus(a);
	printf("cosinusx=%4.4f",z);
	getch();
}
double cosinus(double x)
{
    double n = 1.0;
    double sum = 0.0;
    int i = 1;
 
    do
    {
        sum += n;
        n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
        i++;
    }
    while (fabs(n) > 0.0001);
 
    return sum;
}

