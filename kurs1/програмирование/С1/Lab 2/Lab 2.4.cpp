#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d, e, f, a1, b1, P = 0, O = 0;
	printf("Input 8 numbers: ");
	scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &a1, &b1);
	a > 0?P++:O++;
	b > 0?P++:O++;
	c > 0?P++:O++;
	d > 0?P++:O++;
	e > 0?P++:O++;
	f > 0?P++:O++;
	a1 > 0?P++:O++;
	b1 > 0?P++:O++;
	printf("Otricatel = %d \n Polozhitel = %d \n",O,P);
	system("PAUSE");
	return 0;
}
