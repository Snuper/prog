#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, max;
	printf("Input 3 numbers: ");
	scanf("%d %d %d", &a, &b, &c);
	printf("DO: %d %d %d\n", a, b, c);
	if (a > b and a > c)
	{
		max = a;
		if (b >= c)
		{
			a = c;
			c = max;
		}
		else
		{
			a = b;
			b = max;
		}
	
	}
 else	if (b > a and b > c)
	{
		max = b;
		if (a >= c)
		{
			b = c;
			c = max;
		}
		else
		{
			b = a;
			a = max;
		}
	
		
	}
else	if (c > a and c > b)
	{
		max = c;
		if (a >= b)
		{
			c = b;
			b = max;
		}
		else
		{
			c = a;
			a = max;
		}
	}
	//max=a>b>c ? b>a>c :c>b>a
	printf("Posle: %d %d %d\n", a, b, c);
	system("PAUSE");
	return 0;
}
