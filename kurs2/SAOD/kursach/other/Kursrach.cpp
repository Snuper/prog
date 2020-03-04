#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct record1
{
	char a[30];
	short int b;
	char c[22];
	char d[10];
	
};

void Reader_20(FILE* f, record1* mas){
	int i=0,hit=0;
	i=fread((record1 *)mas, sizeof(record1), 4000, f);
	
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<mas[i].a<<" "<<mas[i].b<<"  "<<mas[i].c<<"  "<<mas[i].d<<"  "<<endl;
		i++;
		if (i%20==0) {
			cout<< "\nDo You want to complete reading? Press N for exit, or press another button for continue\n"<<endl;
			hit = getch();
//			cout<<" %d "<<hit<<endl;   // проверка нажатой клавиши

 			if ((hit==121)||(hit==27)){
				break;
			}
		}
		
	}

}

void Reader_All(FILE* f, record1* mas){
	int i=0,hit=0;
	i=fread((record1 *)mas, sizeof(record1), 4000, f);
	
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<mas[i].a<<"  "<<mas[i].b<<"  "<<mas[i].c<<"  "<<mas[i].d<<endl;
		i++;
		if (_kbhit()){
			hit = getch();
			if (hit == 27){
				break;
			} else if(hit == 13) {
				while (true){
					if (_kbhit()){
			hit = getch();
			if (hit == 13){
				break;
			}}
			
				}
			}
		}
		
	}

}

int main()
{
	FILE *fp;
	record1* mas;
	int hit;
	fp=fopen("testBase2.dat", "rb");
	mas = new record1[4000];	
	
	while(true){
	cout<<"1- Read all\n 2- Read by 20"<<endl;
	hit = getch();	
	if(hit==49) {
		Reader_All(fp,mas);
		break;}
	else if (hit==50) {
		Reader_20(fp,mas);
		break;
	}
	else cout<<"\nError! Try again!\n"<<endl;}
	
	fclose(fp);
	return 0;
}
