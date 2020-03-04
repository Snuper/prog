#include <stdio.h> 
#include <stdlib.h>
const int N = 3;
int random (int N){ return rand()%N; } 
main(){
int a=0, b=9, i,kk=0,k=0,j,Sum=0,Sum2=0,Sum3=0,s=0;
int A[N][N];
do{
s++;
for ( i = 0; i < N; i ++ ) {
;
 for ( j = 0; j < N; j ++ ) {
 
 A[i][j] = random(b-a+1)+a; 
 
}
}

 for (i=0, j = 0; j < N; j ++ ) {
 
 Sum+=A[i][j];

 
}
 
 for ( i = 0; i < N; i ++ ){
 
  for ( j = 0; j < N; j ++ ){
  Sum2+=A[i][j];
  Sum3+=A[j][i];}
   
   
  
  
  if(Sum==Sum2){
Sum2=0;
  k++;
  }
  else
  Sum2=0;
  
   
   
   
  if(Sum==Sum3){
Sum3=0;
  k++;
  }
  else
  Sum3=0;
  }
   if(k==6) kk=1;
   Sum2=0;
   Sum3=0;
   Sum=0;
   k=0;
   
  
 }while(kk!=1);
 
 printf("%d",s);
 
 
 
 system("PAUSE"); 
return 0; 
}
 
