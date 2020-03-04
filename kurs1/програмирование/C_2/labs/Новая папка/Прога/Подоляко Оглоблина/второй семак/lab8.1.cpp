#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
int i,j,m,n,t; 
printf("\n Vvedite kolichestvo shkol=");
scanf("%d",&n);
struct shc {int nomer; int kol; int chis;float proc;} sh; 
struct shc mag[n]; 
float pro[n];
int ind[n];
for (i=0;i<n;i++)
{ 	printf("\n shcola: ");
	scanf("%d",&sh.nomer);
	mag[i].nomer=sh.nomer;
	printf(" chislo vipusknikov: ");
	scanf("%d",&sh.kol);
	mag[i].kol=sh.kol;
	printf(" postupili: ");
	scanf("%d",&sh.chis);
	mag[i].chis=sh.chis;
	printf("%d %d %d ",mag[i].nomer,mag[i].kol,mag[i].chis);
	pro[i]=float(sh.chis)/float(sh.kol)*100;
	ind[i]=i;
	printf("%4.2f",pro[i]);}
for (i = 0; i < n-1; i++) 
	{ 
		for (j=n-1; j>i; j--) 
		{  
			if (pro[ind[j]]>pro[ind[j-1]]) 
			{
				t=ind[j];
				ind[j]=ind[j-1];
				ind[j-1]=t;
			
			}
		}
	}
for(i=0;i<n;i++){
	printf("\n%d,%4d,%4d,%4.2f",mag[ind[i]].nomer,mag[ind[i]].kol,mag[ind[i]].chis,pro[ind[i]]);
}
getch();
}
