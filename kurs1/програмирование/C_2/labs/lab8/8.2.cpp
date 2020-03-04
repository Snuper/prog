#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

main(){
    int i=0,n,j=0,k,l=0,h=0;                                   
	struct lif {int number; int area; char fakult[10]; int residents;} room;
	struct bep {char fakult[10]; int students; int area;} ry;
	lif *info;
	bep *facs;
	puts("Input number of rooms: ");
	scanf("%d",&n);
	info = new lif [n];
	if (info == NULL){
		puts("Fatal Erorr! Memory unsigned!");
		delete info;
		return 1;
	}
	facs = new bep [n];
	if (facs == NULL){
		puts("Fatal Erorr! Memory unsigned!");
		delete facs;
		return 1;
	}
	for (i=0;i<n;i++){
		puts("About room: ");
		scanf("%d%d%s%d",&room.number,&room.area,&room.fakult,&room.residents);
		h+=room.residents;
		info[i]=room;
	}
	for (i=0;i<n;i++){
		facs[i]=ry;
	}
	for(i=0,l=0;i<n;i++){
		for (j=0;j<n;j++){
			k=strcmp(info[i].fakult,facs[j].fakult);
			if(k==0) break;
			//printf("\nlll\n");
		}
		if (k!=0){
			strcpy(facs[l].fakult,info[i].fakult);
			l++;
		}
	}
	for(i=0;i<l;i++){
		facs[i].area=0;
		facs[i].students=0;
	}
	for(i=0;i<l;i++){
		for (j=0;j<n;j++){
			k=strcmp(info[j].fakult,facs[i].fakult);
			if(k==0) {
				facs[i].area+=info[j].area;
				facs[i].students+=info[i].residents;
			}
		}
		}
	printf("\nThere are %d student and %d facs:\n",h,l);
	for(i=0;i<l;i++){
		printf("%d students at %s        %.2f\n",facs[i].students,facs[i].fakult,(float)facs[i].area/facs[i].students);
    }
	delete info;
	delete facs;
	info=NULL;
	info=NULL;
}
