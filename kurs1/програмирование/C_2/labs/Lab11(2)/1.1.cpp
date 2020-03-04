#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;
struct tov {char name[15];char c[15];char kol[15];int mest;float ves;} t1;
void input(FILE *); // создание нового файла
void print(FILE *); // просмотр файла
void app(FILE *); // добавление в файл
void find(FILE *); // поиск и изменение  //удаление
void Find(FILE *, FILE *);
void find_1(FILE *,FILE *,int c_2,int c_4);
main()
{ setlocale(LC_CTYPE,"Russian");
  char c;
  FILE *tf;
  FILE *new_tf;
  while (1)
  { system("CLS");
    puts("  1 - Новый файл");
    puts("  2 - Просмотр файла");
    puts("  3 - Добавление в файл");
    puts("  4 - Поиск ");
    puts("  5 - Удаление из файла");
    puts("  0 - Выход");

    c=getch();
    switch(c)
    { case '1':input(tf);break;
      case '2':print(tf);break;
      case '3':app(tf);break;
      case '4':find(tf);break;
      case '5':Find(tf,new_tf);break;
      case '0':return 0;
      default : puts("неверный режим");
     }
  }
}
void input(FILE *tf)
{ char ch;
int i=1;
  tf=fopen("file1.dat","wb"); // открытие бинарного файла для записи
  system("CLS");
  printf("\n Добавление пассажира\n");
  do
  { printf("\n Фамилия: "); scanf("%s",&t1.name);
    printf(" Имя: "); scanf("%s",&t1.c);
    printf(" Отчество: "); scanf("%s",&t1.kol);
    printf(" Кол-во мест: "); scanf("%d",&t1.mest);
    printf(" Общий вес багажа(кг): "); scanf("%f",&t1.ves);
    fwrite(&t1,sizeof(t1),1,tf); // запись в файл одной структуры t1
    i++;
    printf("\n Закончить?  y/n  ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void print(FILE *tf)
{ int i;
  system("CLS");
  tf=fopen("file1.dat","rb"); // открытие бинарного файла для чтения
  i=1;
  fread(&t1,sizeof(t1),1,tf); // чтение из файла одной структуры t1
  while (!feof(tf))
  { printf("%d)%s %s %s\nКол-во мест: %d\nВес багажа(кг): %.2f\n",i,t1.name,t1.c,t1.kol,t1.mest,t1.ves);
    fread(&t1,sizeof(t1),1,tf);
    i++;
  }
  getch();
}
void app(FILE *tf)
{ char ch;
  tf=fopen("file1.dat","ab"); // открытие бинарного файла для добавления
  system("CLS");
  printf("\n  Добавление пассажира \n");
  do
  {  printf("\n Фамилия: "); scanf("%s",&t1.name);
    printf(" Имя: "); scanf("%s",&t1.c);
    printf(" Отчество: "); scanf("%s",&t1.kol);
    printf(" Кол-во мест: "); scanf("%d",&t1.mest);
    printf(" Общий вес багажа(кг): "); scanf("%f",&t1.ves);
    fwrite(&t1,sizeof(t1),1,tf);
    printf(" Закончить?  y/n ");
    ch=getch();
  }
  while (ch != 'y');
  fclose(tf);
}
void find(FILE *tf)
{ char c,tov[20];
  system("CLS");
  tf=fopen("file1.dat","rb+"); // открытие бинарного файла для чтения и записи
  int i=1;
  puts("ФИО пассажира: ");
  gets(tov);
  fread(&t1,sizeof(t1),1,tf);
  while (!feof(tf))
  {  if (strcmp(t1.name,tov)==0 or strcmp(t1.c,tov)==0 or strcmp(t1.kol,tov)==0 )
     {
        printf("%d)%s %s %s\nКол-во мест: %d\nВес багажа(кг): %.2f\n",i,t1.name,t1.c,t1.kol,t1.mest,t1.ves);
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
  
