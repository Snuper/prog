#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int const N=20;
int random (int N) { return rand()%N; }
main()
{
int i,j,k,a=0,b=20,C[N],D[N],E[2*N],t;
srand(time(NULL));
printf("Massiv C\n");
for ( i = 0;i<N;i++)
{C[i]=random ( b - a + 1 ) + a;
printf("%d ",C[i]);}
printf("\n\nMassiv D\n");
for ( i = 0;i<N;i++)
{D[i]=random ( b - a + 1 ) + a;
printf("%d ",D[i]);}
 for ( i = 0; i < N-1; i ++ )
 for ( j = N-2; j >= i; j--)
 {
  if (C[j]>C[j+1])
  {t = C[j];
  C[j] = C[j+1];
  C[j+1] = t;}
    if (D[j]>D[j+1]) 
	{t = D[j];
    D[j] = D[j+1];
    D[j+1] = t;}
}
printf("\n\nOtsortirovan C:\n");
for ( i = 0; i < N; i ++ )
printf("%d ", C[i]);
printf("\n\nOtsortirovan D:\n");
for ( i = 0; i < N; i ++ )
printf("%d ", D[i]);
for ( i=0,j=0,k=0;k<N*2;k++)
{
if(i<N && C[i] < D[j])
{E[k] = C[i];
i++;}
else
{E[k] = D[j];
j++;}
}
printf("\n Massiv E:\n");
for( k = 0; k<2*N;k++ )
printf("E[%d]=%d\n",k,E[k]);
system("PAUSE");
return 0;
}
