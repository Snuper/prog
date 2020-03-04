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
	strcpy (abonent[0].fam, "Sokolov");
	strcpy (abonent[1].fam, "Sykharev");
	strcpy (abonent[2].fam, "Yakynin");
	strcpy (abonent[3].fam, "Seleverstov");
	strcpy (abonent[4].fam, "Parfencov");
	strcpy (abonent[0].name, "Kirill");
	strcpy (abonent[1].name, "Nikita");
	strcpy (abonent[2].name, "Andrey");
	strcpy (abonent[3].name, "Vasily");
	strcpy (abonent[4].name, "Semion");
	strcpy (abonent[0].city, "Angarsk");
	strcpy (abonent[1].city, "Novosibirsk");
	strcpy (abonent[2].city, "Novosibirsk");
	strcpy (abonent[3].city, "Novosibirsk");
	strcpy (abonent[4].city, "Angarsk");
	strcpy (abonent[0].phone, "8(913)726-14-22");
	strcpy (abonent[1].phone, "8(925)786-53-39");
	strcpy (abonent[2].phone, "8(924)389-68-65");
	strcpy (abonent[3].phone, "8(929)847-96-99");
	strcpy (abonent[4].phone, "8(916)237-52-32");
}

void TelSprav() {
	zap ();
	int i, n=5;
	int a[n], b[n],c[n];
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
			if (i<0)
			return 1;
				else if (i>0) return 0;
				i=strcmp (x.fam, y.fam);
			if (i<0) return 1;
			else return 0;
			break;
	}
}

