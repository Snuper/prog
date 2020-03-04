#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

int C=0,M=0; 
int pam[5],pam2[5];
void PrintMas (int r ,int k[])
{
for (int s=0;s<r;s++)
printf ("%d ",k[s]);
return;
}

void FillInc (int r ,int k[])
{
for(int s=0;s<r;s++)
k[s]=s;
return;
}

void FillDec (int r ,int k[])
{int m=r;
m--;
for(int s=0;s<r;s++,m--)
k[s]=m;
return;
}

void FillRand (int r ,int k[])
{
for(int s=0;s<r;s++)
k[s]= rand() % (10+10+1)-10;
}

void ShakerSort (int r,int k[])
{int L=0,R=r-1,i,K=r-1,temp,flag;
do{flag=0;
for(i=L;i<R;i++){
	C++;
	if(k[i]>k[i+1]){
		temp=k[i];
		k[i]=k[i+1];
		k[i+1]=temp;
		M+=3;
		flag=1;
	}
}R--;

for(i=R;i>L;i--){ C++;
	if(k[i]<k[i-1]){
		temp=k[i];
		k[i]=k[i-1];
		k[i-1]=temp;
		M+=3;
		flag=1;
	}
}L++;
}while((L<R)&&(flag>0));

}

void BubbleSort (int r, int k[]){
int i,j,temp;
	for(i=0;i<r-1;i++){
	 for(j=0;j<r-i-1;j++){C++;
	  if(k[j]>k[j+1]){
	  	
	  	temp=k[j];
	  	k[j]=k[j+1];
	  	k[j+1]=temp;
	  	M+=3;
	  	}
     }
 }
}

void draw(){
	int i;
rectangle(50,400,750,50);
for(i=0;i<5;i++){
moveto(50,350-(i*50));
lineto(750,350-(i*50));
}
moveto(150,100);
lineto(750,100);
for(i=0;i<7;i++)
{
	moveto(150+(i*100),400);
	lineto(150+(i*100),100);
}
moveto(150,50);
lineto(150,100);
moveto(450,50);
lineto(450,100);
outtextxy ( 75, 75, "n");
outtextxy ( 75, 175, "100");
outtextxy ( 75, 225, "200");
outtextxy ( 75, 275, "300");
outtextxy ( 75, 325, "400");
outtextxy ( 75, 375, "500");
outtextxy ( 175, 75, "Mf+Cf bubble");
outtextxy ( 550, 75, "Mf+Cf shaker");
outtextxy ( 160, 125, "Dec");
outtextxy ( 260, 125, "Rand");
outtextxy ( 360, 125, "Inc");
outtextxy ( 460, 125, "Dec");
outtextxy ( 560, 125, "Rand");
outtextxy ( 660, 125, "Inc");
}

		void sortirovka(){
int *a,*b,m=100,sum,snos=0,i;
 char str[100];	
a = new int [m]; 
b = new int [m];

draw();
srand(time(0));
while(m<=500){
a = new int [m]; 
//b = new int [m];	
FillRand(m,a);
//for(i=0;i<m;i++)
//b[i]=a[i];
BubbleSort(m,a);
sum=M+C;
pam[snos]=sum;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 260, 175+snos*50, str);
/*
M=0,C=0;
ShakerSort(m,b);
sum=M+C;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 560, 175+snos, str);
*/
M=0,C=0;
FillDec(m,a);
BubbleSort(m,a);
sum=M+C;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 160, 175+snos*50, str);
M=0,C=0;
FillInc(m,a);
BubbleSort(m,a);
sum=M+C;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 360, 175+snos*50, str);
snos+=1;
m+=100;
M=0,C=0;
delete[] a;
//delete[] b;
}
snos=0;
m=100;
while(m<=500){
a = new int [m]; 	
	
FillRand(m,a);
ShakerSort(m,a);
sum=M+C;
pam2[snos]=sum;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 560, 175+snos*50, str);
M=0,C=0;
FillDec(m,a);
ShakerSort(m,a);
sum=M+C;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 460, 175+snos*50, str);
M=0,C=0;
FillInc(m,a);
ShakerSort(m,a);
sum=M+C;
sum=snprintf(str,100,"%d",sum);
outtextxy ( 660, 175+snos*50, str);
snos+=1;
m+=100;
M=0,C=0;
delete[] a;
}
}

void graph(){
	int x,www,i,cord=0;
moveto(850,550); 
lineto(850,50);
lineto(840,60);
moveto(850,50);
lineto(860,60);
moveto(850,550);
lineto(1650,550);
lineto(1640,540);
moveto(1650,550);
lineto(1640,560);
moveto(850,550); 
x=50;
while(x<550){
	x+=20;
	moveto(850,x);
	lineto(854,x);
	lineto(846,x);
	}
	setcolor(WHITE);
outtextxy ( 822, 520, "20");
outtextxy ( 822, 35, "n");
x=850;
while(x<1600){
	x+=20;
	moveto(x,550);
	lineto(x,554);
	lineto(x,546);
	}
		setcolor(WHITE);
outtextxy ( 860, 560, "10k");
outtextxy ( 1660, 560, "M+C");
setcolor(GREEN);
moveto(850,550);
for(i=0;i<5;i++)
{www=pam[i]/10000;
www*=20;
cord+=100;
lineto(850+www,550-cord);
}
outtextxy ( 1300, 20, "BUBBLE");
cord=0;
setcolor(YELLOW);
moveto(850,550);
for(i=0;i<5;i++)
{www=pam2[i]/10000;
www*=20;
cord+=100;
lineto(850+www,550-cord);
}
outtextxy ( 1500, 20, "SHAKER");
}




int main(){
initwindow(1600,600);
	sortirovka();
	graph();
while(1){
	if ( kbhit() ) 
if ( getch() == 27 ) break;}

}















