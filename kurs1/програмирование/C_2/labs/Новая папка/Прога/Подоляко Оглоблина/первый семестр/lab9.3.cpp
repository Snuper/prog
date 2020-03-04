#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
const int N=5;
int random(int r)
{ return rand()%r;
}
main()
{
int i,j,A[N][N],T[N][N],temp;
system("CLS");
srand(11); 
for(i=0;i<N;i++)
for(j=0;j<N;j++)
A[i][j]=random(20);
printf("\n matritsa A \n");
for (i=0;i<N;i++)
{ printf("\n");
for (j=0;j<N;j++)
printf("%4d",A[i][j]);
}
for(i=0;i<N;i++)
{
for(j=0;j<N;j++)
{ T[i][j]=A[j][i];
}
}
printf("\n transponirovannaya matritsa A \n");
for (i=0;i<N;i++)
{ printf("\n");
for (j=0;j<N;j++)
printf("%4d",T[i][j]);
}

puts("\n");
system("PAUSE");
} 

