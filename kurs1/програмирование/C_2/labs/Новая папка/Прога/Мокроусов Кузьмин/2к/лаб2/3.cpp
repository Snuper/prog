#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int penisland(int);

main(){
	int p;
	scanf("%d",&p);
	penisland(p*2);
	getche();
}

int penisland(int k){
	k=k/2;
	if(k>1)	{
		penisland(k);
		printf("%d",k%2);
	}
	if(k<2)	printf("%d",k);
}

