#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

const int M=10,n=8;
int main()
{
	int i,j,A;
	
//__________________________________{создание динамического массива **}
	int **x = new int* [M];
		for ( i=0; i<M; i++)
		x[i] = new int [A]; 		
	for (i=0; i<M; i++)
	{
		A = rand()%n+8;
		for (j=0; j<A; j++)
		{
			x[i][j]=rand()%n+2;
			printf (" %d",x[i][j]);
		}
	printf ("\n");
	} 
//__________________________________{окончание создания **}
//__________________________________{начало удаления выделенной памяти **}
	for (int i = 0; i < M; i++)
        delete []x[i];
//__________________________________{окончание удаления **};		
}
