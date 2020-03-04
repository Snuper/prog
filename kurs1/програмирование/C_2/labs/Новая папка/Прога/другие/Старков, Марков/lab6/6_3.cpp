#include <stdlib.h> 
#include <stdio.h> 
const int N = 20; 
int random (int N) { return rand()%N; } 
main() 
{ system("CLS"); 
 int i; 
float A[N] , a = -10, b = 10;
for ( i = 0; i < N; i ++ ) 
A[i] =  rand()*(b - a)/RAND_MAX + a;
printf("\n numbers\n"); 

for ( i = 1; i < N; i ++ ) 
printf("%6.2f",A[i]);

printf("\n numbers 2\n");
for ( i = 1; i < N; i ++ ) 
if ((A[i-1]<A[i])and(A[i]>A[i+1]))
printf("%6.2f",A[i]);  
 


system("PAUSE"); 
return 0; 
} 
