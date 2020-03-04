#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чисел
const int m=4, n=4; 
int random(int r)
{  return rand()%r;
} 
main()
{
 int n=10,m=20,a[n][m],i,j,t;
 system("CLS");
	for(i=0;i<n;i++)
   	for(j=0;j<m;j++)
     a[i][j]=random(20);

	printf(" === Stariy === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<m;j++)
     printf("%2d ",a[i][j]); //2D>3D
 }
 
 	for(i=0;i<n;i+=2)
   	for(j=0;j<m;j++)
   	{	t=a[i][j];
		a[i][j]=a[i+1][j];	  
		a[i+1][j]=t; 
	   }
	
	printf("\n === Noviy === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<m;j++)
     printf("%2d ",a[i][j]); 
}
 system("PAUSE");
}

