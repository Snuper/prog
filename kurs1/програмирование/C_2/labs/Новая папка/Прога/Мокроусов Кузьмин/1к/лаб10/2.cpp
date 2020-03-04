#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main()
{
	int i,j=0,l,c=0,f=1,b=0,b1=1,z=0,p1=1,p=0;
	char s[100],s1[10][100],t[100]="anime";
	gets(s);
	for(i=0;i<100;i++){
		if(s[i]!=' '){
		s1[c][j]=s[i];
		s1[c][j+1]='\0';
		j++;
	}
		else{			
			j=0;
			c+=1;
			f+=1;
		}
	}
	for(i=0;i<f;i++){
		
		if(i>0) {for(j=i-1;j>=0;j--){
					for(l=0;l<=strlen(s1[i]);l++){
						if(s1[i][l]==s1[j][l])	p1*=1;
						else p1=0;}
					if(p1==1) p=1;
					p1=1;}
		}
		
		for(j=i;j<f;j++){
			for(l=0;l<=strlen(s1[i]);l++){
				if(s1[i][l]==s1[j][l] and p==0)	b1*=1;
				else b1=0;}
			if(b1==1) b+=1;
			b1=1;}

		if(p==0) printf(" %s, %i  ",s1[i],b);
		b1=1;
		p=0;
		p1=1;
		b=0;
		z=1;
	}
	

  system("PAUSE");
  return 0;
}

