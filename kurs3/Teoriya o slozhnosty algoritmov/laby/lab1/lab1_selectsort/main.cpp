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
    cout << endl << "Massiv[" << step << "]" << "   ";
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

void selectsort(int *massiv, int &n, int &c, int &m)
{//Сортировка
    bool flag = false;
    for(int i = 0, step = 0, small = 0, swap = 0, swap_sh = 0, small_sh = 0; i < n-1; i++, step++)
    {
        flag = false;
        small = i;
        for(int j = i + 1; j < n; j++)
        {//ищем наименьший
            if(massiv[j] < massiv[small])
            {
                small = j;
                flag = true;
            }
            c++;
        }
        if(flag == true)
        {//если флаг = трю, свапаем элементы
            swap_sh = massiv[i];
            small_sh = massiv[small];

            swap = massiv[i];
            massiv[i] = massiv[small];
            massiv[small] = swap;
            m++;
        }
        show(massiv, n, step, swap_sh, small_sh);
    }
}

int main()
{
    srand(time(NULL));

    int n, c = 0, m = 0, arm_input; //m - число перестановок c - число проходов
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

    selectsort(massiv, n, c, m);

    cout << endl << "Practic(perestanovok): " << m * 3 << endl << "Practic(prohodov)" << c;
    return 0;
}
