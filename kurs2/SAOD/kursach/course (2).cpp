#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>


int mp=0, cp=0, rec=0;
bool p=true;
using namespace std;




struct record2
{
	char a[30];
	unsigned short int b;
	char c[10];
	char d[22];
	
};

void QuickSortSum(record2* A, int l, int r, int k) {
	unsigned short int x=A[(l+r)/2].b;
	int  i=l, j=r;
	record2 Swap;
	mp++;
	k++;
	while (i<=j) {
		while (cp++, (A[i].b)<x) i++;
		while (cp++, (A[j].b)>x) j--;
		if (i<=j) {
			Swap=A[i];
			A[i]=A[j];
			A[j]=Swap;
			mp+=3;
			i++;
			j--;
		}
	}
	if (l<j) QuickSortSum(A, l, j, k);
	if (i<r) QuickSortSum(A, i, r, k);
	if (rec<k) rec=k;
}

void QuickSortName(record2* A, int l, int r, int k) {
	char* x=A[(l+r)/2].d;
	int  i=l, j=r;
	record2 Swap;
	mp++;
	k++;
	int cmpi,cmpj;
	while (i<=j) {
		cmpi=strcmp(A[i].d,x);
		cmpi=strcmp(A[j].d,x);

		while (cp++, (cmpi<0)) i++;
		while (cp++, (cmpj>0)) j--;
		{	
			cmpi=strcmp(A[i].d,x);
			cmpi=strcmp(A[j].d,x);	
			if (i<=j) {
				Swap=A[i];
				A[i]=A[j];
				A[j]=Swap;
				mp+=3;
				i++;
				j--;
			}
		}
	}
	if (l<j) QuickSortName(A, l, j, k);
	if (i<r) QuickSortName(A, i, r, k);
	if (rec<k) rec=k;
}


void Reader_20(FILE* f, record2* mas2){
	int i=0,hit=0;
	i=fread((record2 *)mas2, sizeof(record2), 4000, f);
	
    i=0;
	while(i<4000)
	{
		cout<<i+1<<") "<<mas2[i].a<<" "<<mas2[i].b<<"  "<<mas2[i].c<<"  "<<mas2[i].d<<"  "<<endl;
		i++;
		if (i%20==0) {
			cout<< "\nDo You want to finish reading? Press Y for exit, or press another button for continue\n"<<endl;
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
	while(p){
	cout<<"1- Read all\n 2- Read by 20\n3- Sort with sum\n4- Sort by Name(STILL NOT WORKS)"<<endl;
	hit = getch();	
	if(hit==49) {
		Reader_All(fp,mas2);}
	else if (hit==50) {
		Reader_20(fp,mas2);
	}
	else if (hit==51){
	
			QuickSortSum(mas2,0,3999,0);
	}
	else if (hit==52){
	
			QuickSortName(mas2,0,3999,0);
	}
	else if(hit==27){
		break;
	} else
	 cout<<"\nError! Try again!\n"<<endl;}

	fclose(fp);
	return 0;
}
