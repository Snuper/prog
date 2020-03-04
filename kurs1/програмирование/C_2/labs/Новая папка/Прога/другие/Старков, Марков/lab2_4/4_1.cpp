#include <locale>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

 
int main()
{
 
    setlocale(LC_ALL, "rus");
    srand(time(0));
 int row,col,ii,jj,max,i=0,j=0;
    int N;
    int M;
 
    printf("print N\n");
    scanf("%d",&N);
    printf("\nprint M\n");
    scanf("%d",&M);
    
 
    int **B = new int*[N];
 
    for (int count = 0; count < N; count++)
        B[count] = new int[M];
 
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < M; col++)
        {
          B[row][col] = 1 + rand() % 100;
            printf("\t%d",B[row][col]);
        }
        printf("\n\n");
    }
    max=B[0][0];    
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < M; col++)
        {
         if(max<B[row][col]){max=B[row][col];ii=row;jj=col;}
           
        }
        
    }
    printf("%d,%d,%d",max,ii,jj);
    
     
   int **C = new int*[N-1];
 
    for (int count = 0; count < N-1; count++)
        C[count] = new int[M-1];
    
	
	
        
        
        for(row = 0; row < N; row++)
    {    if(ii==row) continue;
       
        for(col = 0; col < M; col++)
        { if(jj==col) continue;
		
         C[i][j]=B[row][col];
          j++; 
        }
        i++;
        j=0;
    }
    
       for(row = 0; row < N-1; row++)
    {
        for(col = 0; col < M-1; col++)
        {
          
            printf("\t%d",C[row][col]);
        }
        printf("\n\n");
    }
        
    
    
 
    
	
	
	
	
	
	for (int count = 0; count < N; count++)
        delete [] B[count];
 
    delete [] B;
 
    system("pause");
    return 0;
}
