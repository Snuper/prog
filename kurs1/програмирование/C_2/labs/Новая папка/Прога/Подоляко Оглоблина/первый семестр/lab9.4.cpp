#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=3;

main(void)
{
int i,k,j,A[N][N],temp,m1,m2,m3,m4,m5,m6,f;
srand(time(NULL));
system("CLS");
temp=0;f=0;
while (f==0) {
for(i=0;i<N;i++)
for(j=0;j<N;j++)
A[i][j]=rand()%10;
m1=A[0][0]+A[0][1]+A[0][2];
m2=A[1][0]+A[1][1]+A[1][2];
m3=A[2][0]+A[2][1]+A[2][2];
m4=A[0][0]+A[1][0]+A[2][0];
m5=A[0][1]+A[1][1]+A[2][1];
m6=A[0][2]+A[1][2]+A[2][2];
temp++;

if ((m1==m2)&&(m1==m3)&&(m1==m4)&&(m1==m5)&&(m1==m6)) {
printf("\n magicheskaya matritsa A \n");
for (i=0;i<N;i++)
{ printf("\n");
for (j=0;j<N;j++)
printf("%4d",A[i][j]);
f=f+1;
}}}

printf("\nm1=%d,m2=%d,m3=%d,m4=%d,m5=%d,m6=%d",m1,m2,m3,m4,m5,m6);
printf("\nk=%d",temp);
puts("\n");
system("PAUSE");
}
