#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 300, K = 40;
int main ()
{ 
	char TEXT[N], SLOVO[K][K]{0}, sravn[K][K]{}, UNIK[K][K]{0}; //массивы для текста
	int i = 0, j = 0, k = 0, dlina_text = 0, kol = 0, ch[K]{}; //переменные для всячины
		
	printf("Input text(300 symvolov max): "); 
	gets(TEXT); //получаем текст
	dlina_text = strlen(TEXT); //узнаём длину для оптимизации цикла
	printf("sravnenie tolko 40 slov\n"); //блабла предупреждение
	
	for(i = 0; i < dlina_text;i++) //делим текст на строки
	{
		if (TEXT[i] != ' ' and TEXT[i] != ',') //елси не пробел и не зпт
		{
			SLOVO[k][j] = TEXT[i]; //то это то что надо
			j++; //символы до спец символа поочереди
		}
		else  //иначе
		{
			k++; //переход к след строки
			j = 0; //переход к первому символу
		}
	}
	
	puts("Vse unikalnie slova: "); //блабла
	
	for (i = 0; i < K; i++)  //цикл поиска уникальности
	{
		for (j = 0; j < K; j++)	//для перебора всех элементов
		{
			if (strcmp(SLOVO[i],SLOVO[j]) == 0) //если слова одинаковы
			{
				ch[i]++; //записываем сколько раз повторялось
			}
		}
	}
		
	for (i = 0; i < K; i++) //цикл вывода слов
	{
		kol = 0; //обнуляем количество встреч
		for (j = 0; j < i; j++) //для перебора всех элементов
		{
			if (strcmp(SLOVO[i],SLOVO[j]) == 0) //если похожи
			{
				kol++; //увеличиваем число
			}
		}
		if(kol == 0 and (strcmp(SLOVO[i],sravn[i]) != 0)) //если же конец
		{
			printf("%s povtoryaetsa: %d\n",SLOVO[i], ch[i]);	//выводим слова и сколько раз повторялись
		}
	}
	
	system("PAUSE");
	return 0; 
}
