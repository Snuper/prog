#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

const int widht = 800, hieght = 600; //размеры окна

int main()
{
	int x = -20, y, i = 0; //координаты
	
	initwindow(widht, hieght); //окошечко
	
	setcolor(WHITE); //цвет линий белый
	moveto(widht/2,0); // следуем в точку
	lineto(widht/2, hieght); //рисуем линию из точки куда пришли в координаты, которые в скобочках
	outtextxy(widht/2 + 20 , 30, "Y ^"); //выводим текст игрик вверх
	
	
	setcolor(WHITE); //цвет линий белый
	moveto(0,hieght/2); // курсор сюда
	lineto(widht, hieght/2); //линия от курсора сюда	
	outtextxy(widht - 50, hieght/2 - 20, "X ->"); //вывод текста икс вправо
	//костыль для чистого экрана без мазюк
	y = sqrt(25 - pow(x,2));	//нахождения значения функции
	moveto(widht/2 + x*10, hieght/2 - y*10); //перемещение туда курсора
	
	//функция первая
	for (float a = -20; a <= 20; a += 2.1) //значения  икса функции
	{
		y = sqrt(25 - pow(a,2)); //получаем значение
		setcolor(WHITE); //линия белая
		lineto(widht/2 + a*10, hieght/2 - y*10); //линия
		moveto(widht/2 + a*10, hieght/2 - y*10); //курсор
	}
	outtextxy(widht/2 - 100 , hieght/2 - 100, "y = sqrt(25 - pow(x,2))"); //вывод текста, что это за формула
	
	//костыль для чистого экрана
	y = 2; //это равно
	moveto(widht/2 + x *10, hieght/2 - y*10);	 //курсор сюда
	
	//функция вторая
	for (x = -20; x <= 20; x++) //икс функции
	{
		y = 2; //игрик
		setcolor(WHITE); //белый цвет
		lineto(widht/2 + x*10, hieght/2 - y*10); //линия
		moveto(widht/2 + x*10, hieght/2 - y*10); //курсор
	}
	outtextxy(widht/2 + x*10 , hieght/2 - 20, "y = 2"); //вывод что за формула
	
	//заркашиваем нужное
	setfillstyle(1,GREEN); //стиль и цвет заливки
	floodfill(widht/2 - 1, hieght/2 - y,WHITE); //где
	floodfill(widht/2 + 1, hieght/2 - y,WHITE); //где
	
	getch(); //ждём нажатия
	closegraph(); //выходим из программы
}
