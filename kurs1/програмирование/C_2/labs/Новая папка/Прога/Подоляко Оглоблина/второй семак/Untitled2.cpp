#include <stdio.h>
#include <conio.h>
#include <math.h>

float max(float); //�������� ������� (����� ��������� ������ ���  
                          //���������� ����������)
 main()
{ float x,y,cosinus;
  printf(" input x ");
  scanf("%f",&x);
  cosinus=max(x);  //����� ������� � ������������ �����������
  printf("x=%f cosinus=%f cos(x)=%f",x,cosinus,cos(x));
  getch();
}
float max(float a) //��������� ������� � ����������� �����������
{ float c,s,s1=1; int p=1,n;
  for (n=2;n<100;n=+4)
  {
      p=p*n;
      s=s-(pow(a,n))/p;
      }
  for (n=4;n<100;n=+4)
  {
      p=p*n;
      s1=s1+(pow(a,n))/p;
      }
      c=s+s1;
  return c;
}
