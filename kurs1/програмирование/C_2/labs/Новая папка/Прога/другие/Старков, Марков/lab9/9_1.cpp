#include <stdio.h> 
#include <stdlib.h>
const int M = 10; // число строк 
const int N = 20; // число столбцов 
int random (int N) { return rand()%N; }
main() 
{ 
int i,z, j, A[M][N], a=-5,b=10; 
for ( i = 0; i < M; i ++ ) 
for ( j = 0; j < N; j ++ ) 
A[i][j] = random(b-a+1) + a;

printf("original matrix A\n"); 
for ( i = 0; i < M; i ++ ) // цикл по строкам 
{
printf("\n"); // переход на другую строку 

for ( j = 0; j < N; j ++ ) // вывод одной строки (в цикле) 
printf ( "%4d", A[i][j] ); // 4 символа на число 
}
for ( i = 0; i < M; i +=2 ){
	for ( j = 0; j < N; j ++ ) {
	
	z=A[i+1][j];
	A[i+1][j]=A[i][j];
	A[i][j]=z;
}
j=0;
}
printf("\n matrix A\n"); 
for ( i = 0; i < M; i ++ ) // цикл по строкам 
{
printf("\n"); // переход на другую строку 

for ( j = 0; j < N; j ++ ) // вывод одной строки (в цикле) 
printf ( "%4d", A[i][j] ); // 4 символа на число 



} 
system("PAUSE"); 
return 0; 
}
