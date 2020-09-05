#include <QCoreApplication>
#include <iostream>

/*
5 - Серилизация структуры
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
            int pos_in_list;
            struct Data *New_element;

            cout << endl << "Enter the position of the new item: ";
            cin >> pos_in_list;

            if(pos_in_list > 0)
            {//простенькая защита
                if(pos_in_list == 1)
                {
                    New_element = new Data;
                    cout << endl << "Input name: ";
                    cin >> New_element->name;
                    cout << endl << "Input age: ";
                    cin >> New_element->age;
                    Head = Start;//На всякий случай, ведь по голова может стоять не в начале и мы ее потеряем
                    New_element->Next = Head;
                    Start = New_element;
                    all_item++;
                    Head = Start;
                    counter = 1;
                }

                else if(pos_in_list < all_item)
                {
                    New_element = new Data;
                    cout << endl << "Input name: ";
                    cin >> New_element->name;
                    cout << endl << "Input age: ";
                    cin >> New_element->age;
                    Head = Start;//в елсе не нужно, ведь ей без разницы, откуда начать искать конец
                    for(int i = 1; i < pos_in_list - 1; i++) Head = Head->Next;
                    New_element->Next = Head->Next;
                    Head->Next = New_element;
                    all_item++;
                    Head = Start;
                    counter = 1;
                }

                else
                {//если в конец
                    if(pos_in_list < all_item + 2)
                    {//против ввода больше значения, чем кол во всего элементов
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
            }
        }
    }

    else if(input == 3)
    {//Удаление
        struct Data *Swap;
        cout << endl << "Enter the number of the item to remove: ";
        cin >> wait;

        if(wait > 0 and wait <= all_item)
        {
            for(int i = 1; i < wait - 1; i++) Head = Head->Next; //находим элемент

            if(wait == 1)
            {//Если начало
                Start = Head->Next;
                delete Head;
            }

            else if(wait == all_item) delete Head->Next;

            else
            {
                Swap = Head->Next;
                Head->Next = Head->Next->Next;
                delete Swap;
            }

            Head = Start;
            counter = 1;
            all_item--;
        }
    }

    else if(input == 4)
    {
        ;
    }

    else if(input == 5)
    {//Делаем заготовку, после вывода всех элементов списка, возвращаем всё начало
        Head = Start;
        for(counter = 1; counter < all_item + 1; counter++)
        {
            cout << endl << "Counter: " << counter << "/" << all_item << endl << "Name: " << Head->name << endl << "Age: " << Head->age << endl;
            Head = Head->Next;
        }
        cout << endl << "----------------------------------------------" << endl << "Input '0' to continue" << endl << "Input: ";
        cin >> wait;
        Head = Start;
        counter = 1;
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
        if(input > 0 and input < 8) menu_input(input, counter, all_item, exit, Head, Start);
    }

    delete Head;
    delete Start;

    return 0;
}
