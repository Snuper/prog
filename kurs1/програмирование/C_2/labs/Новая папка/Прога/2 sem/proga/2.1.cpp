#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int i;
char s[60]=" ",s1[3],probel[]=" ";
long rec(int n)
{ 
scanf("%d", &i);
n=i;
if (n==0) return 0;
else
{
if (n>0)
{
itoa (n, s1, 10);
strcat(s,s1);
strcat(s,probel);
return rec(n);
}
if (n<0)
return rec(n);
}
}
main()
{
rec(10);
printf("%s",s);
}
