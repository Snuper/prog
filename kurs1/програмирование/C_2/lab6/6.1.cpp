#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

int Func(int x, int y, int z, int *f, int *g){
	int ff;
	if ((x+y>z)&&(x+z>y)&&(z+y>x)){
		*f=(x+y+z);
		ff=*f/2;
		*g=sqrt(ff*(ff-x)*(ff-y)*(ff-z));
		return 1;	
	}else{
	return 0;
}
}
main()
{ int p,s,h=0;
  int a,b,c; 
  printf("\n Input: ");
  scanf("%d%d%d",&a,&b,&c);
  h=Func(a,b,c,&p,&s);
  if (h==1){
  	printf("\nP=%d\nS=%d",p,s);
  }else{
  	printf("Triangle does not exist");
  }
  getch();
  return 0;
}
