#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
char str[100], gwords[100][100], temp[100];
int i, i2,i3, j, k, s,m,flag;
printf(" Vvedite spisok familii ");
gets(str);
s=strlen(str);
i=0;j=0;k=0;
for (i=0; i<=s; i++) {
 if (str[i] == ' ' || str[i] == ',') {
  gwords[j][k]='\0';
  j++;
  k=0;
 }
 else {
  gwords[j][k]=str[i];
  k++;
 }
}
for (i=0;i<j;i++) {
 for (k=0;k<j;k++) {
  if(strcmp(gwords[k],gwords[k+1])>0) { 
   strcpy(temp,gwords[k]);
   strcpy(gwords[k],gwords[k+1]);
   strcpy(gwords[k+1],temp);
  }
 }
}
for(i=0;i<=j;i++)
printf("%s\n",gwords[i]);
system("pause");
}
