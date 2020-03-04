#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чисел
const int m=4, n=4; 
int random(int r)
{  return rand()%r;
} 
main()
{
 int n=5,i,j,t[n],a[n][n],b[n][n];
 system("CLS");
	for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
    	a[i][j]=random(20);

	printf(" === Stariy === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<n;j++)
     printf("%2d ",a[i][j]); //Vipiem za lubov'
 }
printf("\n");

 	for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
    	b[j][i]=a[i][j];


printf(" === Noviy === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<n;j++)
     printf("%2d ",b[i][j]); 
 }
 printf("\n");
 system("PAUSE");
}

