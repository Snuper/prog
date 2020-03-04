#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float x,k,m,n;
    printf("Input ");   scanf("%f%f%f",&k,&m,&n);
   x=k;
   if (k>m && n>m) {
   k=m;
   m=x;}
   if (k>n && m>n) {
   k=n;
   n=x;}
   if (m>n){
   	x=m;
   	m=n;
   	n=x;
   }
   printf ("k=%8.2f m=%8.2f n=%8.2f \n", k,m,n); 
   system("PAUSE");
   return EXIT_SUCCESS;
}

