#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

int C=0,M=0; 
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

int main(){
int  m=100;
int *a,B,R,pract,teor,practD,practI,x,pam[5],spam=0,ii;
while(m<501){
a = new int [m]; 
  if ( a == NULL ) 
  {  
     printf(" Не выделена память ");
    return 1; 
  }



srand(time(0));
FillRand (m,a);
printf("\n");
printf("_________________________________________________________________");
BubbleSort (m,a);
printf("\n|     n   |     M+C teor |           |Mfact+Cfact   |           |");
printf("\n|         |              |dec        |rand          |  inc      |");
printf("\n|_________|______________|______________________________________|");
pract=M+C;
M=0,C=0;
pam[spam]=pract;
spam++;
FillDec (m,a);
BubbleSort (m,a);
practD=M+C;
M=0,C=0;
FillInc (m,a);
BubbleSort (m,a);
practI=M+C;

teor=(((m*m)-m)/2)+((3*((m*m)-m))/4);
printf("\n|   %d   | %d        |%d            %d          %d  |",m,teor,practD,pract,practI);
printf("\n|_________|______________|______________________________________|");
delete a; 
a=NULL;
m+=100;
M=0,C=0;

}




system("PAUSE");
}


