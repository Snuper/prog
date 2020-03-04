#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
void FillInc(int *p, int a){
	int i;
	for (i=0; i<a;i++){
		p[i]=i;
		printf("%d  ",p[i]);
	}
}

void FillDec(int *p, int a){
	int i;
	for (i=0; i<a;i++){
		p[i]=a-1-i;
		printf("%d  ",p[i]);
	}
}

void FillRand(int *p, int a){
	int i;
	for (i=0; i<a;i++){
		p[i]=rand()%100+1;
		printf("%d  ",p[i]);
	}
}

int CheckSum(int *p, int a){
	int i,s=0;
	for (i=0;i<a;i++)
	s+=p[i];
	return s;
}

int RunNumber(int *p, int a){
	int i,k=1;
	for (i=0;i<a-1;i++){
		if (p[i]>p[i+1]){
			k++;	
		}
		
	}
	return k;
}

void PrintMas(int *p, int a){
	int i;
	for (i=0; i<a;i++)
		printf("%d  ",p[i]);
}

int main(){

	srand(time(NULL));
	int n,b;
	float s;
	printf ("Vvedite kolvo elementov massiva: \n");
    scanf("%d",&n);
    int A[n];
	printf ("FillInc\n");    
		FillInc(A,n);
	    b=RunNumber(A,n);
	    printf("\nRunNumber %d\n",b);
	    b=CheckSum(A,n);
	    printf("\nCheckSum %d\n\n",b);
	printf("FillDec\n");    
		FillDec(A,n);
	    b=RunNumber(A,n);
	    printf("\nRunNumber %d\n",b);
	    b=CheckSum(A,n);
	    printf("\nCheckSum %d\n\n",b);
	printf("FillRand\n");
	    FillRand(A,n);
	    b=RunNumber(A,n);
	    printf("\nRunNumber %d\n",b);
	    b=CheckSum(A,n);
	printf("\nCheckSum %d\n",b);
	printf("\nPrintMas: ");
	PrintMas(A,n);
	system("PAUSE");
	return 0;
}
