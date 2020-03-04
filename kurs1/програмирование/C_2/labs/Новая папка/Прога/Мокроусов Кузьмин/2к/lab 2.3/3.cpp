#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main()
{ int *p;
  int i,j,n; 
  printf("\n Размер массива: ");
  scanf("%d",&n);
  p=(int *) malloc(n*sizeof(int));
  if ( p == NULL )
 {  
     printf(" Не удалось выделить память ");
    return 1; 
 }
  for (i=2;i<=n;i++) p[i]=i;
  
  for (i=2;i<=n;i++){
  	for(j=i;j<=n;j+=i){
  		if(j != i)
  			p[j]=0;
	  }	
  }
  for (i=2;i<=n;i++)  
  if(p[i]!=0)
     printf("\t p[%d]=%d",i-2,p[i]);
  free(p);
  p=NULL;
  getch();
  return 0;
}

