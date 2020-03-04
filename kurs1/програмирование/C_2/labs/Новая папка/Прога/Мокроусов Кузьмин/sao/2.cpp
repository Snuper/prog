#include <stdio.h>
#include <conio.h>
int maxim();
			
 main()
{
  maxim(); 
  getch();
}
int maxim(){
	int n=5,a[5],x,i,j,k,t,m1=0,c1=0,mt,ct;
  	for (i=0;i<n;i++)
  {  printf("p[%d]=",i);
     scanf("%d",&a[i]);
  }
	for(i=0;i<n;i++) {
		for(j=i;j<n;j++){
			c1++;
			if(a[i]>a[j]) k=j;
		}
		t=a[k];
		a[k]=a[i];
		a[i]=t;
		m1+=3;
		k=i+1;
	}
	mt=3*(n-1);
	ct=(n*n-n)/2;

	for (i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
	printf("M = %d - %d \n",mt,m1);
	printf("C = %d - %d \n",ct,c1);
}

