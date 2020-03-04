#include <stdlib.h> 
#include <stdio.h> 
const int N = 16; 
int random (int N) { return rand()%N; } 
main() 
{ system("CLS"); 
int i, A[N],k,z;
k=0;
z=0;
printf("/n print numbers /n");
for (i=0;i<N;i++)
scanf("%d",&A[i]);
for (i=0;i<N;i++){
if ((i+1)%2==0)
k+=A[i];}


for (i=0;i<N;i++){
	if((i+1)%2!=0)
	z=(A[i]*2);
	if(z>9)
	z-=9;
	k+=z;
	z=0;
}
if(k%10==0)
printf("k=%d, card valide ",k);
if(k%10!=0)
printf("k=%d, card invalide ",k);


system("PAUSE"); 
return 0; 
} 
