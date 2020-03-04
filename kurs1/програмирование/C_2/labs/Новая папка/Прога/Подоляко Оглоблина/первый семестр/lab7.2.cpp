#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
const int N=30;
int random(int N) {return rand()%N;}
main()
{ system("CLS");
int A[N], i, a=0, b=10, k=0;
srand(time(NULL));
int c=-1;
for (i=0; i<N;i++)
{
A[i]=random(b-a+1)+a;
printf("%d \n",A[i]);}

for (k=0;k<=10;k++) {
for(i=0;i<N;i++)
{if (A[i]==k && c<0) c++;
else if (A[i]==k)
 {A[i]=-1; c=0;}} c=-1;}
for(i=0;i<N; i++)
{if (A[i]>=0) printf(" A[i]=%d \n",A[i]);}
system("PAUSE");
return 0;
}

