#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

main(){
	int i,j,m,k,v;
	float vi;
	struct sch{int nom; float vip; float vuz;} school;
	printf("Vvedite kolichestvo shkol: ");
	scanf("%d", &m);
	float proc[m],vipusk[m],vvuze[m];
	int ind[m],nomer[m];
	struct sch mass[m];
	printf("Vvedite indormaciu o shkolah(nomer, vipuskniki, postupivshie): ");
	for(i=0;i<m;i++){
		scanf("%d %f %f", &school.nom, &school.vip, &school.vuz);
		mass[i]=school;
		nomer[i]=school.nom;
		vipusk[i]=school.vip;
		vvuze[i]=school.vuz;
		proc[i]=(vvuze[i]/vipusk[i])*100;
		ind[i]=i;
	}
	for(i=0;i<m-1;i++){	
		k=i;	
		for(j=1;j<m;j++)
			if(proc[j]>proc[k]) k=j;
		v=ind[i];
		ind[i]=ind[k];
		ind[k]=v;
	}
	for(i=0;i<m;i++){
		printf("\n Nomer shkoly: %d; Vipusknikov: %2.0f; Procent postupivshih: %5.2f" , nomer[ind[i]], vipusk[ind[i]], proc[ind[i]]);
	}
	  getch();
}
