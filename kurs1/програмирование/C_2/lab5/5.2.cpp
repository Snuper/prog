#include <stdlib.h>
#include <stdio.h>
#include <time.h>




main()
{ int i,j,n;
  int **p;
  srand(time(NULL));
  printf (" Input: "); 
  scanf ("%d", &n); 
  p = new int* [n];
  for (i=0;i<n;i++)
  p[i] = new int [i+1];  
  if ( p == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  }
  for (i=0; i<n; i++)
  for (j=0; j<=i; j++)
  p[i][j]=0;
  for (i=0; i<n; i++){
  for (j=0; j<=i; j++){
  p[i][j]+=(i+1)*(j+1);
  printf("%4d ",p[i][j]);
  
}
  puts("\n");}
  for (i=0;i<n;i++)
  delete[]p[i];
  system("PAUSE");
  return 0; 
}
