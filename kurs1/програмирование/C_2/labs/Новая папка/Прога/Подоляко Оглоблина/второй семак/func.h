#include<ctime>
namespace sort
{
	void SelectSort (int A[], int n) 
{
	int i,j,k,t;
	for (i = 0; i < n-1; i++ ) { 
		k = i;
		for( j=i+1; j<n; j++){ 
	   		if (A[j]<A[k])k=j;
		}
		t=A[i];
		A[i]=A[k];
		A[k]=t; 
	
	}}
	void SelectSort (double A[], int n) 
{
	int i,j,k;
	double t;
	for (i = 0; i < n-1; i++ ) { 
		k = i;
		for( j=i+1; j<n; j++){ 
	   		if (A[j]<A[k])k=j;
		}
		t=A[i];
		A[i]=A[k];
		A[k]=t; 
	
	}}
	void BubbleSort (int A[], int n) {
	int i,j,t;
	for (i = 0; i < n-1; i++) {
		for (j=n-1; j>i; j--) {
			if (A[j]<A[j-1]) {
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			}
		}
	}
}
	void BubbleSort (double A[], int n) {
	int i,j;
	double t;
	for (i = 0; i < n-1; i++) {
		for (j=n-1; j>i; j--) {
			if (A[j]<A[j-1]) {
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
			}
		}
	}
}
	void ShakerSort (int A[], int n) {
	int left,right,i,j,k,w;
	left=0;
	right=n-1;
	k=n-1;
	do {
		for(j=right; j>left; j-- ){ 
			if (A[j]<A[j-1]) { 
				w=A[j];
		  	 	A[j]=A[j-1];
			  	A[j-1]=w;
		  	 	k=j;
			}
		}
		left=k;
		for(j=left; j<right; j++ ){ 
	   		if(A[j]>A[j+1]){ 
	   			w=A[j];
	  	 		A[j]=A[j+1];
	   			A[j+1]=w;
	   			k=j;
			}
		}
		right=k;
	}
	while( left<right );
}
	void ShakerSort (double A[], int n) {
	int left,right,i,j,k;
	double w;
	left=0;
	right=n-1;
	k=n-1;
	do {
		for(j=right; j>left; j-- ){ 
			if (A[j]<A[j-1]) { 
				w=A[j];
		  	 	A[j]=A[j-1];
			  	A[j-1]=w;
		  	 	k=j;
			}
		}
		left=k;
		for(j=left; j<right; j++ ){ 
	   		if(A[j]>A[j+1]){ 
	   			w=A[j];
	  	 		A[j]=A[j+1];
	   			A[j+1]=w;
	   			k=j;
			}
		}
		right=k;
	}
	while( left<right );
}
	void InsertSort (int A[], int n) {
	int i,t,j;
	for(i=1; i<n; i++) {
		t=A[i];
		j=i-1;
		while(j>=0 && ( t<A[j]) ){ 
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=t;
	}
}
 	void InsertSort (double A[], int n) {
	int i,j;
	double t;
	for(i=1; i<n; i++) {
		t=A[i];
		j=i-1;
		while(j>=0 && ( t<A[j]) ){ 
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=t;
	}
}

	unsigned timer(void(*f)(int*,int),int A[],int n)
	{
		unsigned time=clock();
		f(A,n);
		return clock()-time;
	}
	unsigned timer(void(*f)(double*,int),double A[],int n)
	{
		unsigned time=clock();
		f(A,n);
		return clock()-time;
	}
	

}
