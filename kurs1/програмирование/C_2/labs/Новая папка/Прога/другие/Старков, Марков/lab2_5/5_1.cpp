#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 main()
{ int *A, **B, m,k,row,col,res,KK=0;
printf("vvedite m"), scanf("%d",&m);
printf("vvedite k"), scanf("%d",&k);

A= new int[m];
for(row=0;row<m;row++){
A[row]=rand()%100;
printf("%d ",A[row]);
}
res=m/k;
if(m%k)
res++;
 printf("\n**********************************************************************\n");

 B = new int*[res];
 
    for (int count = 0; count < res; count++)
        B[count] = new int[k];
        
          
		  
		  
		  for(row = 0; row < res; row++)
    {
        for(col = 0; col < k; col++)
        { 
          B[row][col]=A[KK];
          //printf("%d ",KK);
          if(m<=KK) B[row][col]=0;
          KK++;
          printf("\t%d ",B[row][col]);
        }
        printf("\n");
    }
       system ("PAUSE"); 
        
 }
 
 

