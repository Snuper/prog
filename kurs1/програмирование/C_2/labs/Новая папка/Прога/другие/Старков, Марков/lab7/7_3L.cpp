#include <stdlib.h> 
#include <stdio.h> 
const int N = 20; 
int random (int N) { return rand()%N; } 
main() 
{ system("CLS"); 
int j=-1,i,x=0, a = -10, b = 10; 
float A[N]; 
for ( i = 0; i < N; i ++ ) 
A[i] = (float)rand()*(b-a)/RAND_MAX + a; 
printf("\n massive \n"); 
for ( i = 0; i < N; i ++ ) 
printf("%6.2f",A[i]); 

for ( i = 0; i < N; i ++ )
if (A[i]>0) 
x+=1;
float B[x];
for ( i = 0; i < N; i ++ )
if (A[i]>0) {
j++;
B[j]=A[i];
}
printf("\n sorting massive\n");
for ( i = 0; i <= j; i ++ )
printf("%6.2f",B[i]);

system("PAUSE"); 
return 0; 
}
