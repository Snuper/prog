#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int const N=6;
void sortir(int, int, int );

 main(){
	int m [N],j=0,a=0;
	for(int i=0;i<N;i++)	scanf("%d",&m[i]);
	sortir(m,j,a);
	getche();
}

void sortir(int m[N],int j,int a){
	if(j<N){
	if(a==0){
    if(m[j]<0){
	printf("%d ",m[j]);
	j++;
	sortir(m,j,a);}
	else {
    j++;
	sortir(m,j,a);}
	if(j==N-1&&a==0){
	a=1;
	j=0;}
    }
	if(a==1){
	if(m[j]>=0){
	printf("%d ",m[j]);
	j++;
	sortir(m,j,a);}
	else {
	j++;
	sortir(m,j,a);}}}
}

