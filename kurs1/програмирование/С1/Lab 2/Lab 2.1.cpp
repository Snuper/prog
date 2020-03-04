#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int a, b, c, d, e, f, sum = 0, pro = 0;
	printf("Input 6 numbers: ");
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	sum = a + b + c + d + e + f;
	pro = a * b * c * d * e * f;
	if (sum>=pro)
	{
		sum -= pro;
		printf ("Summ > na %d \n",sum);
	}
	else
	{
		pro -= sum;
		printf("Proizved > na %d \n",pro);
	}
	system("PAUSE");
	return 0;
}

