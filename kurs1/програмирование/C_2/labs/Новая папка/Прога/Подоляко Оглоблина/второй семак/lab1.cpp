#include <stdio.h>
#include <conio.h>
float max(int,float); //�������� ������� (����� ��������� ������ ���  
                          //���������� ����������)
 main()
{ int n;
float y,x;
  printf(" input x,n ");
  scanf("%f%d",&x,&n);
  y=max(n,x);  //����� ������� � ������������ �����������
  printf("x=%f n=%d y=%f",x,n,y);
  getch();
}
float max(int a,float b) //��������� ������� � ����������� �����������
{ float c=1; int i;
  if (a>=0)
  
  { for (i=1;i<=a;i++)
   c=c*b;
} 
   if (a<0)
   {
   for (i=-1;i>=a;i--)
   c=c*(1/b); }

  return c;
}
