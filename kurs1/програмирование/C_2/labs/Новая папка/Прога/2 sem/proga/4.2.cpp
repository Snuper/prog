#include <stdio.h>
#include <stdlib.h>
main()
{
int i,j,m,n,summa;
printf ( "Chislo strok ");
scanf ( "%d", &m );
printf ( "Chislo stolbsov ");
scanf ( "%d", &n );
int** matrix1;
matrix1 = new int*[m];
for ( i = 0; i < m; i++) 
	matrix1[i] = new int[n];
if ( matrix1 == NULL )
{ 
	printf("Ne udalos vydelit");
	return 1;
}
int** matrix2;
matrix2 = new int*[m+1];
for ( i = 0; i < m+1; i++) 
	matrix2[i] = new int[n+1];
if ( matrix2 == NULL )
{ 
	printf("?Ne udalos vydelit");
	return 1;
}
int *summastobtsov = new int[n];
int *summastrok = new int[m];
for (i=0; i<m; i++)
{ 
	for (j=0; j<n; j++)
	{ 
		matrix1[i][j]=rand()%11;
		printf("%4d",matrix1[i][j]);
	}
puts("\n");
}
puts("\n");
for (i=0; i<m; i++)
{ 
	summastrok[i]=0;
}
for (i=0; i<m; i++)
{ 
	for (j=0; j<n; j++)
	{
	summastrok[i]=summastrok[i]+matrix1[i][j];
	}
}

for (j=0; j<n; j++)
{ 
	summastobtsov[j]=0;
}
for (j=0; j<n; j++)
{ 
	for (i=0; i<m; i++)
	{
	summastobtsov[j]=summastobtsov[j]+matrix1[i][j];
	}
}
summa=0;
for (j=0; j<n; j++)
{ 
	for (i=0; i<m; i++)
	{
	summa=summa+matrix1[i][j];
	}
}

for (i=0; i<m; i++)
{ 
	printf("%4d",summastrok[i]);
}
puts("\n");
for (i=0; i<n; i++)
{ 
	printf("%4d",summastobtsov[i]);
}
puts("\n");
printf("%4d",summa);
puts("\n");
puts("\n");
for (i=0; i<m+1; i++)
{ 
	for (j=0; j<n+1; j++)
	{ 
	    {
	    	if (i==m and j!=n)
	    	{
	    		matrix2[i][j]=summastobtsov[j];
				printf("%4d",matrix2[i][j]);	
			}
		    if (j==n and i!=m)
	    	{
	    		matrix2[i][j]=summastrok[i];
				printf("%4d",matrix2[i][j]);	
			}
			if (j==n and i==m)
	    	{
	    		matrix2[i][j]=summa;
				printf("%4d",matrix2[i][j]);	
			}
			if (j!=n and i!=m)
			{
	    		matrix2[i][j]=matrix1[i][j];
				printf("%4d",matrix2[i][j]);
			}
		}
	}
puts("\n");
}
delete matrix1;
delete matrix2;
puts("\n");
system("PAUSE");
return 0;
}
