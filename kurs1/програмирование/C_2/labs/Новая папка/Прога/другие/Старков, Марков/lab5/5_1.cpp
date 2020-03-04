#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
main() 
{float P,Pi,x,J;
int z; 
system("CLS"); // очистка экрана 
 x=(-1);
 z=1;
 P=0;
 J=0;


do{
x+=2; 
z+=1;
J=(1/x);
P=P+(pow(-1,z)*J);

}
while(J>0.000001) ;
Pi=4*P;
 

 
printf ("Pi=%6.5f ", Pi); 
system("PAUSE"); 
return 0; 
} 
