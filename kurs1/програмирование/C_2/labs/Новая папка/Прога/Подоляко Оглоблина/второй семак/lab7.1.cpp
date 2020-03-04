#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
int random (int N) { return rand()%N; }
int A[100],B[1000];
void Poiskperebor(int A[],int B[],int n, int m,int k){
	
	int i,s,sravn=0;
	for(i=0;i<100;i++){
		sravn++;
		if (A[i]==k) {
		s=i;break;}	
	}
	printf("A[%d]=%d sravneniya=%d",s,A[s],sravn);
	sravn=0;
		for(i=0;i<m;i++){
		sravn++;
		if (B[i]==k) {
		s=i;break; }	
	}
	printf("\n B[%d]=%d sravneniya=%d",s,B[s],sravn);
}
void Bipoisk(const int A[],const int B[],const int n, const int s,int k){
	int C=0;
	int L=1, R=n, Find=0, m;
	while (L<R)
	{
		m=(int)((L+R)/2);
		C++;
		if (A[m] > k) L=m+1;
		else R=m;
		
	}
	C++;
	
	printf("\n A[%d]=%d sravneniya=%d ",R,k,C);
	L=1,R=1000,C=0;
	while (L<R)
	{
		m=(int)((L+R)/2);
		C++;
		if (A[m] > k) L=m+1;
		else R=m;
		
	}
	C++;
	
	printf("\n B[%d]=%d sravneniya=%d ",R,k,C);
	}
void Sort(int A[],int B[],int n, int m){
	int i,j,k,t;
	for (i = 0; i < n-1; i++) 
	{ 
		for (j=n-1; j>i; j--) 
		{ 
		
			if (A[j]>A[j-1]) 
			{
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			
			}
		}
	}
	for (i = 0; i < m-1; i++) 
	{ 
		for (j=m-1; j>i; j--) 
		{ 
		
			if (B[j]>B[j-1]) 
			{
				t=B[j];
				B[j]=B[j-1];
				B[j-1]=t;
			
			}
		}
	}
	printf("VVedite chislo=");
		scanf("%d",&k);
	Poiskperebor(A,B,100,1000,k);
	Bipoisk(A,B,100,1000,k);
}

    
	main(){
		int i,j,k;
		
		int  a = 0, b = 30;
		srand(time(NULL));
		for ( i = 0; i < 100; i ++ ) {
			A[i] = random(b-a+1)+a;
		}
		printf("\n");
		for ( i = 0; i < 1000; i ++ ){
			B[i] = random(b-a+1)+a;
			}
		Sort(A,B,100,1000);
		
		
		
	printf("\n");
	system("PAUSE");
	return 0;}
	
