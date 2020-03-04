#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{float p;
int a,b,k;
   system("CLS"); // очистка экрана					
   p=0;
   a=1;	
   b=0;	
   k=0;
   while (k<100000) 
   { p+=pow(-1,b)*1/a;
   a+=2;
   b+=1;
   k++;
   }
   p=p*4;	   							
   printf ("s=%7.5f\n", p);   
   system("PAUSE"); 
   return 0;  
}

