#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;	
};

void Reader_20(FILE* f, record* tt)
{
	int i=0,hit=0;
	i=fread((record *)tt, sizeof(record), 4000, f);
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<tt[i].author<<" "<<tt[i].title<<" "<<tt[i].publisher<<" "<<tt[i].year<<" "<<tt[i].num_of_page<<endl;
		i++;
		if (i%20==0)
		{
			cout<< "\nDo You want to complete reading? Press N for exit, or press another button for continue\n"<<endl;
			hit = getch();
 			if ((hit==121)||(hit==27))
			{
				break;
			}
		}	
	}
}

void Reader_All(FILE* f, record* tt)
{
	int i=0,hit=0;
	i=fread((record *)tt, sizeof(record), 4000, f);
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<tt[i].author<<" "<<tt[i].title<<" "<<tt[i].publisher<<" "<<tt[i].year<<" "<<tt[i].num_of_page<<endl;
		i++;
		if (_kbhit())
		{
			hit = getch();
			if (hit == 27)
			{
				break;
			}
				else if(hit == 13)
				{
					while (true)
					{
						if (_kbhit())
						{
							hit = getch();
							if (hit == 13)
							{
								break;
							}
						}
					}
				}
		}	
	}
}

int main()
{
	FILE *fp;
	record* tt;
	int hit;
	fp=fopen("testBase1.dat", "rb");
	tt = new record[4000];	
	
	while(true){
	cout<<"1- Read all\n2- Read by 20"<<endl;
	hit = getch();	
	if(hit==49) {
		Reader_All(fp,tt);
		break;}
	else if (hit==50) {
		Reader_20(fp,tt);
		break;
	}
	else cout<<"\nError! Try again!\n"<<endl;}
	
	fclose(fp);
	return 0;
}
