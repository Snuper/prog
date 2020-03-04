#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 200, K = 40;
int main ()
{ 
	char T[N], SL[K][K]={},c[K][K]; 
	int i = 0, j = 0, k = 0, dlina_t = 0; 
	printf("Surname : "); 
	gets(T);
	dlina_t = strlen(T); 
	printf("\n");
	printf("Alphavit: \n"); 

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
	for(i = 0; i < k; i++) 
	{
		for (j = k - 1; j >= i; j--) //сверху вниз
		{
			if (strncmp(SL[j],SL[j+1],K) > 0) //сравниваем
			{
				strcpy(c[i],SL[j]); 
				strcpy(SL[j],SL[j+1]); //меняем местами
				strcpy(SL[j+1],c[i]); 
			}
		}
	}
	for (i = 0; i < k+1; i++) 
	{
		printf("%d. %s\n", i , SL[i]); 
	}
	printf("\n");
	system("PAUSE");
	return 0; 
}

