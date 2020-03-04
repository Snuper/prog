#include<stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int n = 100;
int main()
{
    char str[n];
    puts("Enter text:");
    gets(str);
char *p=strtok(str," ,.");
int a[10],i,k,j,z;
char o[10][15];
i=k=j=0;
    while (p != NULL){
    strcpy(o[i],p);
    i++;
    p= strtok (NULL, " ,.");
    }
    k=i;
    
	for(i;i>=0;i--)	a[i]=1;
    
	for(i=0;i<k;i++){
    for(j=i+1;j<k;j++){
    if(strcmp(o[i],o[j])==0){
    a[i]++;
    for(z=j;z<k-1;z++){
    strcpy(o[z],o[z+1]);
    }
	k--;
	j--;
	}
	}	
	}
    
	for (i=0;i<k;i++){
        printf("%s : %d\n",o[i],a[i]);
    }
    system("pause");
    return 0;
}
