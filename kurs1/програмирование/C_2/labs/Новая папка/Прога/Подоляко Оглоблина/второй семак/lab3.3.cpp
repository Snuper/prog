#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main()
{ 
int *a;
int i,p,n,j;
printf("Vvedite n ");
scanf ("%d",&n);
a=new int[n+1];
if (p==NULL)
{ printf("Cannot allocate memory");
return 1;
}
for (int i = 0; i < n + 1; i++)
    a[i] = i;
 for (int p = 2; p < n + 1; p++)
  {
    if (a[p] != 0)
    {
      printf("\n %d",a[p]);
      for (j = p*p; j < n + 1; j += p)
        a[j] = 0;
    }
  }
	delete a;
	p=NULL;
	getch();
	return 0;
}
