#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
   float x = 5,N = 1,a,s,n;
   printf("Vvedite polozitelnoe chislo ");
   scanf("%f",&n);
    if (n>0){
	for (s=1, a=1; N<=n; N++)
			{
			a *= N;	
			s+=pow(x,N)/a;
	}
     printf ("N=%f s=%f",N,s);
    }
    else
    {
    	printf("Vi veli otricatelnoe chislo");
	}
	system("PAUSE");
    return 0;
}
