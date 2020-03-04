#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
main() 
{float a,b,c,x,y,min,max;
 int k;
system("CLS"); // очистка экрана 
a=2.14;
b=-4.21;
c=3.25;
x=-4.5; 
y=(a*(x*x)+b*x+c)*sin(x);
k=0;
min=y;
max=y;
 while (k<18)
 {k+=1;
 x-=0.5;
 y=(a*(x*x)+b*x+c)*sin(x);
 if (min>y) {min=y;}
 if (max<y) {max=y;}
}

printf ("min=%3.3f max=%3.3f\n", min,max); 
system("PAUSE"); 
return 0; 
} 
