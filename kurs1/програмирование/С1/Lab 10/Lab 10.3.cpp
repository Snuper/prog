#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 300, K = 40;
int main ()
{ 
	char TEXT[N], SLOVO[K][K] = {0}; //массив текста
	int i = 0, j = 0, k = 0, dlina_text = 0; //dдля оптимизации цикла и для перехода по элементам
	char c[K][K];	//ещё массив текста
	
	printf("Input text(300 symvolov max): "); //блабла
	gets(TEXT); //получаем текст
	dlina_text = strlen(TEXT); //ищем длину
	printf("alphavit poryadok: \n"); //блабла
	//rebotaet ne lez!
	for(i = 0; i < dlina_text;i++) //делим на строки текст
	{
		if (TEXT[i] != ' ' and TEXT[i] != ',') //не равно и не зпт
		{
			SLOVO[k][j] = TEXT[i]; //это оно
			j++; //след символ
		}
		else  //иначе
		{
			k++; //след строка
			j = 0; //обнуляем символ
		}
	}
	for(i = 0; i < k; i++) //пузырбковый только для текста снизу вверх
	{
		for (j = k - 1; j >= i; j--) //сверху вниз
		{
			if (strncmp(SLOVO[j],SLOVO[j+1],1) > 0) //сравниваем
			{
				strcpy(c[i],SLOVO[j]); //копируем в буфер
				strcpy(SLOVO[j],SLOVO[j+1]); //меняем местами
				strcpy(SLOVO[j+1],c[i]); //из буфера
			}
		}
	}
	for (i = 0; i < k+1; i++) //цикл вывода
	{
		printf("%d. %s\n", i + 1, SLOVO[i]); //блабла i+1 для красоты
	}
	system("PAUSE");
	return 0; 
}
