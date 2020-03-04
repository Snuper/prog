#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(){
int **A,i,j,m=9;
A = new int*[m];
 for(i=0;i<m;i++)
 A[i]=new int[i+1];
 for(i=0;i<m;i++){
 	for(j=0;j<i+1;j++){
 		A[i][j]=((i+1)*(j+1));
 		printf("%d ",A[i][j]);
	 } 
	 printf("\n");
 }
 
system ("PAUSE"); 
}
