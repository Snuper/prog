#include <stdio.h>
#include <conio.h>
int maxim(int); //Прототип функции (можно указывать только тип  
                          //формальных параметров)
 main()
{ float x,z,p;
  int n;
  printf(" input x");
  scanf("%f",&x);
  maxim(x);  //Вызов функции с фактическими параметрами
  getch();
}
int maxim(int a) //Заголовок функции с формальными параметрами
{ 
    printf("%d ",a);
    if(a<0){
             maxim(a-1);
             }
    else return 0;
}
