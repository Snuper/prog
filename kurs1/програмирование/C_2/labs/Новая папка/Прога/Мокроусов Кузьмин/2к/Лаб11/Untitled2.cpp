#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct tov {char name[10]; int c; int kol;} t1;
void input(FILE *); // �������� ������ �����
void print(FILE *); // �������� �����
void app(FILE *); // ���������� � ����
void del(FILE *); // ����� � ��������� 
main()
{ char c;
  FILE *tf;
  while (1)
  { system("CLS");
    puts("  1 - New file");
    puts("  2 - Print file");
    puts("  3 - Add to file");
    puts("  4 - Delete from file");
    puts("  0 - Exit");
    c=getch();
    switch(c)
    { case '1':input(tf);break;
      case '2':print(tf);break;
      case '3':app(tf);break;
      case '4':del(tf);break;
      case '0':return 0;
      default : puts(" �������� �����");
     }
  }
}
void input(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","wb"); // �������� ��������� ����� ��� ������
  system("CLS");
  printf("\n Passenger input\n");
  do
  { printf("\n FIO: "); scanf("%s",&t1.name);
    printf(" Space occupied: "); scanf("%d",&t1.c);
    printf(" Weight: "); scanf("%d",&t1.kol);
    fwrite(&t1,sizeof(t1),1,tf); // ������ � ���� ����� ��������� t1
    printf("\n Exit?  y/n  ");
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
  { printf("\n  %3d passenger - %10s space occupied - %4d weight - %4d",i,t1.name,t1.c,t1.kol);
    fread(&t1,sizeof(t1),1,tf);
    i++;
  }
  getch();
}
void app(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","ab"); // �������� ��������� ����� ��� ����������
  system("CLS");
  printf("\n Passenger input\n");
  do
  { printf("\n FIO: "); scanf("%s",&t1.name);
    printf(" Space occupied: "); scanf("%d",&t1.c);
    printf(" Weight: "); scanf("%d",&t1.kol);
    fwrite(&t1,sizeof(t1),1,tf); // ������ � ���� ����� ��������� t1
    printf("\n Exit?  y/n  ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void del(FILE *tf)
{ char c,tov[10];
  FILE *pf;                      // ��������� �� �����
  pf=fopen("new1.dat","wb");  
  tf=fopen("file1.dat","rb"); // �������� ��������� ����� ��� ������ � ������
  system("CLS");
  puts(" Passenger list: ");
  fread(&t1,sizeof(t1),1,tf);
  while (!feof(tf))
  {  if (t1.kol<10)
     {
        printf(" Passenger %10s deleted\n",t1.name);
      }  
      else{
      	fwrite(&t1,sizeof(t1),1,pf); 
	  }
      fread(&t1,sizeof(t1),1,tf);
  }
  getch();
  fclose(pf);
  fclose(tf);
  
  pf=fopen("new1.dat","rb");  
  tf=fopen("file1.dat","wb"); // �������� ��������� ����� ��� ������ � ������
  system("CLS");
  puts(" Passenger list: ");
  fread(&t1,sizeof(t1),1,pf);
  while (!feof(pf))
  {  
    fwrite(&t1,sizeof(t1),1,tf); 
    fread(&t1,sizeof(t1),1,pf);
  }
  fclose(pf);
  fclose(tf);
  remove("new1.dat");
}

