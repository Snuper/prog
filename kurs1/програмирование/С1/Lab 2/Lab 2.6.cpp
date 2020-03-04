#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d, max = 0, min = 0;
	printf("Input 4 numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a > b and a > c and a > d)
	{
		max = a;
	}
	if (b > a and b > c and b > d)
	{
		max = b;
	}
	if (c > a and c > b and c > d)
	{
		max = c;
	}
	if (d > b and d > c and d > a)
	{
		max = d;
	}
	if (a <= b and a <= c and a<= d)
	{
		min = a;
	}
	if (b <= a and b <= c and b <= d)
	{
		min = b;
	}
	if (c <= a and c <= a and c <= d)
	{
		min = c;
	}
	if (d <= b and d <= c and d <= a)
	{
		min = d;
	}
	max = max - min;
	printf("Eto = %d",max);
	system("PAUSE");
	return 0;
}
