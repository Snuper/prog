#include <stdio.h>
#include <conio.h>
int maxim(int); //�������� ������� (����� ��������� ������ ���  
                          //���������� ����������)
 main()
{ float x,z,p;
  int n;
  printf(" input x");
  scanf("%f",&x);
  maxim(x);  //����� ������� � ������������ �����������
  getch();
}
int maxim(int a) //��������� ������� � ����������� �����������
{ 
    printf("%d ",a);
    if(a<0){
             maxim(a-1);
             }
    else return 0;
}
