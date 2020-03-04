#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main(){ 	
	int *b,*c,*d;  
  	int i,n,m,k; 
  	printf("\n razmer massiva: ");
  	scanf("%d",&n);
  	b=(int *) malloc(n*sizeof(int));
 	if ( b == NULL )  
 	{  
     	printf(" error massiv b ");
    	return 1; 
 	}
  	for (i=0;i<n;i++){
  		if(b[i]>0)	m++;
  		if(b[i]<0)	k++;
    	b[i]=rand()%100-50;
  		printf("b[%d]=%d ",i,b[i]);
  	}
  	printf("\n");
  	c=(int *) malloc(m*sizeof(int));
 	if ( c == NULL )  
 	{  
     	printf(" error massiv c ");
    	return 2; 
 	}
	d=(int *) malloc(k*sizeof(int));
 	if ( d == NULL )  
 	{  
     	printf(" error massiv d ");
    	return 3; 
 	}
  	for (i=0,m=0,k=0;i<n;i++){
  		if(b[i]>0)	{
  			c[m]=b[i];
			m++;	
		}
		if(b[i]<0)	{
  			d[k]=b[i];
			k++;	
		}	
	}
	for (i=0;i<m;i++)	printf("c[%d]=%d ",i,c[i]);
	printf("\n");
	for (i=0;i<k;i++)	printf("d[%d]=%d ",i,d[i]);
  	free(b);
  	b=NULL;
  	free(c);
  	c=NULL;
  	free(d);
  	d=NULL;
  	getch();
  	return 0;
}
