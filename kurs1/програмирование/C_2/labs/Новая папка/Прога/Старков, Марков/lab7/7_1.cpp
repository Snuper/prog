#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
main() 
{float a,b,c,x,y,F[58];
 int k,i,j;
system("CLS"); // ������� ������ 
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
for ( i = 0; i < 58-1; i ++ ) // ���������� ��������� N-1 ���������
    for ( j = 58-2; j >= i; j -- ) // ���� � ����� ������� � ������ 
      if ( F[j] < F[j+1] ) // ���� ��� ����� �����������, ...
      {
        c = F[j]; 
        F[j] = F[j+1]; // ����������� A[j] � A[j+1]
        F[j+1] = c;
      }
  printf("\n  sortirovaniy massiv:\n");
  for ( i = 0; i < 58; i ++ )
     printf("%f  \n", F[i]);



system("PAUSE"); 
return 0; 
} 
