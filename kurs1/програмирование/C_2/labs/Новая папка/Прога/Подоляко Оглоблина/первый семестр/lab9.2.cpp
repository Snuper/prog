#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
const int N=5;
int random (int N) { return rand() % N; }
main()
{
int i,j;
float A[N][N],a=0,b=10,s1=0,s2=0,s3=0,s4=0,s5=0;
system("CLS");
srand(11); 
for(i=0;i<N;i++)
for(j=0;j<N;j++)
A[i][j]= (float)rand()*(b-a)/RAND_MAX + a; 
printf("\n matritsa A \n");
for (i=0;i<N;i++)
{ printf("\n");
for (j=0;j<N;j++)
printf("%8.2f",A[i][j]);
}
for(j=0;j<N;j++)
{ s1+=A[0][j];
s2+=A[1][j];
s3+=A[2][j];
s4+=A[3][j];
s5+=A[4][j];
}
printf("\n\n s1=%4.2f s2=%4.2f s3=%4.2f s4=%4.2f s5=%4.2f",s1,s2,s3,s4,s5);
for(j=0;j<N;j++)
{ A[0][j]=A[0][j]/s1;
A[1][j]=A[1][j]/s2;
A[2][j]=A[2][j]/s3;
A[3][j]=A[3][j]/s4;
A[4][j]=A[4][j]/s5;
} 
printf("\n novaya matritsa A \n");
for (i=0;i<N;i++)
{ printf("\n");
for (j=0;j<N;j++)
printf("%8.2f",A[i][j]);
}
system("PAUSE");}

