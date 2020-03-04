#include <iostream>
#include <conio.h>
#include <time.h>
#include "List.h"
#include "Stack.h"
#include "queue.h"
using namespace std;


int main()
{
	setlocale(0, "");
	srand(time(0));
    int n = 10, k;
    Stack *st = new Stack[n];
    Queue *q = new Queue[n];
    for (int i = 0; i < 10; i++)
    {
        k = rand() % 100;
        st->push(k);
        q->push(k);
    }
    cout << "Стек: ";
    st->print();
    cout << endl << "Очередь: ";
	q->print();
	int x;
	cout << endl;
	cout << "Введите номер элемента в стеке: ";
	cin >> x;
	st->printNeed(x);
    system("PAUSE");
    return 0;
}
