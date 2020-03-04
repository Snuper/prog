#include <stdlib.h> 
#include <conio.h>
#include <stdio.h>
int p[33],i=0;
void per ( int n )
{int ch,ost,chp;
if(n==0) return; //(i);
ch=n;
ch/=2;
chp=ch*2;
ost=(chp-n)*(-1);
p[i]=ost;
//i++;
per(ch);
printf("%d", ost);
}
int main() 
{ 
int x; 
scanf("%d",&x); 
/*y=*/per(x);
system("PAUSE");
//y--;
//for(i=y;0<=i;i--)
//printf("%d",p[i]); 
}
