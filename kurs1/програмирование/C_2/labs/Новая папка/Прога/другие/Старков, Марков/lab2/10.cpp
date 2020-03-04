#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{   float m,n,k,bolsh,mensh,sred,posrednik;
    printf("Vvedi 3 chisel k,m,n\n");   scanf("%f%f%f",&k,&m,&n);
  if(k<m&&k<n)
   mensh=k;
  if(m<n&&m<k)
   mensh=m; 
  if(n<k&&n<m)
   mensh=n;
   
   if(m>n&&m>k)
   bolsh=m;
  if(k>m&&k>n)
   bolsh=k; 
  if(n>m&&n>k)
   bolsh=n;
   
   if(k<bolsh&&k>mensh)
    sred=k;
     if(m<bolsh&&m>mensh)
    sred=m;
     if(n<bolsh&&n>mensh)
    sred=n;
    
      
   printf ("k=%8.2f < m=%8.2f < n=%8.2f",k,m,n); 
     //7) Даны 3 числа  K, M  и N. Поменять их значения местами таким образом, чтобы K < M < N.
     
   
   system("PAUSE");
   return EXIT_SUCCESS;
}
