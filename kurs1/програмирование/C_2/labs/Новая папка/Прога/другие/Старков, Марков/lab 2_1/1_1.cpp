#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int n,i=1,flag=0;
float x,z;
float st(int n, float x)

{
      if (n<0) {n=n*(-1);flag=1;}
      z=x;
  while(i<n)
    {
    i++;
    z=z*x;
    
}
  if (flag==1) {z=1/z;}
    return z;
     
}
int main ()
{
    scanf("%f%d",&x,&n);
    z=st(n, x);
    printf("x=%f\n",z);
    system("PAUSE");
    }
    

