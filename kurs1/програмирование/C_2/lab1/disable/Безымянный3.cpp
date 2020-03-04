#include <stdio.h>
#include <stdlib.h>
float pow(float,float); 
 main()
{ float x,y,z;
  printf(" input x,y ");
  scanf("%f%f",&x,&y);
  z=pow(x,y);
  printf("x=%f y=%f pow=%f",x,y,z);

}
float pow(float a ,float b)
{ float c=1;
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




