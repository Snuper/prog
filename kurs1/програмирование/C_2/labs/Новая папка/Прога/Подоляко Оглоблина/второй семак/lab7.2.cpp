#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
int random (int N) { return rand()%N; }
void Summ(int *A[],int S[],int m){
		int i,j,s;
		for (i=0; i<m; i++){
			s=0;
			for(j=0;j<S[i];j++){
				s+=A[i][j];	
			}
	printf("\n Summa stroki %d=%d",i,s);}}
	
int main(){
	int i,n,m,j,s;
	int **A;
	printf("VVedite kolichestvo strok=");
	scanf("%d",&m);
	int *S;
	A=new int *[m];
	S=new int [m];
	if (A==NULL){
	puts("Cannot allocate memory");
	return 1;
} 
if (S==NULL){
	puts("Cannot allocate memory");
	return 1;
} 
	int  a = 0, b = 30;
		srand(time(NULL));		
	for(i=0;i<m;i++){ 
	    printf("dlina=");
	    scanf("%d",&S[i]);
	    A[i]=new  int [S[i]];
		A[i][0]=S[i]; 
		for(j=1;j<S[i];j++)
		A[i][j] = random(b-a+1)+a;
		}
	for (i=0; i<m; i++){
	for(j=0;j<S[i];j++){	
	printf("%4d ",A[i][j]);
	}
	puts("\n");
	}
     Summ(A,S,m);
	for (i=0;i<m;i++){
	delete  A[i];
	A[i]=NULL;}
	delete  A; 
	A=NULL;
	delete  S; 
	S=NULL;
	getch();
	return 0;	
}
