#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
int main()
{ int N;
float x;
float S=1,p=1,i,k;
printf("N="); scanf("%d",&N); printf("x="); scanf("%f",&x);
for (i=1; i<=N; i++)
{ k=pow(x,i);
p*=i;
S+=k/p;
}
printf("S=%7.2f \n",S); 
system("PAUSE");
return 0;
}
