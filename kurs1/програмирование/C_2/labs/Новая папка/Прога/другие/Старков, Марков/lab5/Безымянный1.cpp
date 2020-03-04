#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
main() 
{float P,Pi,x;
int z; 
system("CLS"); // очистка экрана 
 x=(-1);
 z=1;

while (z<100000) 
{ 
x+=2;
z+=1;
P=P+(pow(-1,z)*(1/x));
Pi=4*P;
} 
printf ("Pi=%f", Pi); 
system("PAUSE"); 
return 0; 
} 
