#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 15;
main()
{
int i,j,a[N],c;
for(i=0;i<=N;i++)
{a[i]=rand()%10;
printf("%d \n",a[i]);}
printf("\n");
for (i=0; i<N-1 ;i++){
c=1;
for (j=0; j<i ;j++){if (a[i]==a[j]) c=0;}
if(c==1) printf("%d \n",a[i]);
}
system("PAUSE");
return 0;
}

