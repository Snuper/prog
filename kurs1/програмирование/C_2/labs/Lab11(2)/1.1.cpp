#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;
struct tov {char name[15];char c[15];char kol[15];int mest;float ves;} t1;
void input(FILE *); // �������� ������ �����
void print(FILE *); // �������� �����
void app(FILE *); // ���������� � ����
void find(FILE *); // ����� � ���������  //��������
void Find(FILE *, FILE *);
void find_1(FILE *,FILE *,int c_2,int c_4);
main()
{ setlocale(LC_CTYPE,"Russian");
  char c;
  FILE *tf;
  FILE *new_tf;
  while (1)
  { system("CLS");
    puts("  1 - ����� ����");
    puts("  2 - �������� �����");
    puts("  3 - ���������� � ����");
    puts("  4 - ����� ");
    puts("  5 - �������� �� �����");
    puts("  0 - �����");

    c=getch();
    switch(c)
    { case '1':input(tf);break;
      case '2':print(tf);break;
      case '3':app(tf);break;
      case '4':find(tf);break;
      case '5':Find(tf,new_tf);break;
      case '0':return 0;
      default : puts("�������� �����");
     }
  }
}
void input(FILE *tf)
{ char ch;
int i=1;
  tf=fopen("file1.dat","wb"); // �������� ��������� ����� ��� ������
  system("CLS");
  printf("\n ���������� ���������\n");
  do
  { printf("\n �������: "); scanf("%s",&t1.name);
    printf(" ���: "); scanf("%s",&t1.c);
    printf(" ��������: "); scanf("%s",&t1.kol);
    printf(" ���-�� ����: "); scanf("%d",&t1.mest);
    printf(" ����� ��� ������(��): "); scanf("%f",&t1.ves);
    fwrite(&t1,sizeof(t1),1,tf); // ������ � ���� ����� ��������� t1
    i++;
    printf("\n ���������?  y/n  ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void print(FILE *tf)
{ int i;
  system("CLS");
  tf=fopen("file1.dat","rb"); // �������� ��������� ����� ��� ������
  i=1;
  fread(&t1,sizeof(t1),1,tf); // ������ �� ����� ����� ��������� t1
  while (!feof(tf))
  { printf("%d)%s %s %s\n���-�� ����: %d\n��� ������(��): %.2f\n",i,t1.name,t1.c,t1.kol,t1.mest,t1.ves);
    fread(&t1,sizeof(t1),1,tf);
    i++;
  }
  getch();
}
void app(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","ab"); // �������� ��������� ����� ��� ����������
  system("CLS");
  printf("\n  ���������� ��������� \n");
  do
  {  printf("\n �������: "); scanf("%s",&t1.name);
    printf(" ���: "); scanf("%s",&t1.c);
    printf(" ��������: "); scanf("%s",&t1.kol);
    printf(" ���-�� ����: "); scanf("%d",&t1.mest);
    printf(" ����� ��� ������(��): "); scanf("%f",&t1.ves);
    fwrite(&t1,sizeof(t1),1,tf);
    printf(" ���������?  y/n ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void find(FILE *tf)
{ char c,tov[20];
  system("CLS");
  tf=fopen("file1.dat","rb+"); // �������� ��������� ����� ��� ������ � ������
  int i=1;
  puts("��� ���������: ");
  gets(tov);
  fread(&t1,sizeof(t1),1,tf);
  while (!feof(tf))
  {  if (strcmp(t1.name,tov)==0 or strcmp(t1.c,tov)==0 or strcmp(t1.kol,tov)==0 )
     {
        printf("%d)%s %s %s\n���-�� ����: %d\n��� ������(��): %.2f\n",i,t1.name,t1.c,t1.kol,t1.mest,t1.ves);
        i++;
        getch();
      }
	    
      fread(&t1,sizeof(t1),1,tf);
  }
  fclose(tf);
}
void find_1(FILE *tf,FILE *new_tf,int c_2,int c_4){
     new_tf=fopen("new_file.dat","rb");
     tf=fopen("file1.dat","wb");
     int c_3=0;
     while(!feof(new_tf) && (c_3<c_2-(c_2-c_4))){
                           fread(&t1,sizeof(t1),1,new_tf);
                           fwrite(&t1,sizeof(t1),1,tf);
                           c_3++;
                           }
                           fclose(tf);
                           fclose(new_tf);
}
void Find(FILE *tf, FILE *new_tf){
     tf=fopen("file1.dat","rb");
     new_tf=fopen("new_file.dat","wb");
     int c_2=0,c_4=0,i;
     while((!feof(tf)) && (c_2<i)){
                         fread(&t1,sizeof(t1),1,tf);
                         if((t1.ves>=9)){
                                              c_4++;
                                              fwrite(&t1,sizeof(t1),1,new_tf);
                                              }
                                              c_2++;
                                              }
                                              cout<<endl<<"c_2= "<<c_2<<endl;
                                              fclose(new_tf);
                                              fclose(tf);
                                              find_1(tf,new_tf,c_2,c_4);
}                                                                         
  
