#include <stdio.h>
#include <conio.h>
int max(int,int); //Прототип функции (можно указывать только тип  
                        //формальных параметров)
 main()
{ int x,y,z;
  printf(" input x,y ");
  scanf("%d%d",&x,&y);
  z=max(x,y);  //Вызов функции с фактическими параметрами
  printf("x=%d y=%d max=%d",x,y,z);
  getch();
}
int max(int a ,int b) //Заголовок функции с формальными параметрами
{ int c;
  if (a>b) c=a;
  else c=b;
  return c;
}

