#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
int mp=0, cp=0;
int random (int N) { return rand()%N; }
void Swap (int &x, int &y);
void TelSprav();
void SelectSort_Struct (int A[], int n, int z);
void BSearch1 (int A[], int n, int X);
void BSearch2 (int A[], int n, int X);
int Less (struct sprav x, struct sprav y, int z);

struct sprav {
	char fam[15];
	char name[11];
	char city[15];
	char phone[16];
};
struct sprav abonent[5];


main() {
	
  	
	TelSprav();
	system("PAUSE");
	return 0;
}

void zap () {
	strcpy (abonent[0].fam, "Prichodchenko");
	strcpy (abonent[1].fam, "Zateev");
	strcpy (abonent[2].fam, "Filimonov");
	strcpy (abonent[3].fam, "Basalaev");
	strcpy (abonent[4].fam, "Kovalik");
	strcpy (abonent[0].name, "Ivan");
	strcpy (abonent[1].name, "Sergey");
	strcpy (abonent[2].name, "Vladislav");
	strcpy (abonent[3].name, "Semyon");
	strcpy (abonent[4].name, "Ruslan");
	strcpy (abonent[0].city, "Moscow");
	strcpy (abonent[1].city, "Berdsk");
	strcpy (abonent[2].city, "Novosibirsk");
	strcpy (abonent[3].city, "Ataray");
	strcpy (abonent[4].city, "Kazakhstan");
	strcpy (abonent[0].phone, "8(913)726-45-06");
	strcpy (abonent[1].phone, "8(925)786-53-39");
	strcpy (abonent[2].phone, "8(954)389-78-65");
	strcpy (abonent[3].phone, "8(999)897-96-89");
	strcpy (abonent[4].phone, "8(986)247-52-32");
}

void TelSprav() {
	zap ();
	int i, n=5;
	int a[n], b[n];
	for (i=0; i<n; i++) a[i]=b[i]=i;
	SelectSort_Struct (a, n, 0);
	SelectSort_Struct (b, n, 1);
	for (i=0; i<n; i++) {
		printf ("%s ", abonent[i].fam);
		printf ("%s ", abonent[i].name);
		printf ("%s ", abonent[i].city);
		printf ("%s ", abonent[i].phone);
		printf("\n");
	}
	printf("\n \n\n");
	for (i=0; i<n; i++) {
		printf ("%s ", abonent[a[i]].fam);
		printf ("%s ", abonent[a[i]].name);
		printf ("%s ", abonent[a[i]].city);
		printf ("%s ", abonent[a[i]].phone);
		printf("\n");
	}
	printf("\n \n\n");
	for (i=0; i<n; i++) {
		printf ("%s ", abonent[b[i]].city);
		printf ("%s ", abonent[b[i]].fam);
		printf ("%s ", abonent[b[i]].name);
		printf ("%s ", abonent[b[i]].phone);
		printf("\n");
	}
	printf("\n");
	//BSearch1 (a,n,8);
	//BSearch2 (b,n,6);
	
}
void Swap (int &x, int &y) {
	int t=x; x=y; y=t;
}
void SelectSort_Struct (int A[], int n, int z) {
	int i, j ,k, t;
	for (i=0; i<(n-1); i++) {
		k=i;
		for (j=i+1; j<n; j++) {
			if (Less (abonent [A[j]], abonent [A[k]], z)) k=j;
		}
		if (k!=i) {
			Swap (A[i], A[k]);
		}
	}
}

int Less (struct sprav x, struct sprav y, int z) {
	int i;
	switch (z) {
		case 0: i=strcmp (x.fam, y.fam);
			if (i<0) return 1;
			else return 0;
			break;
		case 1: i=strcmp (x.city, y.city);
			if (i<0) return 1;
			else return 0;
			break;
	}
}


void BSearch1 (int A[], int n, int X)
{
	int Cprak=0;
	int L=1, R=n, Find=0, m;
	while (L<=R)
	{
		m=(int)((L+R)/2);
		Cprak++;
		if (A[m]==X) 
		{
		Find=1;
		break;
		} 
		Cprak++;
		if (A[m]<X) L=m+1;
		else R=m-1;
	}
	printf ("Number a[]=%d", Cprak);
	puts(" ");
}
void BSearch2 (int A[], int n, int X)
{
	int Cprak=0;
	int L=1, R=n, Find=0, m;
	while (L<R)
	{
		m=(int)((L+R)/2);
		Cprak++;
		if (A[m] < X) L=m+1;
		else R=m;
	}
	Cprak++;
	if (A[R]=X) Find = 1;
	else Find = 0;
	printf ("Number b[]=%d", Cprak);
	puts(" ");
}
