#include <stdlib.h> 
#include <stdio.h> 
const int N = 20; 
int random (int N) { return rand()%N; } 
main() 
{ system("CLS"); 
int q, i, A[N], a = 0, b = 10;//a и b область значений 
printf("Elementi massiva\n"); 
for ( i = 0; i < N; i ++) 
{ 
printf("A[%d]",i); 
A[i] = random(b-a+1) + a; 
printf("=%d;\n",A[i]); 
}
void RunNumber()
{
for(q=0,i=0; i<N-1; i++) 
{ 
if(A[i] < A[i+1]) 
; 
else 
q++; 
}
}
printf("q=%d",q); 
system("PAUSE"); 
return 0; 
}
