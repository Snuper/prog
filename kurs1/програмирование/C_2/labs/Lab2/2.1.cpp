#include <stdlib.h>
#include <stdio.h>

void recourse(int x)
{
	printf (" ");
	scanf("%d", &x);
	if (x > 0) 
	{
        printf ("%d", x);
        recourse(x);
    }
	if (x < 0) 
	recourse(x);
	if (x == 0) return;
}
main()
{
	recourse(0);
	system ("PAUSE");
	return 0;
}
