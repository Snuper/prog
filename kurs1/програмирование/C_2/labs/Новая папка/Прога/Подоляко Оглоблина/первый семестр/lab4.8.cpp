#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
int main()
{
int P=1;
int i;
for (i=2; i<=12; i=i+2)
{
P*=i;
}
printf(" P=%7.0d ",P);
system("PAUSE");
return 0;
}
