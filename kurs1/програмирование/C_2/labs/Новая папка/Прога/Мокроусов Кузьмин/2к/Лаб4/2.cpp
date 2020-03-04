#include <stdio.h>
#include <stdlib.h>

main()
{
 int i,j,n,m,s1=0,s2=0;
 int **a,**b;   
 printf ( "Строки - ");
 scanf ( "%d", &n );
 printf ( "Столбцы - ");
 scanf ( "%d", &m );
 a = new int*[n];
 for (int i = 0; i < n; i++)
        a[i] = new int [m];
        
 b = new int*[n+1];
 for (int i = 0; i <= n; i++)
        b[i] = new int [m+1];
 
if ( a == NULL ) 
{   printf("Не удалось выделить память");
    return 1; 
}

if ( b == NULL ) 
{   printf("Не удалось выделить память");
    return 1; 
}
//===================================================================
for (j=0; j<m; j++) b[n][j]=0;
  for (i=0; i<n; i++)
 {  for (j=0; j<m; j++)
 
    { a[i][j]=rand()%11;
      printf("%4d",a[i][j]);
      b[i][j]=a[i][j];
      s1+=a[i][j];
      b[n][j]+=a[i][j];

    }
    puts("\n");
    b[i][j]=s1;
    s2+=s1;
    s1=0;
 } 
b[n][m]=s2;
 
 puts("\n");
          
for (i=0; i<=n; i++){
  for (j=0; j<=m; j++) printf("%i  ",b[i][j]);
 puts("\n");
}
          
 delete a;
 delete b; 

 puts("\n");
 system("PAUSE");
 return 0;
}

