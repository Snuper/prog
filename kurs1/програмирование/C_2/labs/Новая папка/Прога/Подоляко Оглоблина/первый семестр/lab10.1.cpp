#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
char str[100], gwords[100][100], temp[5] ;
int i, i2,i3, j, k, s,m, flag;
printf(" Vvedite slova ");
gets(str);
printf(" VVedite pristavky \n");
gets(temp);
m=strlen(temp);
s=strlen(str);
i=0;j=0;k=0;
for (i=0; i <= s; i++) {
 if (str[i] == ' ' || str[i] == ',') {
  gwords[j][k]='\0';
  j++;
  k=0;}
 else {
  gwords[j][k]=str[i];
  k++;}
}
for (i=0;i<=j; i++) {
 if (strncmp(gwords[i],temp,m)==0) {
  puts(gwords[i]);}}
system("pause");
}
