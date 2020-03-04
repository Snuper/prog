#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h> 
int fact(int a){
	int i;
	long int b;
	b=1;
	for (i=1;i<=a;i++)
	b*=i;
	return b;
}
void Func(int n, int m, float &z, char l){
	int c=0;
	float p=0.45,q=0.55;
	c=fact(n)/(fact(m)*fact(n-m));
	if (l=='g'){
		z=c*pow(p,m)*pow(q,n-m);
	}else{
		z=c*pow(q,m)*pow(p,n-m);
	}
}
int main(){
	int n=0,m=0;
	float s=0;
	char f=0;
	printf("b- boys, g- girls:");
	scanf("%c",&f);
	printf("\nNumber of children:");
	scanf("%d",&n);
	printf("How many %c:",f);
	scanf("%d",&m);
	Func(n,m,s,f);
	if (f=='b'){
		printf("The probability of having %d boys among %d children is %f",m,n,s);
	} else{
		printf("The probability of having %d girls among %d children is %f",m,n,s);
	}
	return 0;
}
