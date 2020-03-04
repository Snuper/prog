#include <stdio.h> 
#include <string.h> 
#include <iostream>
main() 
{ int k=0, i=0,s=0,l=0,ll=0,b=-1,num=0;
char inf1[]="vvedite slova cherez ',' v konce postavte '.'" ,inf2[]="vvedite pristavku";;
char s1[100] , s2[25], pr[10],xr[10]; 
puts (inf1);
gets(s1);
puts (inf2);

gets(xr);

ll=strlen(xr);
 while(s1[i]!='\0'){
 	strncpy ( pr, xr, ll );
 	pr[ll] = '\0';
if((s1[i]==',')||(s1[i]=='.')){
strncpy ( s2-k, s1, i );
s2[i] = '\0'; 
 k+=strlen(s2);
 l=strlen(s2);
k++;

 ;
 while(s<l){
 	if(s>=(l-ll))
 	b++;
 	
 	if(s2[s]==pr[b]){
 		num++;
 		
	 }
 	
 	s++;
 	
 	}
 	
 	
 	if(num==ll) puts (s2);
 s=0;
 b=-1;
 num=0;
 
 
 
 
 
 
 
 while(s<20){
 	s2[s]='\0';
 	s++;
 }
 s=0;
 
 

}
i++;
 }
 



  
}

