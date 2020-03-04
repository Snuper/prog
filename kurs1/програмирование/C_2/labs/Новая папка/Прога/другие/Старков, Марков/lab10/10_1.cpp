#include <stdio.h> 
#include <string.h> 
#include <iostream>
int main() 
{ int k=0, i=0,s=0,l=0,ll=0,b=-1,num=0;
char inf1[]="vvedite slova cherez ',' v konce postavte '.'" ,inf2[]="vvedite pristavku";
char s1[249] , s2[250], pr[100] ;
puts(inf1);
gets(s1);
puts(inf2);
gets(pr);
ll=strlen(pr);
ll--;

while(s1[i]!='\0'){
if((s1[i]==',')||(s1[i]=='.')){
strncpy ( s2-k, s1, i ); 
k+=strlen(s2);
k++;
for(s=0;s<=ll;s++)
{ if (s2[s]==pr[s])
num++;

}
num--;
if(num==ll)
puts (s2);
num=0;
}
for(s=0;s<200;s++)	
s2[s]='\0';	
	
	i++;
	
	

}
system("PAUSE"); 




















}
