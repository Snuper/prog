#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

main(){
	int n,i,j;
	struct stud{int num; int grad; int un;} info;
	struct stud *a;
	struct stud p;
	printf("Number of schools: ");
	scanf("%d",&n);
	puts("\n");
	a= new struct stud [n];
	if(a==NULL){
		printf("Fatal Error! Memory not found!");
		delete a;
		a=NULL;
		return 1;
	}
	float hh;
	for (i=0;i<n;i++){
		printf("About school:");
		scanf("%d%d%d",&info.num,&info.grad,&info.un);
		if (info.grad<info.un){
			printf("Uncorrect information");
			return 1;
		}
		a[i]=info;
		puts("\n");
	}
	puts("\n");
	for (i=0;i<n;i++){
		for (j=n-1;j>i;j--){
			if ((float(a[j].un)/a[j].grad)<(float(a[j-1].un)/a[j-1].grad)){
				p=a[j];
				a[j]=a[j-1];
				a[j-1]=p;
			}
		}
	}
	for (i=0;i<n;i++){
		printf("Number of school: %d    Info: %d   %2.2f%%",a[i].num,a[i].grad,(float(a[i].un)/a[i].grad)*100);
		puts("\n");
	}
	
	delete a;
	a=NULL;
	
}
