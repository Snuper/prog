#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
int random (int N) { return rand() % N; }
const int n=3;

main(){
	
  struct tel {long int n; char a[10]; char m[20]; int r;} t; 
  struct tel sp[n];  
  int i,j,g,A[i],B[i];

  for (i=0;i<n;i++)
  {   printf("\n  Number, Name :  ");
     scanf("%d%s%s%d",&t.n, &t.a, &t.m, &t.r);
      sp[i]=t; 
      A[i]=i;
      B[i]=i;
}

for(i=1;i<n;i++){
		g=A[i];
		j=i-1;
		while(j>=0 and sp[g].n<sp[A[j]].n){
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=g;
	}

for(i=1;i<n;i++){
		g=B[i];
		j=i-1;
		while(j>=0 and strcmp(sp[g].a,sp[B[j]].a)<0){
			B[j+1]=B[j];
			j=j-1;
		}
		B[j+1]=g;
	}

for (i=0;i<n;i++)
  {   
       printf("\n === %ld %s %s %d",sp[A[i]].n,sp[A[i]].a,sp[A[i]].m,sp[A[i]].r);
  }

printf("\n=================\n");

for (i=0;i<n;i++)
  {   
       printf("\n === %ld %s %s %d",sp[B[i]].n,sp[B[i]].a,sp[B[i]].m,sp[B[i]].r);
  }

getche();
}



