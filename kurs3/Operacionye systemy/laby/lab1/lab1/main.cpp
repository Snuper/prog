#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

struct Info
{
    char name[30];
    int age;
};

struct Data
{
    Data *Next;
    Info simple_info;
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
            cin >> Head->simple_info.name;
            cout << endl << "Input age: ";
            cin >> Head->simple_info.age;
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
                    cin >> New_element->simple_info.name;
                    cout << endl << "Input age: ";
                    cin >> New_element->simple_info.age;
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
                    cin >> New_element->simple_info.name;
                    cout << endl << "Input age: ";
                    cin >> New_element->simple_info.age;
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
                        cin >> Head->Next->simple_info.name;
                        cout << endl << "Input age: ";
                        cin >> Head->Next->simple_info.age;
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
    {//серилизация
        ofstream out("struct.bin", ios::binary);
        Head = Start;

        out.write((char*)&all_item, sizeof(all_item));

        while(Head != NULL)
        {
            out.write((char*)Head, sizeof(Data));
            Head = Head->Next;
        }

        out.close();
        Head = Start;
        counter = 1;
    }

    else if(input == 5)
    {//десирилизация
        ifstream in("struct.bin", ios::binary);

        Data *new_Head = NULL, *new_Start = NULL;

        in.read((char*)&all_item, sizeof(all_item));
        for(int i = 0; i < all_item; i++)
        {
            if (!new_Head)
            {//Если это первый элемент
                new_Head = new Data;

                in.read((char*)new_Head, sizeof(Data));

                new_Start = new_Head;
                new_Head->Next = NULL;
            }

            else
            {
                while(new_Head->Next != NULL) new_Head = new_Head->Next;
                new_Head->Next = new Data;

                in.read((char*)new_Head->Next, sizeof(Data));

                new_Head->Next->Next = NULL;
                new_Head = new_Start;
                counter = 1;
            }
        }

        in.close();
        Start = new_Start;
        Head = Start;
        counter = 1;
    }

    else if(input == 6)
    {//Делаем заготовку, после вывода всех элементов списка, возвращаем всё начало
        Head = Start;
        for(counter = 1; counter < all_item + 1; counter++)
        {
            cout << endl << "Counter: " << counter << "/" << all_item << endl << "Name: " << Head->simple_info.name << endl << "Age: " << Head->simple_info.age << endl;
            Head = Head->Next;
        }
        cout << endl << "----------------------------------------------" << endl << "Input '0' to continue" << endl << "Input: ";
        cin >> wait;
        Head = Start;
        counter = 1;
    }

    else if(input == 7)
    {//вернуть в начало
        Head = Start;
        counter = 1;
    }
    else if(input == 8) exit = true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Data *Head = NULL, *Start = NULL; //Указатели на пустые элементы структур, голова и начало
    bool exit = false;

    for(int input, counter = 1, all_item = 0; exit == false;)
    {//меню
        system("cls");
        cout << "Menu:" << endl << "1 - Next" << endl << "2 - Paste" << endl << "3 - Delete" << endl << "4 - Save" << endl << "5 - Load" << endl << "6 - Display the entire list" << endl << "7 - Go start" << endl << "8 - Exit";
        if(all_item > 0)
        {
            cout << endl << "----------------------------------------------" << endl << "Counter: " << counter << "/" << all_item; //Счетчик с обозначением, элемента на котром находишся + всего элементов
            cout << endl << "Name: " << Head->simple_info.name << endl << "Age: " << Head->simple_info.age;
        }
        cout << endl << "----------------------------------------------" << endl << "Input: ";
        cin >> input;
        if(input > 0 and input < 9) menu_input(input, counter, all_item, exit, Head, Start);
    }

    delete Head;
    delete Start;

    return 0;
}
