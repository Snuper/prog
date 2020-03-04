#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
const int m=10, n=20;
int random(int r)
{ return rand()%r;
}
main()
{
int i,k,j,A[m][n],temp;
system("CLS");
srand(11); 
for(i=0;i<m;i++)
for(j=0;j<n;j++)
A[i][j]=random(20);
printf("\n matritsa A \n");
for (i=0;i<m;i++)
{ printf("\n");
for (j=0;j<n;j++)
printf("%4d",A[i][j]);
}
printf(" \n preobrazovannaya matritsa\n");
for(i=0;i<m;i+=2)
for(j=0;j<n;j++)
{
temp=A[i][j];
A[i][j]=A[i+1][j];
A[i+1][j]=temp;
}

for (i=0;i<m;i++)
{ printf("\n");
for (j=0;j<n;j++)
printf("%4d",A[i][j]);
}
puts("\n");
system("PAUSE");}
