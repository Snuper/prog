
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int random (int N) { return rand() % N; }
const int n=16; 

main()
{ system("CLS");
int i, c[n], a=0, b;
printf("Vvedite nomer: ");

for (i=1; i<=n; i++) {

	scanf("%d", &c[i]);
	if (i%2==0)	a+=c[i];
	if (i%2!=0) { if ((c[i]*2)>9) 
    {(c[i]=c[i]*2-9);
    a+=c[i];}
    else a+=c[i]*2;
	}
	
}
if (a%10==0) printf("Verno");
else printf("Neverno");

system("PAUSE");

return 0;

}
