#include <stdlib.h>
#include <stdio.h>

const int N = 15;
int random (int N) { return rand()%N; }

main()
{ system("CLS");
int i, A[N], a = -10, b = 10,c=0;
float X[N];
for ( i = 0; i < N; i ++ ){
X[i] = (float)rand()*(b - a)/RAND_MAX + a;
printf("%5.2f \n",X[i]);
if(X[i]>0)c++;}
float B[c];
c=0;
printf("Novie chisla\n");
for ( i = 0; i < N; i ++ )
{if(X[i]>0){
	B[c]=X[i];
	printf("%5.2f \n",B[c]);
	c++;
}
}
system("PAUSE");
return 0;
}
