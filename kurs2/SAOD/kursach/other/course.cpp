#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>


using namespace std;




struct record2
{
	char a[30];
	unsigned short int b;
	char c[10];
	char d[22];
	
};

void Reader_20(FILE* f, record2* mas2){
	int i=0,hit=0;
	i=fread((record2 *)mas2, sizeof(record2), 4000, f);
	
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<mas2[i].a<<" "<<mas2[i].b<<"  "<<mas2[i].c<<"  "<<mas2[i].d<<"  "<<endl;
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

void Reader_All(FILE* f, record2* mas2){
	int i=0,hit=0;
	i=fread((record2 *)mas2, sizeof(record2), 4000, f);
	
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<mas2[i].a<<"  "<<mas2[i].b<<"  "<<mas2[i].c<<"  "<<mas2[i].d<<endl;
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
	record2* mas2;
	int hit;
	fp=fopen("testBase3.dat", "rb");
	mas2 = new record2[4000];
	
	
	while(true){
	cout<<"1- Read all\n 2- Read by 20"<<endl;
	hit = getch();	
	if(hit==49) {
		Reader_All(fp,mas2);
		break;}
	else if (hit==50) {
		Reader_20(fp,mas2);
		break;
	}
	else cout<<"\nError! Try again!\n"<<endl;}
	
	fclose(fp);
	return 0;
}
