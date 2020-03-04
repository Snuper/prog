#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int random (int N) { return rand()%N; }
main()
{int i,j=0,g,q,t,k=50, m=0,n;
float *a,*b;
printf("Vvedite n  ");
scanf ("%d",&n);
a=new float[n];
if (a==NULL)
{ printf("Cannot allocate memory");
return 1;
}
b=new float [n];
if (b==NULL)
{ printf("Cannot allocate memory");
return 1;
}
	srand(time(NULL));
for (i=0;i<n;i++)
{
*(a+i)=(float)rand()*(k-m)/RAND_MAX + m;;
}
for (i=0;i<n;i++)
{
 b[j]=*(a+i);
 j++;
}
  for(j=0;j<n;j++){
  	g = j;
		for( q=j+1; q<n; q++){
	   		if (b[q]<b[g])g=q;
		}
		t=b[j];
		b[j]=b[g];
		b[g]=t; 
}

for (i=0;i<n;i++)
	printf("  a[%d]=%4.2f  ",i,a[i]);
	puts("\n");
	for(j=0;j<n;j++)
	printf("  b[%d]=%4.2f  ",j,b[j]);
	puts("\n");
	delete a;
	delete b;
	a=NULL;
	b=NULL;
	getch();
	return 0;
}
