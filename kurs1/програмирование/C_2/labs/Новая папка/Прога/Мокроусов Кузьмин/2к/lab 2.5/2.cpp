#include <stdio.h>
#include <stdlib.h>

main()
{
 int i,j,n=10;
 int **a;   
  
 a = new int*[n];
 for (int i = 0; i < n; i++)
        a[i] = new int [i+1];
        
if ( a == NULL ) 
{   
	printf("Не удалось выделить память");
    return 1; 
}

//===================================================================

  for (i=1; i<n; i++)
 {  for (j=1; j<=i; j++)
    {
    	a[i][j]=i*j;
    }
 } 

 puts("\n");
          
for (i=1; i<n; i++){
  for (j=1; j<=i; j++) printf("  %i",a[i][j]);
 puts("\n");
}
          
 delete a;

 puts("\n");
 system("PAUSE");
 return 0;
}


