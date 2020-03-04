#include <stdlib.h>
#include <stdio.h>
#include <math.h>
main()
{
//1 Вариант задания
int x,N,a,b,h,I1,I2,i; //I1-ФОРМУЛА ТРАПЕЦИИ I2-ФОРМУЛА СИМПСОНА
float A[i];
system("CLS");
printf("Vvedite N: ");	
scanf("%d",&N);  
x=0; a=-2; b=5;
for(x=a, i=0; x<=5; x++, i++)
{
	A[i]=(x*x)/(10+pow(x,3)); //Заполняем массив
	printf("A[%d]=%f\n",i,A[i]);
}
system("PAUSE");
return 0;
}
