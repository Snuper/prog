#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;
int main()
{ int n;
printf("n="); scanf("%d",&n);
float S =0;
float p=-1;
int i;
for (i=1; i <=n; i++)
{
p=p*(-1);
S+=p*i;
}
printf("n=%5.0d S=%5.0f ",n,S);
system("PAUSE");
return 0;
}
