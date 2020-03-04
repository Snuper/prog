#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int ch();

main(){
	ch();
	return 0;
}

int ch(){
	int a;
	scanf("%d",&a);
	if (a!=0){
		ch();
	}
	if (a>0){
		printf("%d ",a);
	}
}

