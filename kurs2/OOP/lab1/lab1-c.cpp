/*
p - ������� � ���������� ������� 
j - �������������� ����������
i - ������������ ����������
complete - ���������� ��� �������� ���-�� ����������� ����� �� ������ �� ������ (->DRUL->)
number - ����������, � ������� �������� ����� ���-�� �����, ��� ���������� �������
check - �������� ���������
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

const int M = 10, n = 8;
int main()
{
	int p, i, j, o = 1, counter = 0, convert = 0, back = 0, number = 1, check = 0, complete = 0;
	setlocale(LC_CTYPE, "rus");
	srand (time(0));
//__________________________________{�������� ������������� ������� **}
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
//__________________________________{��������� �������� **}
//__________________________________{������� �� ������}
	int *zad_a = new int[M*M];
	cout << endl << "������� ��� c" << endl;
	for ( o = 1, p = 0, i = (M/2)-1, j = (M/2)-1; p < M*M; check++) 
	{	
		for ( complete = 0; complete < number; complete++ ) //DOWN
		{
			zad_a[p] = x[i][j];
    		printf ("[%d][%d] = %d (DOWN) \n",j , i , zad_a[p]);
			i++;
   			p++;
		}
		for ( complete = 0; complete < number; complete++ ) //RIGHT
		{
			zad_a[p] = x[i][j];
    		printf ("[%d][%d] = %d (RIGHT) \n",j , i , zad_a[p]);
			j++;
    		p++;
		}
		check++;
		if ( check == 10 )
    	check = 0;
    	else
    	number++;
		for ( complete = 0; complete < number; complete++ ) //UP
		{
			zad_a[p] = x[i][j];
    		printf ("[%d][%d] = %d (UP) \n",j , i , zad_a[p]);
			i--;
    		p++;
		}
		for ( complete = 0; complete < number; complete++ ) //LEFT
		{
			zad_a[p] = x[i][j];
    		printf ("[%d][%d] = %d (LEFT) \n",j , i , zad_a[p]);
			j--;
    		p++;
		}
    	if ( check == 10 )
    		check = 0;
    	else
    	number++;
	}
    delete [] zad_a;//�������� ���������� ������ *
//__________________________________{������� �� ������}
//__________________________________{������ �������� ���������� ������ **}
	for (int i = 0; i < M; i++)
        delete []x[i];
//__________________________________{��������� �������� **}			
}
