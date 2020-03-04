#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
char str[100], gwords[100][100];
int i, i2,i3, j, k, s, a,flag;
printf(" Vvedite slova ");
gets(str);
s=strlen(str);
i=0;j=0;k=0;
for (i=0; i <= s; i++) {
 if (str[i] == ' ' || str[i] == ',')
  {gwords[j][k]='\0';
  j++;
  k=0;}
 else
  {gwords[j][k]=str[i];
  k++;}
} 
printf(" Povtoryaushiesya slova \n");
for (i=0;i<=j-1; i++) { 
flag=1;
 for (i2=i+1;i2<=j;i2++) {
  if (strcmp(gwords[i],gwords[i2])==0) { 
  flag++; for (i3=0;i3<=k;i3++) gwords[i2][i3]=' ' ;}}
 if (gwords[i][0]!=' ') {
 puts(gwords[i]); printf(" k=%d \n",flag);}
}
system("pause");
}
