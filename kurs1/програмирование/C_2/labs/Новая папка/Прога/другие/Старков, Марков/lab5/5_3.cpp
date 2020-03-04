#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
main() 
{
int x,m,k,i,z; 
system("CLS"); // очистка экрана 
x=0;
printf ("vvedite n"); scanf("%d",&x);
 k=0;
 m=1;
 z=0;
 
for (i=0;i<x;i++)
{
z+=1;
   while (m<z) 
  {  m+=1;
  if (z==m)continue;
  if((z%m)==0) {k+=1;}
  }
  m=1;
  if(k==0) {printf (",%d",z);}
  k=0;
}

  
  
   

system("PAUSE"); 
return 0; 
} 
