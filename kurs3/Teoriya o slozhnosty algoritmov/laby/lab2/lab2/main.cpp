#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

void random_input(int *massiv, int n)
{//Рандомим массив
    for(int i = 0; i < n; i++) massiv[i] = rand()%100;
}

void show(int *massiv, int &n, int &step, int &swap_sh, int &small_sh)
{//Вывод массива + шаг + показать свапнутые элементы
    cout << endl << "Step[" << step << "]" << "   ";
    for(int i = 0; i < n; i++) cout << massiv[i] << " ";
    cout << " | " << swap_sh << " -> " << small_sh;
    cout << endl;
}

void show(int *massiv, int &n)
{//Вывод массива
    cout << endl << "Massiv" << "   ";
    for(int i = 0; i < n; i++) cout << massiv[i] << " ";
    cout << endl;
}

void bublesort(int *massiv, int &n, int &c, int &m)
{//Сортировка
    bool swaped;
    for(int i = 1, step = 0, swap_sh, small_sh, swap, temp_n = n; temp_n > 1; temp_n--)
    {
        swaped = false;
        for(int j = i; j < temp_n; j++)
        {
            if(massiv[j - 1] < massiv[j])
            {
                step++;
                swaped = true;

                small_sh = massiv[j];//нужно для вывода

                swap = massiv[j];
                massiv[j] = massiv[j - 1];
                massiv[j - 1] = swap;

                swap_sh = massiv[j];//нужно для вывода
                show(massiv, n, step, swap_sh, small_sh);
                m++;
            }
            c++;
        }
        if(swaped == false) break;
    }

}

int main()
{
    srand(time(NULL));

    int n, c = 0, m = 0, arm_input; //M - число присваиваний, C - число сравнений
    cout << endl << "Input size array: ";
    cin >> n;

    int *massiv = new int [n];

    cout << endl << "Rychnoi vvod? ";
    cin >> arm_input;


    if(arm_input) //если любое число, кроме нуля
        for(int i = 0; i < n; i++)
        {
            cout << endl << "Massiv[" << i << "] = ";
            cin >> massiv[i];
        }

    else random_input(massiv, n);

    show(massiv, n);

    bublesort(massiv, n, c, m);

    cout << endl << "M = " << m * 3 << endl << "C = " << c;
    return 0;
}
