#include <stdio.h>
#include <conio.h>
#include <math.h>
float maxim(float);  
                          
 main()
{ float x,z,z1;
  int n;
  printf(" input x ");
  scanf("%f",&x);
  while(x<-3.14 or x>3.14){
  	if(x<-3.14) x+=3.14;
  	if(x>3.14) x-=3.14;
  }
  z=maxim(x); 
  z1=cos(x); 
  printf("x=%f cos=%f",z,z1);
  getch();
}
float maxim(float a) 
{ float x=1,e=0;
  int i,j,o=1;
  long long int h=1;
  
  for(i=0;i<20;i+=2){	  // ����� �����, � �� ����� �������� (���� ���, ��� ������������ ����� ��������� ������ ������, �� ����� ���� � ��� ����� ������ ���)
  	
  	for(j=1;j<i+1;j++){   // ������ ���
  		h=h*j;			  // ��� ��� ���� ������ !, �� ����� ��� ����������
	  }
	for(j=1;j<i+1;j++){   // ���� ��������� �
  		x=x*a;
	  }
	
	e=e+(o*x/h);     	  // ��� ��������� ���������� ����� ������
	
	  o=o*(-1);			  // ��� �� ������� �������, ����� �� �������
	  h=1;
	  x=1;
  }
  return e;
}
