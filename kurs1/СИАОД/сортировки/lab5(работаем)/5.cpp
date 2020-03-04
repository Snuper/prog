#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
int M=0, C=0;

void Tab(int *data){
		char in[10];
		int a,b,c,d,e,i,j;
	 
   //tablica
   initwindow(900,210);
   rectangle(10,10,850,185);
   line(70,10,70,185); //линия после N
   line(130,10,130,185); //линия после M+C теорет
   line(130,35,850,35); //линия с M+C разных сортировок
   outtextxy(35,25,"N");
   outtextxy(85,15,"M+C");
   outtextxy(75,35,"теорет.");
   for(i=1;i<4;i++){ //выделяем места для записей M+C разных сортировок(i+1 - построит место под одну сортировку) 
   	line(130+i*180,10,130+i*180,185);
   }
   for(i=1;i<12;i++){  //стодлбцы для записи ранд убыв и возр массивов
   	line(130+i*60,35,130+i*60,185);
   }
   for (i=1;i<6;i++){ //строки
   	line(10,35+i*25,850,35+i*25);
   }
   outtextxy(28,65,"100");
   outtextxy(28,90,"200");
   outtextxy(28,115,"300");
   outtextxy(28,140,"400");
   outtextxy(28,165,"500");
   outtextxy(205,15,"M+C(B)");
   outtextxy(385,15,"M+C(Sh)");
   outtextxy(385+180,15,"M+C(I)");
   outtextxy(385+180*2,15,"M+C(Sl)");
   for(i=0;i<4;i++){
   	outtextxy(140+i*180,40,"Убыв.");
	outtextxy(200+i*180,40,"Ранд.");
	outtextxy(260+i*180,40,"Возр."); 
   }
   for(i=1;i<6;i++){
   	sprintf(in,"%d",data[i]);
   outtextxy(75,40+25*i,in);
   }
   for(i=6,j=0;i<21;i+=3,j++){//заполнение бабла
   	sprintf(in,"%d",data[i]);
   outtextxy(140,65+j*25,in);
   sprintf(in,"%d",data[i+1]);
   outtextxy(200,65+j*25,in);
   sprintf(in,"%d",data[i+2]);
   outtextxy(260,65+j*25,in);
   }
   for(i=21,j=0;i<36;i+=3,j++){//заполнение шейкера
   	sprintf(in,"%d",data[i]);
   outtextxy(320,65+j*25,in);
   sprintf(in,"%d",data[i+1]);
   outtextxy(380,65+j*25,in);
   sprintf(in,"%d",data[i+2]);
   outtextxy(440,65+j*25,in);
   }
    for(i=36,j=0;i<51;i+=3,j++){//заполнение инсерта
   	sprintf(in,"%d",data[i]);
   outtextxy(320+180,65+j*25,in);
   sprintf(in,"%d",data[i+1]);
   outtextxy(380+180,65+j*25,in);
   sprintf(in,"%d",data[i+2]);
   outtextxy(440+180,65+j*25,in);
   }
   for(i=51,j=0;i<66;i+=3,j++){//заполнение селекта
   	sprintf(in,"%d",data[i]);
   outtextxy(320+360,65+j*25,in);
   sprintf(in,"%d",data[i+1]);
   outtextxy(380+360,65+j*25,in);
   sprintf(in,"%d",data[i+2]);
   outtextxy(440+360,65+j*25,in);
   }
   getch();
   closegraph();
}

void BubbleSort(int *p, int n){
	int i,t,j,u;
	M=0; C=0;
	
	for (i=0;i<n;i++){
		for (j=n-1;j>i;j--)
		{
		     C+=1;
		     if (p[j]<p[j-1]){
			 t=p[j];
			 p[j]=p[j-1];
			 p[j-1]=t;
			 M+=3;
		    }
		}
	} 
}
void ShakerSort(int *p, int n){
	int l=0, r=n-1,k=n-1,t,i;
	M=0;
	C=0;
	do{

	for(i=r;i>l;i--){
		C++;
			if(p[i]<p[i-1]){
				t=p[i];
				p[i]=p[i-1];
				p[i-1]=t;
				k=i;
				M+=3;
			}
		}
		l=k;
		for(i=l;i<r;i++){
			C++;
			if(p[i]>p[i+1]){
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=t;
				k=i;
				M+=3;
			}
		}
		r=k;
	}while(l<r);
}
void InsertSort(int *a, int n)
{
	int i,j,k,l;
	M=0;C=0;
	for(i=1;i<n;i++){
		k=a[i];
		++M;
		for(j=i;j>0;j--){
			C++;
			if(k<a[j-1]){
				a[j]=a[j-1];
			    M++;
			}else break;
		}
		a[j]=k;
		++M;
	}
}
void SelectSort(int *a, int n)

{ M=0; C=0;

    int i, j, p, k;

    printf("\n");

    for (i = 0; i < n-1; i++)
	{
        k = i;
        for (j = i + 1; j < n; j++)
        {
            C++;
			if (a[j] < a[k]){
				k = j;
        					}        
        }
        
    	M+=3;
		p = a[i];
        a[i] = a[k];
        a[k] = p;  
    }
}
void FillInc(int *a, int n)

{

    int i;

    for (i = 0; i < n; i++)

    {

        a[i] = i;

    }
}
void FillRand(int *a, int n)


{

    int i;

    for (i = 0; i < n; i++)

    {

        a[i] = rand() %10000 ;
    }
}

void FillDec(int *a, int n)

{

    int i;

    for (i=0;i<n;i++)

    {

        a[i] =n-1- i;
    }
}
int Make(int *a, int n, int *data,int y){
	a= new int [n];  // работа с массивом в 100 элементов
  if ( a == NULL ) 
 {  
     return 1; 
 }
	 FillDec(a,n);
	BubbleSort(a,n);
	data[y]=M+C;
	FillDec(a,n);
	ShakerSort(a,n);
 	data[y+15]=M+C;
 	FillDec(a,n);
	InsertSort(a,n);
	data[y+30]=M+C;
	FillDec(a,n);
	SelectSort(a,n);
 	data[y+45]=M+C;
 	
 	FillRand(a,n);
 	BubbleSort(a,n);
 	data[y+1]=M+C;
 	FillRand(a,n);
 	ShakerSort(a,n);
 	data[y+16]=M+C;
 	FillRand(a,n);
 	InsertSort(a,n);
 	data[y+31]=M+C;
 	FillRand(a,n);
 	SelectSort(a,n);
 	data[y+46]=M+C;
 	
 	FillInc(a,n);
 	BubbleSort(a,n);
 	data[y+2]=M+C;
 	FillInc(a,n);
 	ShakerSort(a,n);
 	data[y+17]=M+C;
 	FillInc(a,n);
 	InsertSort(a,n);
 	data[y+32]=M+C;
 	FillInc(a,n);
 	SelectSort(a,n);
 	data[y+47]=M+C;
 	delete a;
 	return 0;
}
int main(){
	 int *a;  
	 int i;
	 int data[36+30];
	 int s=0;
  //1,2,3,4,5- M+C теорет для 100,200,300,400 и 500 элементов в массиве. 6,7,8 -М+С в возраст, убыв и ранд массивах 100. 9,10,11 -М+С в возраст, убыв и ранд массивах 200. 12,13,14 - М+С в возраст, убыв и ранд массивах 300. 15,16,17 - М+С в возраст, убыв и ранд массивах 400. 18,19,20 -М+С в возраст, убыв и ранд массивах 500                                                                                                                
  //21-35 : убыв ранд возраст шейкер
  srand(time(NULL));
  for (i=1;i<=5;i++)
  data[i]=3*(i*100-1)+(i*i*10000-i*100);
	s= Make(a,100,data,6);
	if (s==1)
		{
     printf("ERROR");
    return 1; 
 
	}
  s=Make(a,200,data,9);
  if (s==1)
		{
     printf("ERROR");
    return 1; 
 
	}
  s=Make(a,300,data,12);
  if (s==1)
		{
     printf("ERROR");
    return 1; 
 
	}
 s=Make(a,400,data,15);
  if (s==1)
		{
     printf("ERROR");
    return 1; 
 
	}
s=Make(a,500,data,18);
  if (s==1)
		{
     printf("ERROR");
    return 1; 
 
	}
delete a;
a=NULL;
Tab(data);
return 0;	
}
