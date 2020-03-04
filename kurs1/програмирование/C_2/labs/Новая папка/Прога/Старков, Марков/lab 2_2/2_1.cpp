#include<stdlib.h>
#include <conio.h>
#include <stdio.h>
	int m;
void cho(int m){
scanf("%d",&m);
if (m==0) return;
cho(m);
if (m>0) printf(" %d",m);
}
int main(){
cho(-1);
printf("\n");
	system("PAUSE");
}
