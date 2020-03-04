#include <iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;
int main()
{ int x=1;
float S=0;
float p=0.18*x;
int i;
for (i=1; i <=10; i++)
{
S+=pow(p,i);
p+=0.02*x;
}
printf("S=%5.3f \n ",S);
system("PAUSE");
return 0;
}
