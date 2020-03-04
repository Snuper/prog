#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{int a,b,i,n,c;	
printf ("Vvedi n =");			
   scanf("%i",&n);
   a=2;
   b=0;
   while(a<n) 
   { for(i=2;i<a;i++) {
   if(a%i==0) c=1;
   }
   if(c!=1){
   printf ("s=%d\n", a); 
   b+=1;}
   a+=1;
   c=0;}	   							
   printf ("kolvo chisel = %d\n", b);   
   system("PAUSE"); 
   return 0;  
}

