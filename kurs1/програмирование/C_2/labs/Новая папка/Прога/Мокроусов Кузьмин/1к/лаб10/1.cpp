#include<stdlib.h>
#include <stdio.h>
#include <string.h>

const int n = 100;
int main()
{
char s[n],a[10][15],b[10];
int i=0,j=0,l;
gets(s);	
char *p=strtok(s," ,.");
gets(b); l=strlen(b);
while (p != NULL){
    strcpy(a[i],p);
    i++;
    p= strtok (NULL, " ,.");
    }
j=i;    
for(i=0;i<j;i++){
    	if(strncmp(a[i],b,l)==0){
        	puts(a[i]);
		}
}
system("pause");
return 0;
}
