#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>
#include <ctime>
#include <iostream>

using namespace std;

const int width = 500, height = 500; //размер окна
const int points = 100; //кол-во точек
int i;

void Draw(int x, int y, int color)
{
	setfillstyle(1, 0); //выбираем заливкузаполняем
	line(x+5,y,x-5,y); //рисуем
	line(x,y-5,x,y+5);
	floodfill(x, y, color); //заливаем
}

int main()
{
	initwindow(width,height); //окно
	srand(time(0)); //рандом
	int x[points], y[points], color; //массив координат
	for(i = 0; i < points; i++) //заполняем 
	{
		x[i] = rand() % (3 + (width-3)); //рандом по иксу
		y[i] = rand() % (3 + (height-3)); //рандом по игрику
	}
	while(1) //бесконечно
	{
	if (kbhit()) //нажатие кнопки если без кбхит будет ждать нажатия после каждого цикла
	if(getch() == 27) ///если это esc
	{
		break; //выходим из цикла и программы
	}
		i = rand()%points; //рандомное место в массиве
		color = rand()%15; //рандомный цвет
		Draw(x[i], y[i], color);
		delay(5); //задержка
		//просто  4 одинаковых функции удаления, сказали всё на рандоме, удаление тоже
		i = rand()%points;  //рандомное место (может быть пустым, поэтому использую аж  4 одинаковых функции)
	}
	closegraph(); //закрываем окно
}
