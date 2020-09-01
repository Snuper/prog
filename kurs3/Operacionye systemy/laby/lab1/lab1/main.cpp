#include <QCoreApplication>
#include <QProcess>
#include <iostream>

/*
3 - Функция удаления
5 - Серилизация структуры
7 - Функция вставки в середину
*/

using namespace std;

struct Data
{
    Data *Next;
    string name;
    int age;
};

void menu_input(int &input, int &counter, int &all_item, bool &exit, Data *&Head, Data *&Start)
{//Обращение с меню
    int wait;

    if(input == 1)
    {//Перемещение
        if(counter >= all_item)
        {//Если мы дошли до конца списка
            cout << endl << "----------------------------------------------" << endl << "Last item, input '0' to continue" << endl << "Input: ";
            cin >> wait;
        }

        else
        {
            Head = Head->Next;
            counter++;
        }
    }

    else if(input == 2)
    {//Вставка
        if (!Head)
        {//Если это первый элемент
            Head = new Data;
            cout << endl << "Input name: ";
            cin >> Head->name;
            cout << endl << "Input age: ";
            cin >> Head->age;
            Start = Head;
            Head->Next = NULL;
            all_item++;
        }

        else
        {
            while(Head->Next != NULL) Head = Head->Next;
            Head->Next = new Data;
            cout << endl << "Input name: ";
            cin >> Head->Next->name;
            cout << endl << "Input age: ";
            cin >> Head->Next->age;
            Head->Next->Next = NULL;
            all_item++;
            Head = Start;
            counter = 1;
        }
    }

    else if(input == 3)
    {
        ;
    }

    else if(input == 4)
    {
        ;
    }

    else if(input == 5)
    {
        ;
    }

    else if(input == 6)
    {
        Head = Start;
        counter = 1;
    }
    else if(input == 7) exit = true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Data *Head = NULL, *Start = NULL; //Указатели на пустые элементы структур, голова и начало
    bool exit = false;

    for(int input, counter = 1, all_item = 0; exit == false;)
    {//меню
        system("cls");
        cout << "Menu:" << endl << "1 - Next" << endl << "2 - Paste" << endl << "3 - Delete" << endl << "4 - Serializing a list" << endl << "5 - Display the entire list" << endl << "6 - Go start" << endl << "7 - Exit";
        if(all_item > 0)
        {
            cout << endl << "----------------------------------------------" << endl << "Counter: " << counter << "/" << all_item; //Счетчик с обозначением, элемента на котром находишся + всего элементов
            cout << endl << "Name: " << Head->name << endl << "Age: " << Head->age;
        }
        cout << endl << "----------------------------------------------" << endl << "Input: ";
        cin >> input;
        menu_input(input, counter, all_item, exit, Head, Start);
    }

    return 0;
}
