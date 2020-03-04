#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d;
	printf("Input 5 numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf(" DO ryad: %d %d %d %d \n", a, b, c, d);
	if (a <= 0) a = 0;
	if (b <= 0) b = 0;
	if (c <= 0) c = 0;
	if (d <= 0) d = 0;
	printf("POSLE ryad: %d %d %d %d \n", a, b, c, d);
	system("PAUSE");
	return 0;
}
