#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
float q,r,e,pi,n,a,c,b;
   printf("\n Vvedite tochnost vichisleniya: ");
   scanf("%f",&e);    
  // e=0.00001;
   b=0; //Для знакочередования
   r=0;
   n=1;
   a=3; //На что делим
   c=1; //Для знакочередования
   r=1;
   while(r>e)
   {
	b=pow(-1,c);
	c++;
	n+=b*(1/a);
   	r=1/a;
   	a=a+2;
   //	printf("\n r=%.5f",r);
   }
   //printf("n=%.7f",n);
   pi=4*n;
   printf("\n pi=%f",pi);
 //  printf("\n a=%.5f",a); 
 //  printf("\n r=%.5f",r);
 //  printf("\n q=%.5f",q); 
  // printf("\n e=%.5f",e);
 //  printf("\n n=%.5f",n); 
 //  printf("\n c=%.5f",c);
//   printf("\n b=%.5f",b);
   system("PAUSE"); 
   return 0;  
}

