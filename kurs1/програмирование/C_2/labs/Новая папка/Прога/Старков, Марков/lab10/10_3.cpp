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
 	char *p=strtok(str," ,");
 	   int i,j,z;
 	char o[10][15],temp[15];
 	i=j=0;
    while (p != NULL){
    strcpy(o[i],p);
    i++;
    p= strtok (NULL, ",");
    }
	const int k=i;
	for(i=0;i<k-1;i++){
    	for(j=k-2;j>=i;j--){
    if(strcmp(o[j],o[j+1])>0){
    		
    strcpy(temp,o[j]);
    strcpy(o[j],o[j+1]);
    strcpy(o[j+1],temp);
	}
    }	
	}
    
	for (i=0;i<k;i++){
        printf("%s \n",o[i]);
    }
    system("pause");
    return 0;
}
