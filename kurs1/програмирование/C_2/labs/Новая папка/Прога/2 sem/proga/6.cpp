#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{ float x,y,z;
  void pl(float *, float *, float *);
  printf("\n x,y,z ");
  scanf("%f%f%f",&x,&y,&z);
  pl(&x,&y,&z);
  printf("\n %7.2f   %7.2f ",x,y);
  getch();
}
void pl(float * a, float * b, float * c)
{float p;
  p=(*a+*b+*c)/2;
  p=sqrt(p*(p-*a)*(p-*b)*(p-*c));
  if((*a+*b)<=*c or (*b+*c)<=*a or (*a+*c)<=*b) *b=0;
  else *b=1;
  *a=p;
}

