#include <stdio.h> 
#include <stdlib.h>
const int N = 5;
int random (int N){ return rand()%N; } 
main(){
int a=-10, b=10, i,j;
int A[N][N], B[N][N];
for ( i = 0; i < N; i ++ ) 
 for ( j = 0; j < N; j ++ ) 
 A[i][j] = random(b-a+1)+a; 
 
 for ( i = 0; i < N; i ++ ){
 printf("\n"); 
 for ( j = 0; j < N; j ++ ){
 printf("%d\t",A[i][j]); printf("||");}
}
for ( i = 0; i < N; i ++ ) {

printf("\n");
 for ( j = 0; j < N; j ++ ) {
 printf("%d",A[j][i]);printf("||");}
}
 system("PAUSE"); 
return 0; 
}
