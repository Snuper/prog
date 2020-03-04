#include<stdlib.h> 
#include <stdio.h> 
int main() {
int n,nf,i,ii,fi,c,cf,res;
nf=1;
fi=1;
cf=1;
printf ("print n \n");scanf("%d",&n);
int A[n],C[n];
for(i=0;i<n;i++)
A[n]+=(i+1);
for(i=0;i<n;i++)
nf+=(nf*i);
for(i=0;i<n;i++){
fi+=(fi*i);
c=n-(i+1); 
 for(ii=0;ii<c;ii++){
	cf+=(cf*ii);
}
res=nf/(fi*cf);
C[i]=res;
cf=1;
}
for(i=0;i<n;i++)
printf("%d,",C[i]);

system("PAUSE");  
return 0; 
}
