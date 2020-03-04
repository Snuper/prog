#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

struct record
{
	char Familia[15];
	char Name[1];
	char Fathername[1];
};

struct record1
{
	char a[15];
	char c[15];
	char d[15];
	
};

struct record2
{
	char a[30];
	char c[10];
	
};

struct record3
{
	int a;
};

struct record4
{
	int a;
};

int main()
{
	FILE *fp;
	fp=fopen("testBase2.dat", "rb");
	record tt[4000]={0};
	//record1 mas[4000]={0};
	//record2 mas2[4000]={0};
	//record3 mas3[4000]={0};
	//record4 mas4[4000]={0};
	int i=0;
	i=fread((record *)tt, sizeof(record), 4000, fp);
	for(int i=0;i<20;++i)
		cout<<i+1<<" "<<tt[i].Familia<<tt[i].Name<<"."<<tt[i].Fathername<<"."<<endl;
	/*while((i++)<500)
	{
		getchar();
		cout<<mas[i].a<<mas[i].c<<mas[i].d<<endl;
	}
	
	while((i++)<500)
	{
		getchar();
		cout<<mas2[i].a<<mas2[i].c<<endl;
	}
	while((i++)<500)
	{
		getchar();
		cout<<mas3[i].a<<endl;
	}
	i=0;
	
	while((i++)<500)
	{
		getchar();
		cout<<mas4[i].a<<endl;
	}*/
	return 0;
}
