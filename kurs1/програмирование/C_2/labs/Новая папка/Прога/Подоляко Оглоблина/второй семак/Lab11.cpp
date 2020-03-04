#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

struct tov {char fname[15];char mname[15];char lname[15]; int kolbag; float mas;} t1;
void input(FILE *);
void print(FILE *);
void app(FILE *);
void findel(FILE *);

main(){
	char c;
	FILE *tf;
	while (1){ 
  		system("CLS");
    	puts("  1 - new file");
    	puts("  2 - see file");
    	puts("  3 - add in file");
    	puts("  4 - find and delete");
    	puts("  0 - exit");
    	c=getch();
    	switch(c){
			case '1':input(tf);break;
    		case '2':print(tf);break;
    		case '3':app(tf);break;
    		case '4':findel(tf);break;
    		case '0':return 0;
    		default :system("CLS");puts("incorrect key");printf("try again...");getch();
    	}
	}
}

void input(FILE *tf){ 
	char ch;
	tf=fopen("file.dat","wb"); 
	system("CLS");
	printf("\ninput passenger:\n");
	do{
		printf("\n FIO: "); scanf("%s %s %s",&t1.fname,&t1.mname,&t1.lname);
    	printf(" kolichestvo bag: "); scanf("%d",&t1.kolbag);
    	printf(" weight : "); scanf("%f",&t1.mas);
    	fwrite(&t1,sizeof(t1),1,tf);
    	printf("\n fin?  y/n  ");
		ch=getch();
	}while (ch != 'y');
	fclose(tf);
}

void print(FILE *tf){
	int i;
	system("CLS");
	tf=fopen("file.dat","rb"); // открытие бинарного файла для чтения
	i=1;
	fread(&t1,sizeof(t1),1,tf); // чтение из файла одной структуры t1
	while (!feof(tf)){
		printf("\n%d. %15s %15s %15s - kolichestvo bag: %d \t weight: %.2f",i,t1.fname,t1.mname,t1.lname,t1.kolbag,t1.mas);
		fread(&t1,sizeof(t1),1,tf);
		i++;
	}
	getch();
}

void app(FILE *tf){
	char ch;
	tf=fopen("file.dat","ab");
	system("CLS");
	printf("\ninput passenger:\n");
	do{
		printf("\n FIO: "); scanf("%s %s %s",&t1.fname,&t1.mname,&t1.lname);
    	printf(" kolichestvo bag: "); scanf("%d",&t1.kolbag);
    	printf(" weight: "); scanf("%f",&t1.mas);
    	fwrite(&t1,sizeof(t1),1,tf);
    	printf("\n fin?  y/n  ");
		ch=getch();
	}while (ch != 'y');
	fclose(tf);
}

void findel(FILE *tf){
	FILE *tf2;
	char c;
	tf=fopen("file.dat","rb+");
	tf2=fopen("file2.dat","wb");
	system("CLS");
	fread(&t1,sizeof(t1),1,tf);
	while (!feof(tf)){
		if (t1.mas>10){
			fwrite(&t1,sizeof(t1),1,tf2);
		}
		fread(&t1,sizeof(t1),1,tf);
	}
	fclose(tf);
	fclose(tf2);
	remove("file.dat");
	rename("file2.dat","file.dat");
	tf=tf2;
}
