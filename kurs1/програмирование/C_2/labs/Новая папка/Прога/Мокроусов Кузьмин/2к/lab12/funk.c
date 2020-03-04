

void BubbleSort(int *A, int n){
  int i,j,t;
  for (i=0;i<n;i++){
    for (j=0;j<n-1-i;j++){
      if (A[j]>A[j+1]){
        t=A[j];
		A[j]=A[j+1];
		A[j+1]=t;
      } 
    }
  }
}

void InsertSort(int *A, int n){
	int i,j,t;
	for(i=1;i<n;i++){
		t=A[i];
		j=i-1;
		while(j>=0 and t<A[j]){
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=t;
	}
}

void BubbleSort2(float *A, int n){
  int i,j;
  float t;
  for (i=0;i<n;i++){
    for (j=0;j<n-1-i;j++){
      if (A[j]>A[j+1]){
        t=A[j];
		A[j]=A[j+1];
		A[j+1]=t;
      } 
    }
  }
}

void InsertSort2(float *A, int n){
	int i,j;
	float t;
	for(i=1;i<n;i++){
		t=A[i];
		j=i-1;
		while(j>=0 and t<A[j]){
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=t;
	}
}


