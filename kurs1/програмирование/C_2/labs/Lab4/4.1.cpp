#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int n=5;
const int c=4; 
typedef int rown[n];
typedef int rowny[c];
main()
{
 int i,j,m,k=0,l=0,e=0,x=0;
 rown *a;
 rowny *b;
 srand(time(NULL));    
 printf ( "Chislo strok?  ");
 scanf ( "%d", &m );
 a = new rown[m]; 
                                
 if ( a == NULL ) 
 {   printf("Error");
    return 1; 
 }
 b = new rowny[m-1]; 
                                
 if ( b == NULL ) 
 {   printf("Error");
    return 1; 
 }
  for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
    { a[i][j]=rand()%200;
      printf("%4d ",a[i][j]);
    }
    puts("\n");
 } 
 puts("\n");
 for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
    { if (a[i][j]>a[k][l]){k=i; l=j;
	}
    }
 }
 printf("%4d ",a[k][l]);
 puts("\n");
   for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
    { if ((i!=k)&&(j!=l)){b[e][x]=a[i][j]; 
	                       printf("%4d ",b[e][x]);
	                       e++;
                           x++;
	                     }
      
    }
    if (i!=k)puts("\n");
 }
          
 delete a;
 a=NULL; 
 delete b;
 b=NULL; 
 system("PAUSE");
 return 0;
}
