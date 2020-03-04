#include "queue.h"

Queue::Queue() 
{
	head = tail = nullptr; 
}


void Queue::push(int value) //добавление элемента
{
	if(head == nullptr)
	{
		head = new stack;
		tail = head;
		head->data = value;
		head->next = nullptr;
	}
	else
	{
		stack *temp = new stack;
		temp->next = nullptr;
		temp->data = value;
		tail->next = temp;
		tail = temp;	
	}
}

void Queue::clear() //удаление элемента
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
    tail = nullptr;
}

void Queue::print()
{
	stack *ptr = head;
    while (ptr)
    {
        cout << ptr->data << "  ";
        ptr = ptr->next;
    }
}
