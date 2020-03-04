#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;
int main()
{ int m;
printf("m="); scanf("%d",&m);
int P=1;
int i;
for (i=1; i <=m; i++)
{
P*=i;
}
printf("m=%3.0d P=%5.0d ",m,P);
system("PAUSE");
return 0;
}

