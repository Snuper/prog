#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чисел
const int m=4, n=4; 
int random(int r)
{  return rand()%r;
} 
main()
{
 int n=5,i,j,t[n];
 float c[n][n],a[n][n];
 system("CLS");
 t[0]=0;
  t[1]=0;
   t[2]=0;
    t[3]=0;
     t[4]=0;
	for(i=0;i<n;i++)
   	for(j=0;j<n;j++){
    	a[i][j]=random(20);
    	t[i]+=a[i][j];
} 
	printf(" === Stariy === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<n;j++)
     printf("%5.2f ",a[i][j]); //Hochu krijovnik
 }
printf("\n");

 	for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
    	c[i][j]=a[i][j]/t[i];


printf(" === Noviy === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<n;j++)
     printf("%6.4f ",c[i][j]); 
 }
 printf("\n");
 system("PAUSE");
}

