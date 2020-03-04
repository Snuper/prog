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
 int row,col,colsum=0,rowsum,max=0;
    int N;
    int M;
 
    printf("print N\n");
    scanf("%d",&N);
    printf("\nprint M\n");
    scanf("%d",&M);
    
 
    int **A = new int*[N];
 
    for (int count = 0; count < N; count++)
        A[count] = new int[M];
 
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < M; col++)
        {
          A[row][col] = 1 + rand() % 100;
            printf("\t%d",A[row][col]);
        }
        printf("\n\n");
    }
printf("\n\n*********************************************************\n");
     
	 int **D = new int*[N+1];
 
    for (int count = 0; count < N+1; count++)
        D[count] = new int[M+1];
 
    
	
	
	
	rowsum=0;
      for(row = 0; row < N; row++)                //stroki
    {
        for(col = 0; col < M+1; col++)
        {
          D[row][col]=A[row][col];
          if(M>col)rowsum+=A[row][col];
          if(M==col) {D[row][col]=rowsum;}
            
            
        }
     
        printf("\n\n");
        rowsum=0;
    }
    
    
       for(col = 0; col < M+1; col++){             //stolbiki
       	for(row = 0; row < N+1; row++){
       		if(N>row)colsum+=A[row][col];
       		if(N==row)D[row][col]=colsum;
       		
		   }
       	
       	colsum=0;
	   }
	   
	   
	   for(row = 0; row < N; row++)
	   max+=D[row][M];
	   
	   
	   for(row = 0; row < M; row++)
	   max+=D[N][row];
	   
	   D[N][M]=max;                                   //krainiy
	   
	   
	    
		
		
		for(row = 0; row < N+1; row++)
    {
        for(col = 0; col < M+1; col++)
        {
         
            printf("\t%d",D[row][col]);
        }
        printf("\n\n");
    }
    system ("PAUSE"); 
}
    
    
    
    
