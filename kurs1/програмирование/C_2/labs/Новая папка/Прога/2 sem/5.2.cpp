#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main(){
int j,i,m;
int **A;   
printf("m=");
scanf("%d",&m);                
A=new int *[m];
if (A==NULL){
puts("Cannot allocate memory");
return 1;
}  
for(i=0;i<m;i++){
A[i]=new int [i+1]; 
if (A[i]==NULL){
puts("Cannot allocate memory ");
return 1;
}	
}
printf("\n tablitsa: \n\n");
for (i=0; i<m; i++){
for(j=0;j<i+1;j++){	
A[i][j]=(i+1)*(j+1);
printf("%4d ",A[i][j]);
}
puts("\n");
}
for (i=0;i<m;i++){
delete  A[i];
A[i]=NULL;}
delete  A; 
A=NULL;
getch();
return 0;
}
