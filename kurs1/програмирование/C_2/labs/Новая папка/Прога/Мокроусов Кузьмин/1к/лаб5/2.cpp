#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{float a,b,c,h,x,z1,z2;

   system("CLS"); // очистка экрана					
   a  = 2.14;  
   b= - 4.21;  
   c = 3.25; 
   h=-4.5;
   z1=0;
   z2=0;
   while (h>-14) 
   {x=(a*h*h+b*h+c)*sin(h);
	if(z1>x) z1=x;
	if(z2<x) z2=x;
	h+=-0.5;
   }	   							
   printf ("z1=%7.3f z2=%7.3f\n",z1,z2);   
   system("PAUSE"); 
   return 0;  
}

