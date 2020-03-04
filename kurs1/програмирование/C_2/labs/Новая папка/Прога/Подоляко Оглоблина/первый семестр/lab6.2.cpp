#include <stdlib.h>
#include <stdio.h>
main()
{
system("CLS");
int N;
printf("N=");
scanf("%d",&N);
int i=1,k,m,c;
float f=1,f1=1,f2=1;
float C[N];
 for(k=N;k>0;k--)
 f*=k;
  for(i=1;i<=N;i++)
   {f2*=i;
  m=N-i;
  for(c=1;c<=m;c++)
  f1*=c;
  C[i]=f/(f2*f1);
  f1=1;
  printf("C[i]=%6.3f\n",C[i]);}
system("PAUSE");
return 0; 
}
