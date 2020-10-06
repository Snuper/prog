#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

void random_input(int *massiv, int n)
{//Рандомим массив
    for(int i = 0; i < n; i++) massiv[i] = rand() % 100;
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

void mergesort(int *massiv, int n, int &c, int &m)
{//Сортировка
    bool EXelement = false;
    if(n % 2 != 0)
    {//если есть лишний элемент, то в конце мы добавим его на свою позицию
        n--;
        EXelement = true;
    }

    //Для цикла потребуется:
    //Sbrush = размер кисти, который увеличивается в 2 раза
    for(int Sbrush = 1; Sbrush < n; Sbrush *= 2)
    {//Идея такова, оригинальный массив служит буфером с которым мы будем работать
     //Будут два масива(Lbrush и Rbrush) в которые мы будет записывать элементы сортируемого масива
     //Далее начинаем мержить две кисти и результат записывать в сортируемый массив
     //Если массив не четкий, то мы не трогаем лишний элемент до самого конца
     //Мы его просто добавим на свою позицию в уже остортиорованный массив

        int *Lbrush = new int [Sbrush];//Левая кисть
        int *Rbrush = new int [Sbrush];//Правая ксить

        for(int M = 0, i, j; M < n;)
        {//цикл заполняет кисти и мержит их

            for(i = 0, j = M; i < Sbrush; i++, j++) Lbrush[i] = massiv[j];
            for(i = 0; i < Sbrush; i++, j++) Rbrush[i] = massiv[j];


            for(int L = 0, R = 0;/*пока L/R не достигнет размера кисти*/;)
            {//Здесь мержим кисти
                if(Lbrush[L] < Rbrush[R])
                {//по возростанию
                    massiv[M] = Lbrush[L];
                    L++;
                    M++;
                }

                else
                {
                    massiv[M] = Rbrush[R];
                    R++;
                    M++;
                }

                if(L == Sbrush)
                {//если левая кисть пустая, то правую мы можем просто переписать
                    while(R < Sbrush)
                    {
                        massiv[M] = Rbrush[R];
                        R++;
                        M++;
                    }
                    break;
                }

                else if (R == Sbrush)
                {//если правая кисть пустая, то левую мы можем просто переписать
                    while(L < Sbrush)
                    {
                        massiv[M] = Lbrush[L];
                        L++;
                        M++;
                    }
                    break;
                }
            }
            show(massiv, n);
        }

        delete [] Lbrush;
        delete [] Rbrush;
    }

    if(EXelement == true)
    {//делаем по-последний мерж
        int *sort_massiv = new int [n];
        int lastElement = massiv[n + 1];

        for(int e = 0; e < n; e++) sort_massiv[e] = massiv[e];

        for(int e = 0;;)
        {//Здесь мержим кисти
            if(sort_massiv[e] < lastElement)
            {//по возростанию
                massiv[e] = sort_massiv[e];
                e++;
            }

            else
            {//так как он один, сразу начинем записывать оставшиеся элементы
             //и выходить из цикла
                massiv[e] = lastElement;
                e++;

                while(e < n + 1)
                {
                    massiv[e] = sort_massiv[e - 1];
                    //i - 2, так как после записи последнего элемента
                    //идет рассинхрон в 2 элемента
                    e++;
                }

                break;
            }

        }
    }

    show(massiv, n);
}

int main()
{
    srand(time(NULL));

    int n, c = 0, m = 0, arm_input; //M - число присваиваний, C - число сравнений
    cout << "Input size array: ";
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

    mergesort(massiv, n, c, m);

    cout << endl << "M = " << m * 3 << endl << "C = " << c;
    return 0;
}

/*
int brush_size = 1;//размер кисти
//    int counter_brush;
//    int counter_m;//счетчик сравнений, которые нужно выполнить
int new_left_brush_border, new_right_brush_border;//Нужны для дотого, что бы регулировать индексы левой и правой кистей
int i, j;//i и j использую как индекс левой и правой стороны, при сравнивании
for(int step = 0, swap;; brush_size *= 2)
{//этот цикл будет перебрасывать на уровень выше
    new_left_brush_border = brush_size;//граница левой кисти равна размеру кисти
    new_right_brush_border = (brush_size * 2);//граница правой кисти, равна
    //ДОЛЖНА БЫТЬ ПРОВЕРКА ПРАВОЙ ГРАНИЦЫ, ЕСЛИ ОНА НЕ БУДЕТ ЧЕТНОЙ
    if(brush_size > n) break;
    while(true)
    {//а этот цикл координирует сравнения на данном уровне

        if(new_right_brush_border > n) break;
        //значит кистей больше нет и можно перейти на уровень выше

        //создаем кисти
        int *left_brush = new int [brush_size];
        int *right_brush = new int [brush_size];

        //для начала заполним наши кисти
        for(int lb = 0, i = new_left_brush_border - brush_size; i < new_left_brush_border; lb++, i++) left_brush[lb] = massiv[i];
        for(int rb = 0, j = new_right_brush_border - brush_size; j < new_right_brush_border; rb++, j++)right_brush[rb] = massiv[j];

        for(int lb = 0, rb = 0;;)
        {//сравниваем созданные кисти
            if(left_brush[lb] > right_brush[rb])
            {//по возрастанию
                //нужно сравнить кисти
            }
            c++;
        }
        delete [] left_brush;
        delete [] right_brush;

        new_left_brush_border += brush_size * 2;
        new_right_brush_border += brush_size * 2;
        //ДОЛЖНА БЫТЬ ПРОВЕРКА ПРАВОЙ ГРАНИЦЫ, ЕСЛИ ОНА НЕ БУДЕТ ЧЕТНОЙ
    }
}
*/
