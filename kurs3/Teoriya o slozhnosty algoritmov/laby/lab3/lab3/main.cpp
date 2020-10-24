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
    bool first_pb = true;//флаг для отслеживания первого мержа в pushback
    int border_pb = 0, cut_n, save_n = n;//граница пушбэка \ переменная, которая хранит начало среза с основного массива
    int *pushback = new int [n];//массив, в который мержу отростки основного масива
    //Для цикла потребуется:
    //Sbrush = размер кисти, который увеличивается в 2 раза
    for(int Sbrush = 1, prev_n; Sbrush < n; Sbrush *= 2)
    {//Идея такова, оригинальный массив служит буфером с которым мы будем работать
     //Будут два масива(Lbrush и Rbrush) в которые мы будет записывать элементы сортируемого масива
     //Далее начинаем мержить две кисти и результат записывать в сортируемый массив
     //Если массив не четкий, то мы не трогаем лишний элемент до самого конца
     //Мы его просто добавим на свою позицию в уже остортиорованный массив

        if((n / Sbrush) % 2 != 0)
        {//работаем так
         //если есть одиночная кисть
         //то мы ее мержим с масивом, в котором хранятся все лишние элементы
         //потом, в самом конце мы проведем глобальный и последний мерж
         //масива и буфера
            if(first_pb == true)
            {//для первого мержа не мержим, чисто создаем пушбэк
                cut_n = n - Sbrush;//определяем срез основного массива
                border_pb += n - cut_n;//задаем границу pushback
                n = cut_n;//уменьшаем размер основного массива

                for(int i_pb = 0, i_mm = cut_n; i_pb < border_pb; i_pb++, i_mm++)
                {//записываем лишний кусочек
                    pushback[i_pb] = massiv[i_mm];
                }

                first_pb = false;
            }

            else
            {
                prev_n = n;
                cut_n = n - Sbrush;//определяем срез основного массива
                int *temp_brush = new int[n - cut_n + (border_pb + (n - cut_n))];//создаем временную кисть для мержа
                                                     //в эту кисть мы будем мержить из массива pb и основного масива
                                                     //далее мы перезапишем результат обратно в пб и освободим память
                n = cut_n;//уменьшаем размер основного массива
                for(int i_pb = 0, i_mm = cut_n, i_tbr = 0;/*пока i_pb/i_mm не достигнет размера кисти*/;)
                {//Здесь мержим кисти
                    if(massiv[i_mm] < pushback[i_pb])
                    {//по возростанию
                        temp_brush[i_tbr] = massiv[i_mm];
                        i_mm++;
                        i_tbr++;
                    }

                    else
                    {
                        temp_brush[i_tbr] = pushback[i_pb];
                        i_pb++;
                        i_tbr++;
                    }

                    if(i_mm == prev_n)
                    {//если левая кисть пустая, то правую мы можем просто переписать
                        while(i_pb < border_pb)
                        {
                            temp_brush[i_tbr] = pushback[i_pb];
                            i_pb++;
                            i_tbr++;
                        }
                        break;
                    }

                    else if (i_pb == border_pb)
                    {//если правая кисть пустая, то левую мы можем просто переписать
                        while(i_mm < prev_n)
                        {
                            temp_brush[i_tbr] = massiv[i_mm];
                            i_mm++;
                            i_tbr++;
                        }
                        break;
                    }
                }
                for(int i = 0; i < prev_n - cut_n + (border_pb + (prev_n - cut_n)); i++) pushback[i] = temp_brush[i];
                delete [] temp_brush;
                border_pb += prev_n - cut_n;//задаем новую границу pushback
            }
        }

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

    //главный мерж!!!
    int *result_brush = new int [save_n];
    for(int M = 0, PB = 0, R = 0;/*пока L/R не достигнет размера кисти*/;)
    {//Здесь мержим кисти
        if(massiv[M] < pushback[PB])
        {//по возростанию
            result_brush[R] = massiv[M];
            M++;
            R++;
        }

        else
        {
            result_brush[R] = pushback[PB];
            PB++;
            R++;
        }

        if(M == n)
        {//если левая кисть пустая, то правую мы можем просто переписать
            while(PB < border_pb)
            {
                result_brush[R] = pushback[PB];
                PB++;
                R++;
            }
            break;
        }

        else if (PB == border_pb)
        {//если правая кисть пустая, то левую мы можем просто переписать
            while(M < n)
            {
                result_brush[R] = massiv[M];
                M++;
                R++;
            }
            break;
        }
    }
    show(result_brush, save_n);
    for(int i = 0; i < save_n; i++) massiv[i] = result_brush[i];
    delete [] result_brush;
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
*/

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
