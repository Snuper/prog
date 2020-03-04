#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int ch();

main(){
	ch();
	getche();
}

int ch(){
	int a;
	scanf("%d",&a);
	
	if (a>0){
		printf("%d ",a);
	}
	if (a!=0){
		ch();}
	return 0;
}

