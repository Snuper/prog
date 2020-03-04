#include <stdio.h> 
#include <stdlib.h>
const int N = 5;
int random (int N){ return rand()%N; } 
main(){
int a=-10, b=10, i,j;
float A[N][N], Sum=0;
for ( i = 0; i < N; i ++ ) 
 for ( j = 0; j < N; j ++ ) 
 A[i][j] = (float)rand()*(b-a)/RAND_MAX + a; 



for ( i = 0; i < N; i ++ ) {

printf("\n");
 for ( j = 0; j < N; j ++ ) 
 {printf("%f\t",A[i][j]); printf("||");}
}
printf("\n");
for ( i = 0; i < N; i ++ ){

   for ( j = 0; j < N; j ++ ){
   	Sum+=A[i][j];
   }
   printf("\n");
   for ( j = 0; j < N; j ++ ){
   	printf("%f\t",A[i][j]/Sum);printf("||");
   	}
   	Sum=0;
   }
system("PAUSE"); 
return 0; 
} 

