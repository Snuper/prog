#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int const N = 200,R = 20;
int main ( )
{ 
	char T[N], PR[R], SL[20][20]={0}; 
	int i = 0, j = 0, k = 0, dlina = 0,dlina_t = 0,pri = 0; 
	
	printf("Pristavka : "); 
	gets(PR); 
	dlina = strlen(PR); 
	printf("\n");	
	printf("Slova : ");
	gets(T); 
	dlina_t = strlen(T);
	
	
	for(i = 0; i < dlina_t;i++) 
	{
		if (T[i] != ' ' and T[i] != ',') 
		{
			SL[k][j] = T[i]; 
			j++; 
		}
		else 
		{
			k++; 
			j = 0; 
		}
	}
	printf("\n");
	puts("Spisok slov : "); 

	for (i = 0; i < 20; i++) 
	{
		pri = strncmp(SL[i],PR,dlina); 
		if(pri == 0) 
		{
			puts(SL[i]); 
		}
	}
	printf("\n");
	system("PAUSE");
	return 0; 
}

