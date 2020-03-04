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

struct spis
{
	record2 e;
	spis* next;
};

void QuickSortSum(record2* A, int l, int r) {
	unsigned short int x=A[(l+r)/2].b;
	int  i=l, j=r;
	record2 Swap;
	while (i<=j) {
		while (A[i].b<x) i++;
		while (A[j].b>x) j--;
		if (i<=j) {
			Swap=A[i];
			A[i]=A[j];
			A[j]=Swap;
			i++;
			j--;
		}
	}
	if (l<j) QuickSortSum(A, l, j);
	if (i<r) QuickSortSum(A, i, r);
}

void QuickSortName(record2* A, int l, int r) {
	char* x=A[r].d;
	int  i=l, j=r;
	record2 Swap;
	
	while (i<=j) {
		
		
		

		while (strcmp(A[i].d,x)<0) i++;
		while (strcmp(A[j].d,x)>0) j--;
		{	
			
		//	cout<<"29";	
			if (i<=j) {
				Swap=A[i];
				A[i]=A[j];
				A[j]=Swap;

				i++;
				j--;
			}
		}
	}
	if (l<j) QuickSortName(A, l, j);
	if (i<r) QuickSortName(A, i, r);
	
}

void Search (record2* A, spis* stack, char* key){
	
	int i=0;
	char x[3];
	char* y;
	
	
	for( i = 0 ; i < 4000 ; i++ ){
		
		y = A[i].c;
		x[0]=y[0];
		x[1]=y[1];
		x[2]=y[2];
		
		if (strcmp(x,key)==0){
			
			stack->e = A[i];
			stack = stack->next;
			
		}
		
	}
	stack->next = NULL;
	
}

void Reader_20(FILE* f, record2* mas2){
	int i=0,hit=0;
	
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
	record2 mas;
	char key[3],koi;
	int hit,i,k=0,l=0,temp,y=0;
	spis* found;
	bool found_after = false;
	
	fp=fopen("testBase3.dat", "rb");
	mas2 = new record2[4000];
	i=fread((record2 *)mas2, sizeof(record2), 4000, fp);

	while(p){
	system("cls");
	cout<<"1- Read all\n2- Read by 20\n3- Sort"<<endl<<"4- Search";
	if (found_after){
		
		cout<<"5 - Read found elements"<<endl;
		
	}
	hit = getch();	
	if(hit==49) {
		Reader_All(fp,mas2);}
	else if (hit==50) {
		Reader_20(fp,mas2);
	}
	else if (hit==51){

			QuickSortSum(mas2,0,3999);
			while(l<4000){
				
				temp=mas2[l].b;
				
				while(temp == mas2[l].b) {
					
					l++;
					
				}
				
				QuickSortName(mas2,k,l-1);
				k=l;
				
			}
			
	}
	else if (hit==52){

		system("cls");
		cout<<" What do you want to find? "<<endl;
		scanf("%c",key);
		
		Search(mas2, found, key);
		found_after = true;	
	}
	else if ((hit==53)&&(found_after)){

			while(found!=NULL){
				
				mas = found->e;
				cout<<y+1<<") "<<mas.a<<" "<<mas.b<<"  "<<mas.c<<"  "<<mas.d<<"  "<<endl;
				found = found->next;
				
			}
		y=0;	
	}
	else if(hit==27){
		break;
	} else
	 cout<<"\nError! Try again!\n"<<endl;}

	fclose(fp);
	return 0;
}
