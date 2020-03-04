#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double power(double,int); 
 main()
{ double x,y,z;
  printf(" input x,y ");
  scanf("%f, %f",&x,&y);
  z=power(x,y);
  printf("x=%f y=%f pow=%f",x,y,z);
  int();
}
double power(double a ,int b)
{ double c=1;
  if(b=0)
  c=1;
  if(b>0)
  {
  while (b>0)
  {
  c=a*a;
  b--;
}
if(b<0)
{
while (b<0)
{
c=c*a;
  b++;
}
c=1/c;
}
  return c;
}
}




