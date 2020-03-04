#include "Stack.h"

Stack::Stack()
{
    head = NULL;
}

void Stack::push(int vall)
{
	stack *newelem = new stack;
	newelem->data = vall;
	if(head == nullptr)
	{
	    head = newelem;
	    head->next = nullptr;
	}
	else
	{
	    newelem->next = head;
	    head = newelem;
	}
}

void Stack::clear()
{
    stack *tmp = new stack;
    stack *ptr = head;
    while (ptr != NULL)
    {
        tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    head = nullptr;
}

void Stack::print()
{
	stack *ptr = head;
    while (ptr)
    {
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }
}

void Stack::printNeed(int x)
{
	stack *ptr = head;
	for(int i = 1; i < x; i++)
	{
		ptr = ptr->next;
		try
		{
			if(ptr == nullptr)
				throw 404;
		}
		catch(int i)
		{
				cout << "Ёлемента под "<< x << " номером в стеке нет." << endl;
				return;
		}

	}
	cout << "Ёлемент: "<<ptr->data << endl;
}


