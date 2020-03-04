#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

int main()
{
	int a = 2, n, s = 0, p=0,K=0;
	printf("Vvedite n: ");
	scanf("%d", &n);
	while(a <= n)
	{
		
		if ((a % 2) == 0 and a != 2) 
		{
		s++;
		}
		else if ((a % 3) == 0 and a != 3)
		{
		s++;
		}
		else if ((a % 5) == 0 and a != 5) 
		{
		s++;
		}	
	    else if ((a % 7) == 0 and a != 7)
		{
		s++;
		}
		for (int j=1;j<=a;j++)
		if(a%j==0)
		p++;
		if(p==2)
		printf("%d \n",a);
		p=0;
	    a++;
		
	}
    K = n - 1 -s;
	printf("Postih chisel: %d \n", K);
	system("PAUSE");
	return 0;
}
