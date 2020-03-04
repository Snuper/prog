#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

class Queue : public List
{
	public:
		Queue();
        void push(int value);
        void clear();
        void print();
        
	private:
		stack *head; 
		stack *tail; 
};

#endif
