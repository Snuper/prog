#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int random (int N) { return rand() % N; }
const int n=500;
void FillInc(int A[n],int);
void FillRand(int A[n],int);
void PrintMas(int A[n],int);
void FillDec(int A[n],int);
int CheckSum(int A[n],int);
int RunNumber(int A[n],int);
void SelectSort(int A[n], int);
void BubbleSort(int A[n], int);

main(){
int A[n], i, sum, ser1,c,i2,m,m1,mc;
long long x=0;



for(m=100;m<=500;m+=100){
c=(m*m-m)/2;
m1=(c*3)/2;
mc=m1+c;
printf("\nTeor = %d |", mc);
//printf("Teoreticheski = %d", mc);
FillInc(A,m);
BubbleSort(A,m);

FillDec(A,m);
BubbleSort(A,m);

FillRand(A,m);
BubbleSort(A,m);
printf("\n==================================================\n");
}
//PrintMas(A,n);

//RunNumber(A,n);
//CheckSum(A,n);

getche();
}



void FillInc(int *A,int n){
     int c;
     c=(n*n-n)/2;
	//printf("FillInc =======\n");
	//printf("Zameni T = 0 === Sravnenia T - %d\n", c);
    int i;
	for(i=0;i<n;i++) {
    A[i]=i;
    }
}

void FillDec(int *A,int n){
	int m,c;
	c=(n*n-n)/2;
    //printf("FillDec =======\n");
	m=c*3;
	//printf("Zameni T = %d === Sravnenia T - %d\n", m, c);
    int i,j;
	for(i=n-1,j=0;i>=0;i--,j++) {
    A[i]=j;
    }
}

void FillRand(int *A, int n){
	int m,a,b,i,c,mc;
	c=(n*n-n)/2;
    //printf("FillRand =======\n");
	m=(c*3)/2;
	mc=m+c;
	//printf("Teoreticheski = %d\n", mc);
     //printf("Vvedite a b: ");
     //scanf("%d %d", &a, &b);
     for(i=0;i<n;i++) {
		//A[i]= random(b-a+1)+a;
		A[i]= random(15);
	}
}


void PrintMas(int A[n],int n){
     int i;
printf("Elementy massiva: ");
     for (i=0;i<n;i++) {
     printf("%d ", A[i]);}
printf("\n");
}


int CheckSum(int A[n],int n){
    int i;
    long long sum=0;
    for (i=0;i<n;i++) {
sum+=A[i];
}
return sum; 

}


int RunNumber(int A[n],int){
     int i,k=0,ser=1;
     for(i=0;i<n-1;i++){
        if (A[i]<A[i+1]) k++;
        else {k=0; ser++;}
        }
return ser; 

}


void SelectSort(int A[n], int){
	int i,j,k,t,m1=0,c1=0,mt,ct;
	for(i=0;i<n-1;i++) {
        k=i;
		for(j=i;j<n;j++){
			c1++;
			if(A[j]<A[k]) k=j;
		}
		t=A[k];
		A[k]=A[i];
		A[i]=t;
		m1+=3;
	}
	mt=3*(n-1);
	ct=(n*n-n)/2;
    printf("SeilorMoon ");
	for (i=0;i<n;i++) printf("== %d ",A[i]);
	printf("\n");
	printf("Zameni = %d - %d \n",mt,m1);
	printf("Sravnenia = %d - %d \n",ct,c1);
}


void BubbleSort(int *A, int n){
  int i,j,t,m1=0,c1=0,mc;
  for (i=0;i<n;i++){
    for (j=0;j<n-1-i;j++){
		c1++;
      if (A[j]>A[j+1]){
        t=A[j];
		A[j]=A[j+1];
		A[j+1]=t;
		m1+=3;
      } 
    }
  }
//	mt=3*(n-1);
	//ct=(n*n-n)/2;
	mc=m1+c1;
	printf(" %d |", mc);
}






