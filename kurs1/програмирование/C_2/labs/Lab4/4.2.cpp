#include <stdlib.h>
#include <stdio.h>
#include <time.h>




main()
{ int i,j,k,n,s,m,x=0;
  int **p,**a;
  srand(time(NULL));
  printf (" Input: "); 
  scanf ("%d%d", &n,&m); 
  p = new int* [n];
  for (i=0;i<n;i++)
  p[i] = new int [m];  
  if ( p == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  } 
  a = new int* [n+1];
  for (i=0;i<=n;i++)
  a[i] = new int [m+1];  
   if ( a == NULL )
  {  
     printf("\n ERROR ");
    return 1; 
  }
  for (i = 0; i < n; i ++ ){
  for (j=0;j<m;j++)
  { 
     p[i][j]=rand()%20;
  }}
 for (i = 0; i < n; i ++ ){
  for (j=0;j<m;j++)
  { 
    printf("%4d ",p[i][j]);
  } puts("\n");}
  puts("\n");
  a[n][m]=0;
  for (i = 0 ; i < n ; i++ ){
  	k=0;
  	for (j = 0 ; j < m ; j++ ){
  		a[i][j]=p[i][j];
  		
  		a[n][m]+=p[i][j];
  		k+=p[i][j];
  		if (j==m-1){
  			a[i][m]=k;
		  }
	  }
  }  
  for (i=0;i<n;i++)
  a[n][i]=0;
  for (j = 0 ; j < m ; j++ ){
  	for (i = 0 ; i < n ; i++ ){
  		a[n][i]+=a[j][i];
		  }
	  }
  
  //printf("\n%4d\n ",a[n][m]);
   for (i = 0; i <=n; i ++ ){
  for (j=0;j<=m;j++)
  { 
    printf("%4d ",a[i][j]);
  } puts("\n");}
  for (i=0;i<n;i++)
  delete[]p[i];
  for (i=0;i<=n;i++)
  delete[]a[i];
  system("PAUSE");
  return 0;
}
