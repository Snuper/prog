#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d;
	printf("Input 4 numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a <= b and a <= c and a <= d)
	{
		printf("Min = 1");
	}
	else if (b <= a and b <= c and b <= d)
	{
		printf("Min = 2");
	}
	else if (c <= a and c <= b and c <= d)
	{
		printf("Min = 3");
	}
	else if (d <= a and d <= b and d <= c)
	{
		printf ("Min = 4");
	}
	system("PAUSE");
	return 0;
}
