#include <stdlib.h> 
#include <math.h> 
#include <conio.h>
#include <stdio.h>
float cosenus(float z);

int main(){
	float x,y;
	printf("vvedite x\n");
	scanf("%f",&x);
	y=cosenus(x);
	printf("cosinus = %f\n",y);
	y=cos(x);
	printf("cos = %f\n",y);
	system ("PAUSE");
}

float cosenus(float z){
float const PI=6.28318531;
 int st=0,i,flag=0;
	long double fac;
	float eps=1,result=0,l;
	//l=(PI/360)*z; 
	l=z;
	if (l<0) l*=(-1); 
	while(l>PI)
	l-=PI;
	while(eps>0.0001)
	{st+=2;
	fac=1;
	for(i=1;i<=st;i++)
	fac*=i;
	eps=pow(l,st)/fac;
	if(flag==0) {result-=eps; flag=1;}
	else {result+=eps; flag=0;}
	}
	result+=1;
	return result;
}
