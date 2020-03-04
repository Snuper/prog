#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 200, K = 40;
int main ()
{ 
	char T[N], SL[K][K]={0}, sravn[K][K]={}; 
	int i = 0, j = 0, k = 0, dlina_t = 0, kol = 0, c[K]={}; 
		
	printf("Text: "); 
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
	puts("Slova: "); 
	for (i = 0; i < K; i++)  
	{
		for (j = 0; j < K; j++)	//для перебора всех элементов
		{
			if (strcmp(SL[i],SL[j]) == 0) //если слова одинаковы
			{
				c[i]++; 
			}
		}
	}
		
	for (i = 0; i < K; i++) 
	{
		kol = 0; 
		for (j = 0; j < i; j++) 
		{
			if (strcmp(SL[i],SL[j]) == 0) 
			{
				kol++; 
			}
		}
		if(kol == 0 and (strcmp(SL[i],sravn[i]) != 0)) 
		{
			printf("%s : %d\n",SL[i], c[i]);	
		}
	}
	printf("\n");
	system("PAUSE");
	return 0; 
}

