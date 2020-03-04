#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d, max1 = 0, max2 = 0;
	printf("Input 4 numbers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	//max1
	max1 = a; 
	if (b > max1) max1 = b;
	if (c > max1) max1 = c;
	if (d > max1) max1 = d;
	//max2
	max2=-max1;
	if (a > max2 and a != max1) max2 = a;
	if (b > max2 and b != max1) max2 = b;
	if (c > max2 and c != max1) max2 = c;
	if (d > max2 and d != max1) max2 = d;
	
	printf("max1: %d \n max2: %d \n", max1, max2);
	system("PAUSE");
	return 0;
}
