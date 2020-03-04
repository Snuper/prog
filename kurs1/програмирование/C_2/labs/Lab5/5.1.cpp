#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>



main()
{ int i,j,k,n=0,s,m,x=0;
  int **b,*a;
  float l;
  srand(time(NULL));
  printf (" Input: "); 
  scanf ("%d%d", &m,&k); 
  
  a = new int [m];
  
   if ( a == NULL )
  {  
     printf("\n ERROR ");
    return 1; 
  }
  for (i=0;i<m;i++)
  a[i]=rand()%20;
  for (i=0;i<m;i++)
  printf("%4d ",a[i]);
  puts("\n");
  s=ceil((float)m/k);
  b = new int* [s];
  for (i=0;i<s;i++)
  b[i] = new int [k];  
  if ( b == NULL ) 
  {  
     printf("\n ERROR ");
    return 1; 
  } 
  for (i=0;i<s;i++){
  	for (j=0;j<k;j++){
  		b[i][j]=0;
  		
	  }
  }
  for (i=0;i<s;i++){
  
  	for (j=0;j<k;j++){
  		if (n<m){
  			b[i][j]=*(a+n);
  			n++;
		  }else{break;
		  }
  	
  }}
   for (i=0;i<s;i++){
  
  	for (j=0;j<k;j++){
  		
  			printf("%4d ",b[i][j]);
  			
  	
  }puts("\n");}
  for (i=0;i<s;i++)
  delete[]b[i];
  delete a;
  a=NULL;
  b=NULL;
  system("PAUSE");
  return 0; 
}
