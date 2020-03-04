#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int i,j;
void Recu(int *p,int n){
        if (i<n){
		if (p[i]<0){ printf("%d ",p[i]); i++;
		Recu(p,n);
		}else{i++; Recu(p,n);
		}}
		
		if (j<n){
		
		if (p[j]>0){ printf("%d ",p[j]); j++;
		Recu(p,n);
		}else{j++;
		Recu(p,n);
		} }
	}


int main(){
	int N;
		scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++)
	scanf("%d",&A[i]);
	i=0; j=0;
	Recu(A,N);
	system ("PAUSE");
	return 0;
}


