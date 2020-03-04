#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int random (int N) { return rand()%N; }
main(){
int m,k,j,i,c=0,str;
int  **B; int *A;                                
printf("Vvedite m= "); 
scanf("%d",&m);
A=new  int[m]; 
if (A==NULL){
puts("Cannot allocate memory");
return 1;
}
srand(time(NULL));
for (i=0; i<m; i++){
 A[i]=rand()%20;
 printf("%2d ",A[i]);
}
printf("\n Vvedite k= "); scanf("%d",&k);
B=new  int *[k];
if (B==NULL){  
puts("Cannot allocate memory");
return 1;
} 
if(m%k==0)	str=m/k;
else str=m/k+1;
for (i=0; i<k; i++){
B[i]=new  int [str];
if (B[i]==NULL){
puts("Cannot allocate memory ");
return 1;
}}
for (i=0; i<k; i++){ 
for (j=0; j<str; j++){
if(c>=m)	B[i][j]=0;
else	B[i][j]=A[c];
printf("%4d ",B[i][j]);
c++;}		
puts("\n");
}
for (i=0;i<k;i++){
delete  B[i];
B[i]=NULL;
}
delete  B; 
B=NULL;
delete  A; 
A=NULL;
getch();
return 0;
}
