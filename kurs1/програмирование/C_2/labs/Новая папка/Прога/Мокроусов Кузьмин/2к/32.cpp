#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
  	int i,n; 
	float temp;
  	float *a;
	float *b; 
  	printf (" razmer massiva -> "); 
  	scanf ("%d", &n);
  	a = new float [n];
  	b = new float [n];
  	if ( a == NULL ) 
	{  
    	printf(" error a ");
    	return 1; 
 	}
 	if ( b == NULL ){	  
    	printf(" error b ");
    	return 1; 
 	}
 	for (i = 0; i < n; i ++ ) 
 	{ 
 		a[i]=(float)rand()/ RAND_MAX;
   		b[i]=*(a+i);
 	}
 	for (int j=0;j<n-1;j++){
 		for (i = 0; i < n-j-1; i ++ ) {
 			if(*(b+i)>*(b+(i+1))){
 				temp=*(b+i);
      			*(b+i)=*(b+(i+1)); 
      			*(b+(i+1))=temp;	
			}	
		}
	}
 	for (i = 0; i < n; i ++ ) 
    printf ("a[%d] = %f ", i,a[i]);
 	puts("\n"); 
 	for (i = 0; i < n; i ++ ) 
    printf ("b[%d] = %f ", i,b[i]);  
 	delete a;
	delete b; 
 	a=NULL;
	b=NULL;
 	getch();
 	return 0;
}
