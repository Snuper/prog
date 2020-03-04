#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>




main()
{ int i,j,n,l;
  int **p;
  int *a;
  srand(time(NULL));
  printf (" Input: "); 
  scanf ("%d", &n); 
  p = new int* [n];
  for (i=0;i<n;i++){
  l=rand()%n+2;
  p[i] = new int [l];
  p[i][0]=l;
}
  if ( p == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  }
  a = new int [n];
  if ( a == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  }
  for (i=0;i<n;i++){
  	for (j=1;j<p[i][0];j++){
  		p[i][j]=rand()%100;
	  } 
  }
   for (i=0;i<n;i++){
  	for (j=1;j<p[i][0];j++){
  		a[i]=0;
	  } 
  }
  for (i=0;i<n;i++){
  	for (j=1;j<p[i][0];j++){
  		a[i]+=p[i][j];
	  } 
  }
   for (i=0;i<n;i++){
  	for (j=0;j<p[i][0];j++){
  		printf("%4d ",p[i][j]);
	  }puts("\n");
  }
  puts("\n");
  for (i=0;i<n;i++)
  	printf("%4d ",a[i]);
	  puts("\n");
  for (i=0;i<n;i++){
    delete[]p[i];
    p[i]=NULL;
 }
  delete a;
  a=NULL;
  p=NULL;
  getch();
  return 0; 
}
