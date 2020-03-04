#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
void FillRand(int *p, int a){
	int i;
	for (i=0; i<a;i++){
		p[i]=rand()%100+1;
		printf("%d  ",p[i]);
	}
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

int main ()
{
 srand(time(NULL));
 int n, A 
 //printf("Vvedite kolvo elementov v odnom massive:");
 //scanf("%d",&n);
 FillRand(A,n)
 PrintMas(A,n)
}
 
