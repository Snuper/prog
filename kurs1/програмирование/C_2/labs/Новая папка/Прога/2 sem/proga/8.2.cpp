#include<iostream>
#include<string.h>
#define N 3

main(){
	int i,j,kolf=0,x,check=0,sum=0,st=0,s=0;
	struct baza{int n;int s;char fac[15];int k;} zap[N];
	char f[N][15];
	for	(i=0;i<N;i++)	f[i][0]=' ';
	printf("input info:\n");
	for (i=0;i<N;i++){   
		printf("\n  nomer room, plocad, facultet, kol-vo projiv.:  ");
		scanf("%d%d%s%d",&zap[i].n,&zap[i].s,&zap[i].fac,&zap[i].k);
		sum+=zap[i].k;
	}
	for (i=0,x=0;i<N;i++){   
		for (j=0;j<N;j++){
			if(strcmp(f[j],zap[i].fac)){
			}else{	check=1;		
				break;
            }
		}
		if(check==0){
			
			strcpy(f[x],zap[i].fac);
			kolf++;
			x++;
		}
		check=0;
	}
	
	for (i=0;i<kolf;i++){   
		for (j=0;j<N;j++){
			if(strcmp(f[i],zap[j].fac)){
			}else{	s+=zap[j].s;		
				st+=zap[j].k;
			}
		}
		printf("\nsr. plocad na odno studenta faculteta %s: %f Studentov - %d\n",f[i], (float)s/st, st);
		s=0;
		st=0;
	}
		printf("\nstudentov:%d, komnat:%d\n",sum,N);
	for	(i=0;i<kolf;i++)		printf("\n%d. %s\n ",i+1,f[i]);	
	for (i=0;i<N;i++)		printf("\nnomer room %d, plocad %d, facultet %s, kol-vo projiv. %d\n",zap[i].n,zap[i].s, zap[i].fac,zap[i].k);
  	system("Pause");
	return 0;
}
