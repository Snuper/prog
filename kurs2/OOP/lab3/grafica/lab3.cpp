#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>
#include <ctime>
#include <iostream>

using namespace std;

const int width = 500, height = 500; //������ ����
const int points = 100; //���-�� �����
int i;

void Draw(int x, int y, int color)
{
	setfillstyle(1, 0); //�������� ����������������
	line(x+5,y,x-5,y); //������
	line(x,y-5,x,y+5);
	floodfill(x, y, color); //��������
}

int main()
{
	initwindow(width,height); //����
	srand(time(0)); //������
	int x[points], y[points], color; //������ ���������
	for(i = 0; i < points; i++) //��������� 
	{
		x[i] = rand() % (3 + (width-3)); //������ �� ����
		y[i] = rand() % (3 + (height-3)); //������ �� ������
	}
	while(1) //����������
	{
	if (kbhit()) //������� ������ ���� ��� ����� ����� ����� ������� ����� ������� �����
	if(getch() == 27) ///���� ��� esc
	{
		break; //������� �� ����� � ���������
	}
		i = rand()%points; //��������� ����� � �������
		color = rand()%15; //��������� ����
		Draw(x[i], y[i], color);
		delay(5); //��������
		//������  4 ���������� ������� ��������, ������� �� �� �������, �������� ����
		i = rand()%points;  //��������� ����� (����� ���� ������, ������� ��������� ��  4 ���������� �������)
	}
	closegraph(); //��������� ����
}
