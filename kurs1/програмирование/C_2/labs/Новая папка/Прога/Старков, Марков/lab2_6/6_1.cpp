#include <stdio.h>
#include <conio.h>
#include <math.h>
int swap(float * a, float * b,float * c, float*p,float*s)
{int pp;
 if((*a+*b)<*c) return 0;
 if((*a+*c)<*b) return 0;
 if((*b+*c)<*a) return 0;
 
 *p=(*a+*b+*c);
 pp=(*p/2);
 *s=sqrt(pp*(pp-*a)*(pp-*b)*(pp-*c));
 return 1;
}
main()
{ float x,y,z,P,S;
  printf("\n  print a,b,c");
  scanf("%f%f%f",&x,&y,&z);
  swap(&x,&y,&z,&P,&S); // Передаём адреса переменных
  printf("\n  P=%4.2f S=%4.2f ",P,S);
  getch();
}


