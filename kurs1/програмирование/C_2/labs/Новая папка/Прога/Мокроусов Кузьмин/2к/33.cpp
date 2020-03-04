#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
  	int i,n; 
  	int *a;
  	printf (" razmer massiva -> "); 
  	scanf ("%d", &n);
  	a = new int [n+1];
  	if ( a == NULL ) 
	{  
    	printf(" error a ");
    	return 1; 
 	}
 	for (i = 0; i <= n+1; i ++ )	a[i]=i;	
 	for (int p=2;p<n+1;p++){
 		if(a[p]!=0){
 			printf("%d ",a[p]);	
			for (int j = p*p; j < n+1; j +=p )		a[j]=0;
		}	
	} 
 	delete a;
 	a=NULL;
 	getch();
 	return 0;
}
