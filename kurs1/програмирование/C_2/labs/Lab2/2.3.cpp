#include <stdlib.h>
#include <math.h>
#include <iostream>

int i=0;
void Rec(int a){
 if (a>1)
 	Rec(a/2);
  printf("%d",a%2);	
	}
int main(){
	int n;
	scanf("%d",&n);
	Rec(n);
	system("PAUSE");
	return 0;
}
