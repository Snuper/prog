#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
const int N=10;
int random(int N) {return rand()%N;}

main()
{ system("CLS");
int A[N], i,j,f, a=0, b=5, k=0;
f=0;
srand(time(NULL));
int c=-1;
for (i=0; i<N;i++)
{
A[i]=random(b-a+1)+a;
printf("%d \n",A[i]);}
for(i=0;i<N;i++)
for(j=0;j<N;j++){
if (A[i]==A[j])f=1;
 if (f==0) printf(" A[i]=%d \n",A[i]);}
system("PAUSE");
return 0;
}
