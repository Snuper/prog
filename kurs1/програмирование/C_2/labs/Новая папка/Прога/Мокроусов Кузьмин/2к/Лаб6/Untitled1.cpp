#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void BG(int m, int n, int k, float &p, float &q, float c);
float fac(float n);

main()
{
	float p=0.45, q=1-p, c, buf1, buf2, buf3; 
	int m,n,k;
	printf("Vvedite kol-vo detei i devochek: ");
	scanf("%d%d",&n,&m);
	k=n-m;
	buf1=fac(n);
	buf2=fac(m);
	buf3=fac(k);
	c= fac(n)/(fac(m)*fac(k));
	BG(n,m,k,p,q,c);
	getche();
	return 0;	
}

float fac(float n){
	int i, fact=1;
	for (i=2;i<=n;i++) fact*=i;
	return fact;
}

void BG(int m, int n, int k, float &p, float &q, float c)
{
	float pd=0, pm=0,j,j1, f, f1;
	pd=c*pow(p,m)*pow(q,k);
	printf("%f \n", pd );
	pm=c*pow(q,m)*pow(p,k);
	printf("%f \n", pm);
}
