#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;

int *a, *b, *c;
int M, C;

void FillInc (int a[], int n){
     for (int i = 0; i < n; i++)
         a[i]=i;         
}

void FillDec (int a[], int n){
     for (int i = n, k = 0; i > 0; i--, k++)
         a[k]=i;
}
     
void FillRand (int a[], int n){
      for (int i = 0; i < n; i++)
         a[i]= -50 + rand() % 100;
}
     
int CheckSum (int a[], int n){
     int sum = 0;
     for (int i = 0; i < n; i++)
         sum += a[i];
     return sum;
}

int RunNumber (int a[], int n){
     int sum_ser = 1;
         for (int i = 0; i < n-1; i++)
                 if (a [i] > a [i+1]){
                    sum_ser += 1;
                    }
     return sum_ser;
}
                
void PrintMas (int a[], int n){
     for (int i = 0; i < n; i++)
         cout<<a[i]<<" ";
     cout<<endl;
}   

void BubbleSort(int a[], int n){
	M = 0, C = 0;
	int i, j, temp;
	for (i = 0; i < n - 1; i ++){
		for (j = n - 1; j > i; j --){
			C ++;
			if (a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
				M ++;
			}
		}
	}
	a[n] = M + C;
}          

void grafic(int a_f[]){
	initwindow (800, 800);
	char in[10];
	setcolor(WHITE); 
	moveto(400,0); 
	lineto(400, 800); 
	moveto(0,400); 
	line(400,0,395,5);
	line(400,0,405,5);
	outtextxy ( 410, 8, (char *)"M+C (fact)" );
	line(395,383,405,383);
	line(395,354,405,354);
	line(395,325,405,325);
	line(395,278,405,278);
	line(395,230,405,230);
   sprintf(in,"%d",a_f[0]);
   outtextxy(360,375,in);
   sprintf(in,"%d",a_f[1]);
   outtextxy(350,346,in);
   sprintf(in,"%d",a_f[2]);
   outtextxy(350,317,in);
   sprintf(in,"%d",a_f[3]);
   outtextxy(345,270,in);
   sprintf(in,"%d",a_f[4]);
   outtextxy(345,222,in);
	 
    setcolor(WHITE); 
	moveto(0,400); 
	lineto(800, 400);
	line(800,400,795,395);
	line(800,400,795,405);
    outtextxy ( 780, 380, (char *)"n" );
    line(500,395,500,405);
    outtextxy ( 500, 410, (char *)" 100");
    line(550,395,550,405);
    outtextxy ( 550, 410, (char *)"200" );
    line(600,395,600,405);
    outtextxy ( 600, 410, (char *)"300" );
    line(650,395,650,405);
    outtextxy ( 650, 410, (char *)"400" );
    line(700,395,700,405);
    outtextxy ( 700, 410, (char *)"500" );
    

    setcolor(4);
    moveto(400 ,400);
    for(int n = 100, j = 0; n < 501, j < 5; n += 100, j ++){
		lineto(400 + n, (400-(a_f[j] / 400)));
    }
  getch();
  closegraph();
}

int theor (int k){
	return ((k * k - k) / 2) + (3 * (k * k - k) / 4);
}  

int main(){
	int a_f [5];
	int b_f [5];
	int c_f [5];
	srand(time(NULL));
	for (int n = 100, j = 0; n < 501, j < 5; n += 100, j ++) {
    	a = new int [n+1]; // rand
    	b = new int [n+1]; //inc
    	c = new int [n+1]; //dec
    	FillRand(a, n);
    	FillInc(b, n);
    	FillDec(c, n);
    	BubbleSort(a, n);
    	BubbleSort(b, n);	
    	BubbleSort(c, n);	
    	a_f[j] = a[n];
    	b_f[j] = b[n];
    	c_f[j] = c[n];
    	delete a;
    	delete b;
    	delete c;
	}	
 	
 	cout<<endl<<endl;
    cout<<" ______________________________________________________"<<endl;
    cout<<"|  n  |   M+C (theor)   |          M+C (fact)          |"<<endl;
    cout<<"|     |                 |------------------------------|"<<endl;
    cout<<"|     |                 |   dec   |   rand   |   inc   |"<<endl;
    cout<<"|-----|-----------------|---------|----------|---------|"<<endl;
    cout<<"| 100 |      "<<theor(100)<<"      |  "<<c_f[0]<<"   |   "<<a_f[0]<<"   |  "<<b_f[0]<<"   |"<<endl;
    cout<<"|-----|-----------------|---------|----------|---------|"<<endl;
    cout<<"| 200 |      "<<theor(200)<<"      |  "<<c_f[1]<<"  |   "<<a_f[1]<<"  |  "<<b_f[1]<<"  |"<<endl;
    cout<<"|-----|-----------------|---------|----------|---------|"<<endl;
    cout<<"| 300 |      "<<theor(300)<<"     |  "<<c_f[2]<<"  |   "<<a_f[2]<<"  |  "<<b_f[2]<<"  |"<<endl;
    cout<<"|-----|-----------------|---------|----------|---------|"<<endl;
    cout<<"| 400 |      "<<theor(400)<<"     |  "<<c_f[3]<<" |   "<<a_f[3]<<" |  "<<b_f[3]<<"  |"<<endl;
    cout<<"|-----|-----------------|---------|----------|---------|"<<endl;
    cout<<"| 500 |      "<<theor(500)<<"     |  "<<c_f[4]<<" |   "<<a_f[4]<<" |  "<<b_f[4]<<" |"<<endl;
    cout<<"|-----|-----------------|---------|----------|---------|"<<endl;
    
    grafic(a_f);

    system ("PAUSE");
    return 0;
}


