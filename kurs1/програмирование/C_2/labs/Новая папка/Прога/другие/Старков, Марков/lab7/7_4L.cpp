#include <stdlib.h> 
#include <stdio.h> 
const int N = 20; 
int random (int N) { return rand()%N; } 
main() 
{ system("CLS"); 
int i, C[N], D[N],E[N*2] ,k,c,j,a = 0, b = 20; 

 
for ( i = 0; i < N; i ++ ) {

C[i] = random(b-a+1) + a;
D[i] = random(b-a+1) + a; 
}
 printf("\nmassiv C\n"); 
for ( i = 0; i < N; i ++ ) 
printf("%4d",C[i]); 
printf("\nmassiv D\n"); 
for ( i = 0; i < N; i ++ ) 
printf("%4d",D[i]);

for ( i = 0; i < N-1; i ++ )  
for ( j = N-2; j >= i; j -- ) 
if ( C[j] > C[j+1] ) 
{ 
c = C[j]; 
C[j] = C[j+1]; 
C[j+1] = c; 
} 

printf("\nsorting massiv C\n"); 
for ( i = 0; i < N; i ++ ) 
printf("%4d",C[i]); 

for ( i = 0; i < N-1; i ++ )  
for ( j = N-2; j >= i; j -- ) 
if ( D[j] > D[j+1] ) 
{ 
c = D[j]; 
D[j] = D[j+1]; 
D[j+1] = c; 
} 

printf("\nsorting massiv D\n"); 
for ( i = 0; i < N; i ++ ) 
printf("%4d",D[i]);
//??????
k=0;
j=0;
for(i=0; i<40; i++){
         if((C[j]>=D[k])&&(k<20))
         {E[i]=D[k];
         k++;}
         else {
         E[i]=C[j];
         j++;}
         }
         


 printf("\nsorting massiv E\n"); 
for ( i = 0; i < N*2; i ++ ) 
printf("%4d",E[i]);

 
system("PAUSE"); 
return 0; 
} 
