#include <stdio.h>
#include <conio.h>
#include <string.h>
	main(){
		int i=0,j=0,m,n=0,kf=0,kk=0,ks=0; 
		struct kom {int nomer; int plo; char fac[10];int kol;} k; 
		struct kom mag[10]; 
		do{printf("\n komnata ,ploschad,facultet,kolichestvo: ");
		scanf("%d%d%s%d",&k.nomer,&k.plo,&k.fac,&k.kol);
		mag[i]=k;
		i++;n++;
		}
		while(k.nomer!=0);
	    struct kom Fac[n-1];
	    int g=0,flag;
		for (i=0;i<n-1;i++){ flag=1;
			for(j=i+1;j<n-2;j++)
			{   
				if (strcmp(mag[i].fac,mag[j].fac)==0) flag=0;
				
				} if(flag)
					{ strcpy(Fac[g].fac,mag[i].fac);
				 Fac[g].plo=mag[i].plo/mag[i].kol;kf++;g++;
				}}
	    printf("kf=%d  ",kf);
		
	
		for (i=0;i<n-1;i++){ flag=1;
			for(j=i+1;j<n-2;j++)
			{ if (mag[j].nomer==mag[i].nomer) flag=0;
			 }
			 if(flag)
			{	kk++;ks=ks+mag[i].kol;
				
				}	
				
		}
		float Plo[kf];
		for(i=0;i<kf;++i)
			{ int stu=0;
			for(j=0;j<n-1;j++)
				if(strcmp(Fac[i].fac,mag[j].fac)){
					Plo[i]+=mag[j].plo;
					stu+=mag[j].kol;
				}
			Plo[i]=Plo[i]/stu;
			}
	
		printf("\n Kolichestvo komnat=%d",kk);
		printf("\n Kolichestvo studentov=%d",ks);
		printf("\n Ploschad na odnogo studenta");
		for (i=0;i<kf;i++) printf("\n%s=%.2f",Fac[i].fac,Plo[i]);
		getch();
	}
