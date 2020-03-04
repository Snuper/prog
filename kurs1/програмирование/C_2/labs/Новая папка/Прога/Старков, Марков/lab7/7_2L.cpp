#include <stdio.h> 
#include <stdlib.h> 
const int N = 10; 
main() 
{ 
int i, j, A[N], c ;
// генерируем массив A 
printf("\n original massive:\n"); 
for ( i = 0; i < N; i ++ ) 
{ A[i]=rand()%10; 
printf("%d ",A[i]); 
} 
for ( i = 0; i < N; i ++ ) {
 for (j=0; j<N; j++)
 {if ((A[i] == A[j])&&(i!=j))
 A[j]=-1;
 }
 j=0;
}
printf("\n sorting massive \n");
 for ( i = 0; i < N; i ++ ) 
 if (A[i]>-1)
 
 printf("%d ",A[i]);
 



system("PAUSE"); 
return 0; 
}
