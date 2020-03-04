/*
o - используем дл€ подсчета шагов(диагонали) 
p - позици€ в одномерном массиве 
j - горизонтальна€ координата
i - вертикальна€ координата
counter - счЄтчик
convert - переменна€ дл€ конвертировани€ переменной "o"
back - переменна€ дл€ обратного конвертировани€ переменной "o"
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

const int M = 10,n = 8;
int main()
{
	int p, i, j, o = 1, counter = 0, convert = 0, back = 0;
	setlocale(LC_CTYPE, "rus");
	srand (time(0));
//__________________________________{создание динамического массива **}
	int **x = new int* [M];
		for ( i=0; i<M; i++)
		x[i] = new int [M]; 		
	for (i=0; i<M; i++)
	{
		for (j=0; j<M; j++)
		{
			x[i][j]=rand()%n+2;
			printf (" %d",x[i][j]);
		}
	printf ("\n");
	} 
//__________________________________{окончание создани€ **}
//__________________________________{ѕо правым диоганал€м}
	int *zad_a = new int[M*M];
	cout << endl << "«адание под а" << endl;
	for (p = 0, i = 1, j = M; p < M*M; o++) 
	{
		cout << endl;
		i = o;
		j = M;
		counter = 0;
		if ( o > M - 1 )
			{
				o = o - convert;
				i = M;
				j = o;
				back = o + convert;
				convert = convert + 2;
			}
		while ( counter < o )
			{
				counter ++;
				i--;
        		j--;
				zad_a[p] = x[i][j];
        		printf ("[%d][%d] = %d\n",j , i , zad_a[p]);
        		p++;
			}
		if ( back > 1)
			o = back;
	}
    delete [] zad_a;//удаление выделенной пам€ти *
//__________________________________{ѕо правым диоганал€м}
//__________________________________{начало удалени€ выделенной пам€ти **}
	for (int i = 0; i < M; i++)
        delete []x[i];
//__________________________________{окончание удалени€ **}			
}
