#ifndef STACK_H
#define STACK_H

#include "list.h"

class Stack : public List
{
    public:
        Stack();
        void push(int vall);
        void clear();
        void print();
        void printNeed(int x);
};

#endif
