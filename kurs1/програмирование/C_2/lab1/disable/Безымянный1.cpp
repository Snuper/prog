#include <stdio.h>
#include <conio.h>
int max(int,int); //�������� ������� (����� ��������� ������ ���  
                        //���������� ����������)
 main()
{ int x,y,z;
  printf(" input x,y ");
  scanf("%d%d",&x,&y);
  z=max(x,y);  //����� ������� � ������������ �����������
  printf("x=%d y=%d max=%d",x,y,z);
  getch();
}
int max(int a ,int b) //��������� ������� � ����������� �����������
{ int c;
  if (a>b) c=a;
  else c=b;
  return c;
}

