#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d, e, sum = 0;
	printf("Input 5 numbers: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if (a >= 0) sum += a;
	if (b >= 0) sum += b;
	if (c >= 0) sum += c;
	if (d >= 0) sum += d;
	if (e >= 0) sum += e;
	printf("summ = %d\n",sum);
	system ("PAUSE");
	return 0;
}
