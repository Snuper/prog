#include<stdio.h>
#include<stdlib.h>
main()
{int n,i,k;
system("CLS");
printf ("Vvedite n ");
scanf ("%d", &n);
i= 2;
k=0;
while (i<=n)
{ while (n%i!=0) { i++ ;}
if (i==n) {printf("%d \n",n); k++;}
n--;
i=2;
}
printf(" kolichestvo=%d \n",k);
system("PAUSE");
return 0;
}
