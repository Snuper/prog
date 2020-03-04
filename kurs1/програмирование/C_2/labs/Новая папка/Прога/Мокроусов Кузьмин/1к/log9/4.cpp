#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //для генерации случайных чисел
const int m=4, n=4; 
int random(int r)
{  return rand()%r;
} 
main()
{
 int n=3,i,j,a[n][n],c=0,g[n],v[n],p[2];
 system("CLS");
 g[0]=0;
 g[1]=1;
 g[2]=0;
 v[0]=0;
 v[1]=1;
 v[2]=0;
 p[0]=0;
 p[1]=1;
	for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
    	a[i][j]=random(3);

while (g[0]!=g[1] || g[1]!=g[2] || v[0]!=v[1] || v[1]!=v[2] || v[0]!=p[0] || p[1]!=p[0])  {
	g[0]=0;
	g[1]=0;
 	g[2]=0;
 	v[0]=0;
 	v[1]=0;
 	v[2]=0;
 	p[0]=0;
 	p[1]=0;
 	
	for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
    	a[i][j]=random(3);
    	
	for(i=0;i<n;i++)
   	for(j=0;j<n;j++){
    	g[i]+=a[i][j];
		v[j]+=a[i][j];
		if(i==j) p[0]+=a[i][j];
		if(i==n-j-1) p[1]+=a[i][j];}
	c++;
}
	printf(" === Koldunskiy kvadrat === ");
 	for (i=0;i<n;i++)
 	{ printf("\n");
   	for (j=0;j<n;j++)
     printf("%2d ",a[i][j]); // Mujiki, mojet ne nado
 }
 printf("\n Skoka raz - %2d ",c);

 system("PAUSE");
}
