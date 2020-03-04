#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
int M=0, C=0;

void Tab(int *data){
		char in[10];
		int a,b,c,d,e;
	 initwindow(1366,768);
   line(50,650,50,50);
   line(50,50,55,55);
    line(50,50,45,55);
    outtextxy(30,55,"N");
   line(50,650,1100,650);
   line(1100,650,1095,645);
   line(1100,650,1095,655);
   outtextxy(1080,625,"M+C");
   outtextxy(40,655,"0");
   outtextxy(15,143,"500");
   line(45,150,55,150);
   outtextxy(15,243,"400");
   line(45,250,55,250);
   outtextxy(15,343,"300");
   line(45,350,55,350);
   outtextxy(15,443,"200");
   line(45,450,55,450);
   outtextxy(15,543,"100");
   line(45,550,55,550);
   a=round(data[7]/500);
   b=round(data[10]/500);
   c=round(data[13]/500);
   d=round(data[16]/500);
   e=round(data[19]/500);
   line(50,650,50+a,550);
   line(50+a,550,50+a+b,450);
   line(50+a+b,450,50+a+b+c,350);
   line(50+a+b+c,350,50+a+b+c+d,250);
   line(50+a+b+c+d,250,50+a+b+c+d+e,150);
   line(50+a,655,50+a,645);
   line(50+a+b,655,50+a+b,645);
   line(50+a+b+c,655,50+a+b+c,645);
   line(50+a+b+c+d,655,50+a+b+c+d,645);
   line(50+a+b+c+d+e,655,50+a+b+c+d+e,645);
   sprintf(in,"%d",data[7]);
   outtextxy(50+a,655,in);
   sprintf(in,"%d",data[1]);
   outtextxy(50+a+b,655,in);
   sprintf(in,"%d",data[13]);
   outtextxy(50+a+b+c,655,in);
   sprintf(in,"%d",data[16]);
   outtextxy(50+a+b+c+d,655,in);
   sprintf(in,"%d",data[19]);
   outtextxy(50+a+b+c+d+e,655,in);
   
   
   //tab
   initwindow(320,195);
   line(10,10,10,60);
   line(10,60,310,60);
   line(70,60,70,10);
   line(70,10,10,10);
   outtextxy(35,25,"N");
   outtextxy(85,15,"M+C");
   outtextxy(75,35,"теорет.");
   line(10,60,10,185);
   line(10,185,70,185);
   line(70,185,70,10);
   outtextxy(28,65,"100");
   outtextxy(28,90,"200");
   outtextxy(28,115,"300");
   outtextxy(28,140,"400");
   outtextxy(28,165,"500");
   line(10,85,310,85);
   line(10,110,310,110);
   line(10,135,310,135);
   line(10,160,310,160);
   rectangle(70,10,310,185);
   line(130,10,130,185);
   line(130,35,310,35);
   line(190,35,190,185);
   line(250,35,250,185);
   outtextxy(205,15,"M+C");
   outtextxy(140,40,"Убыв.");
   outtextxy(200,40,"Ранд.");
   outtextxy(260,40,"Возр.");
   sprintf(in,"%d",data[1]);
   outtextxy(80,65,in);
   sprintf(in,"%d",data[2]);
   outtextxy(80,90,in);
   sprintf(in,"%d",data[3]);
   outtextxy(80,115,in);
   sprintf(in,"%d",data[4]);
   outtextxy(75,140,in);
   sprintf(in,"%d",data[5]);
   outtextxy(75,165,in);
   sprintf(in,"%d",data[6]);
   outtextxy(140,65,in);
   sprintf(in,"%d",data[7]);
   outtextxy(200,65,in);
   sprintf(in,"%d",data[8]);
   outtextxy(260,65,in);
   sprintf(in,"%d",data[9]);
   outtextxy(140,90,in);
   sprintf(in,"%d",data[10]);
   outtextxy(200,90,in);
   sprintf(in,"%d",data[11]);
   outtextxy(260,90,in);
   sprintf(in,"%d",data[12]);
   outtextxy(140,115,in);
   sprintf(in,"%d",data[13]);
   outtextxy(200,115,in);
   sprintf(in,"%d",data[14]);
   outtextxy(260,115,in);
   sprintf(in,"%d",data[15]);
   outtextxy(140,140,in);
   sprintf(in,"%d",data[16]);
   outtextxy(200,140,in);
   sprintf(in,"%d",data[17]);
   outtextxy(260,140,in);
   sprintf(in,"%d",data[18]);
   outtextxy(140,165,in);
   sprintf(in,"%d",data[19]);
   outtextxy(200,165,in);
   sprintf(in,"%d",data[20]);
   outtextxy(260,165,in);
   getch();
   closegraph(2);
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
			 M+=1;
		    }
		}
	} //printf("\n%d",M+C);
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
int main(){
	 int *a;  
	 int i;
	 int data[21];
  //1,2,3,4,5- M+C теорет для 100,200,300,400 и 500 элементов в массиве. 6,7,8 -М+С в возраст, убыв и ранд массивах 100. 9,10,11 -М+С в возраст, убыв и ранд массивах 200. 12,13,14 - М+С в возраст, убыв и ранд массивах 300. 15,16,17 - М+С в возраст, убыв и ранд массивах 400. 18,19,20 -М+С в возраст, убыв и ранд массивах 500                                                                                                                
  srand(time(NULL));
  for (i=1;i<=5;i++)
  data[i]=3*(i*100-1)+(i*i*10000-i*100);
  a= new int [100];  // работа с массивом в 100 элементов
  if ( a == NULL ) 
 {  
     printf("ERROR");
    return 1; 
 }
 FillDec(a,100);
 BubbleSort(a,100);
 data[6]=M+C;
 FillRand(a,100);
 for (i=0;i<100;i++)
 printf("%d ",a[i]);
 puts("\n");
 BubbleSort(a,100);
 for (i=0;i<100;i++)
 printf("%d ",a[i]);
 data[7]=M+C;
 FillInc(a,100);
 BubbleSort(a,100);
 data[8]=M+C;
delete a;
  a= new int [200];//massive 200
  if ( a == NULL ) 
 {  
     printf("ERROR");
    return 1; 
 }
 FillDec(a,200);
 BubbleSort(a,200);
 data[9]=M+C;
 FillRand(a,200);
 BubbleSort(a,200);
 data[10]=M+C;
 FillInc(a,200);
 BubbleSort(a,200);
 data[11]=M+C;
delete a;
  a= new int [300];//massive 300
  if ( a == NULL ) 
 {  
     printf("ERROR");
    return 1; 
 }
 FillDec(a,300);
 BubbleSort(a,300);
 data[12]=M+C;
 FillRand(a,300);
 BubbleSort(a,300);
 data[13]=M+C;
 FillInc(a,300);
 BubbleSort(a,300);
 data[14]=M+C;
delete a;
 a= new int [400];//massive 400
  if ( a == NULL ) 
 {  
     printf("ERROR");
    return 1; 
 }
 FillDec(a,400);
 BubbleSort(a,400);
 data[15]=M+C;
 FillRand(a,400);
 BubbleSort(a,400);
 data[16]=M+C;
 FillInc(a,400);
 BubbleSort(a,400);
 data[17]=M+C;
delete a;
 a= new int [500];//massive 500
  if ( a == NULL ) 
 {  
     printf("ERROR");
    return 1; 
 }
 FillDec(a,500);
 BubbleSort(a,500);
 data[18]=M+C;
 FillRand(a,500);
 BubbleSort(a,500);
 data[19]=M+C;
 FillInc(a,500);
 BubbleSort(a,500);
 data[20]=M+C;
delete a;
a=NULL;
Tab(data);
return 0;	
}
