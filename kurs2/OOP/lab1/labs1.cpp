/*
o - ���������� ��� �������� �����(���������) 
p - ������� � ���������� ������� 
j - �������������� ����������
i - ������������ ����������
counter - �������
convert - ���������� ��� ��������������� ���������� "o"
back - ���������� ��� ��������� ��������������� ���������� "o"
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
//__________________________________{�� ������ ����������}
	int *zad_a = new int[M*M];
	cout << endl << "������� ��� �" << endl;
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
    delete [] zad_a;//�������� ���������� ������ *
//__________________________________{�� ������ ����������}
//__________________________________{������ �������� ���������� ������ **}
	for (int i = 0; i < M; i++)
        delete []x[i];
//__________________________________{��������� �������� **}			
}
