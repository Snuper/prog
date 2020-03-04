#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
int n, i, k = 0, sum = 0;
printf("Input kol-vo chisel v nomere card: ");
scanf("%d",&n);
//zapolnenie
int C[n];
for (i = 0; i < n; i++)
	{
	scanf("%d",&k);
	C[i] = k;
	printf("C[%d] = %d\n", i, C[i]);
	}
	
printf("Nomer card: "); //utochnenie
for (i = 0; i < n; i++)
	{
		printf("%d ",C[i]);
	}
printf("\n");
//chetnie
for (i = 1; i < n; i += 2)
{
	sum += C[i];
}
//nechetnie
for (i = 0; i < n; i += 2)
{
	if (C[i] * 2 < 9)
	{
			sum += C[i] * 2;
	}
	else
	{
		sum += C[i] * 2;
		sum -= 9;
	}
}
//proverka
printf("sum=%d", sum);
if (sum % 10 == 0)
{
	printf("Card is true\n");
}
else
{
	printf("Card is false\n");
}

system("PAUSE");
return 0;

}
