#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
const int n=5;
typedef int rown[n];
main()
{
int i,j,m,max,maxi,maxj;
rown *b;
rown *c;
printf ( "Chislo strok ");
scanf ( "%d", &m );
b = new rown[m];
if ( b == NULL )
{ 
	printf("Ne udalos vydelit");
	return 1;
}
c=new rown[m-1];
if ( b == NULL )
{ 
	printf("?Ne udalos vydelit");
	return 1;
}
for (i=0; i<m; i++)
{ 
	for (j=0; j<n; j++)
	{ 
		b[i][j]=rand()%11;
		printf("%4d",b[i][j]);
	}
puts("\n");
}
max=0; maxi=0;maxj=0;
for (i=0; i<m; i++)
{ 
	for (j=0; j<n; j++)
	if (b[i][j]>max)
	{
		max=b[i][j];
		maxi=i;
		maxj=j;	
	}
}
puts("\n");
for (i=0; i<m; i++)
{ 
	for (j=0; j<n; j++)
	{ 
	    if(i!=maxi and j!=maxj)
	    {
	    	c[i][j]=b[i][j];
			printf("%4d",c[i][j]);
		}
	}
if(i!=maxi)
puts("\n");
}
delete b;
delete c;
puts("\n");
system("pause");
return 0;
}
