#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int random (int N) { return rand() % N; }
const int n =6;
void FillInc(int A[n],int);
void FillRand(int A[n],int);
void PrintMas(int A[n],int);
void FillDec(int A[n],int);
int CheckSum(int A[n],int);
int RunNumber(int A[n],int);
void SelectSort(int A[n], int);

main(){
int A[n], i, sum, ser1;
float ns;
long long x=0;

//FillInc(A,n);
FillRand(A,n);
//FillDec(A,n);
PrintMas(A,n);
sum=CheckSum(A,n);
printf("Control summ = %d \n", sum);
ser1=RunNumber(A,n);
printf("Serii: %d \n", ser1);
ns=(float)n/ser1;
printf("SDS - %5.2f \n",ns);
SelectSort(A,n);
PrintMas(A,n);
sum=CheckSum(A,n);
printf("Control summ = %d \n", sum);
ser1=RunNumber(A,n);
printf("Serii: %d \n", ser1);
getche();
}



void FillInc(int A[n],int n){
    int i;
	for(i=0;i<n;i++) {
    A[i]=i;
  //  printf("%d ", A[i]);
    }
//printf("\n");
}

void FillDec(int A[n],int n){
    int i,j;
	for(i=n-1,j=0;i>=0;i--,j++) {
    A[i]=j;
//    printf("%d ", A[i]);
    }
//printf("\n");
}

void FillRand(int A[n], int n){
     int a,b,i;
     printf("Vvedite a b: ");
     scanf("%d %d", &a, &b);
     for(i=0;i<n;i++) {
		A[i]= random(b-a+1)+a;
//		printf("%d ", A[i]);
	}
// printf("\n");
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
return sum; //----------

}

int RunNumber(int A[n],int){
     int i,k=0,ser=1;
     for(i=0;i<n-1;i++){
        if (A[i]<=A[i+1]) k++;
        else {k=0; ser++;}
        }
return ser; //============

}


void SelectSort(int A[n], int){
	int i,j,k,t,m1=0,c1=0,mt,ct;
	for(i=0;i<n-1;i++) {
        k=i;
		for(j=i+1;j<n;j++){
			
			if(A[j]<A[k])
            k=j; 
            c1++;
		}
		if(k!=i){
		t=A[k];
		A[k]=A[i];
		A[i]=t;
		m1+=3;}
	}
	mt=3*(n-1);
	ct=(n*n-n)/2;
//    printf("SeilorMoon ");
//	for (i=0;i<n;i++) printf("== %d ",A[i]);
//	printf("\n");
	printf("Zameni = %d - %d \n",mt,m1);
	printf("Sravnenia = %d - %d \n",ct,c1);
}
