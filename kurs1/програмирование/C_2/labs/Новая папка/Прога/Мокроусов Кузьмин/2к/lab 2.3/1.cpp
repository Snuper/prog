#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main()
{ int *p,*n1,*n2; 
  int i,n=5,b=0,m=0; 

  p=(int *) malloc(n*sizeof(int));
  if ( p == NULL ) 
 {  
     printf(" Не удалось выделить память ");
    return 1; 
 }
  for (i=0;i<n;i++)
  {  printf("p[%d]=",i);
     scanf("%d",&p[i]);
     if(p[i]<0) m++;
     else b++;
  }
    
   n1=(int *) malloc(m*sizeof(int));
   n2=(int *) malloc(b*sizeof(int));
  if ( n1 == NULL and n2 == NULL ) 
 {  
     printf(" Не удалось выделить память ");
    return 1; 
 }
 m=0;
 b=0;
  for (i=0;i<n;i++)
  {
  if(p[i]<0){
  n1[m]=p[i];
  m++;	   
  } 
  else
  {
  n2[b]=p[i];
  b++;
	 }
  }
  
  
    //printf("%d  %d",m,b);
  //puts("\n");  

  for (i=0;i<m;i++)  
     printf("\t n1[%d] = %i",m,n1[i]);
      puts("\n");   
     
  for (i=0;i<b;i++)  
     printf("\t n2[%d] = %d",b,n2[i]);
     
  free(p);
  p=NULL;
  getch();
  return 0;
}

