#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const N = 300,R = 11;
int main ( )
{ 
	char TEXT[N], SRAVNENIE[R], SLOVO[10][40]{0}; //объявляем вещественные массивы 
	int i = 0, j = 0, k = 0, dlina = 0,dlina_text = 0,sravn = 0; // переменные
	
	printf("Input s chem sravnivat`(10 symvolov max): "); 
	gets(SRAVNENIE); //получем значение
	dlina = strlen(SRAVNENIE); // получаем длину сравнения	
	printf("Input text(300 symvolov max): ");
	gets(TEXT); //получаемя текст
	dlina_text = strlen(TEXT); // получаемя длину текста (эти длины просто оптимизация, чтобы он не весь массив прогонял, не факт, что весь массив заполнят текстом)
	printf("sravnenie tolko 10 slov\n"); 
	
	for(i = 0; i < dlina_text;i++) //цикл деления на строки текст, каждое слово = отдельная ячейка в массиве
	{
		if (TEXT[i] != ' ' and TEXT[i] != ',')  // условия это пробел или запятая 
		{
			SLOVO[k][j] = TEXT[i]; //сохраняем в ячейку
			j++; //перехдим к следующему символу в строке
		}
		else //иначе
		{
			k++; //прибавляем переходим к следующей строке
			j = 0; //обнуляем символ в строке
		}
	}
	
	puts("Slova podhodyat: "); //выводим слова подходящие под приставку

	for (i = 0; i < 10; i++) //вывод этих слов
	{
		sravn = strncmp(SLOVO[i],SRAVNENIE,dlina); //сравнивается приставка и слово
		if(sravn == 0) // совпадает
		{
			puts(SLOVO[i]); //вывод этого слова
		}
	}
	
	system("PAUSE");
	return 0; 
}
