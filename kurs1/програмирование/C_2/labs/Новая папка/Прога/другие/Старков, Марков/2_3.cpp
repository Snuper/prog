#include <stdlib.h> 
#include <conio.h>
#include <stdio.h>
int p[33],i=0;
int per ( int n )
{int ch,ost,chp, rez;
if(n==0) {rez=i; return rez;}
ch=n;
ch/=2;
chp=ch*2;
ost=(chp-n)*(-1);
p[i]=ost;
i++;
per(ch);
}
int main() 
{ 
int x,y=0; 
scanf("%d",&x); 
printf("%d ",y);
*y=per(x);
y--;
printf("%d ",y);
for(i=y;0<=i;i--)
printf("%d",p[i]); 
}
