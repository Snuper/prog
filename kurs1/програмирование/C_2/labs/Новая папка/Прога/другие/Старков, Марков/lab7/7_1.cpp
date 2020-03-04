#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
main() 
{float a,b,c,x,y,F[58];
 int k,i,j;
system("CLS"); // очистка экрана 
a=2.14;
b=-4.21;
c=3.25;
x=-4.5; 
k=0;

 while (k<58)
 {k+=1;
 x-=0.5;
 y= a*(x*x)*sin(x)+b*x+c;
 F[k-1]=y;
 printf("%f \n",F[k-1]);
}
for ( i = 0; i < 58-1; i ++ ) // достаточно поставить N-1 элементов
    for ( j = 58-2; j >= i; j -- ) // идем с конца массива в начало 
      if ( F[j] < F[j+1] ) // если они стоят неправильно, ...
      {
        c = F[j]; 
        F[j] = F[j+1]; // переставить A[j] и A[j+1]
        F[j+1] = c;
      }
  printf("\n  sortirovaniy massiv:\n");
  for ( i = 0; i < 58; i ++ )
     printf("%f  \n", F[i]);



system("PAUSE"); 
return 0; 
} 
