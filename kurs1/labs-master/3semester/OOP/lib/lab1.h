#ifndef OOP_LAB1_H
#define OOP_LAB1_H
#include <iostream>
#include <stdlib.h>

class Arr {
	public:
		Arr(int);
		~Arr();
		void rand_arr();
		int* operator[] (int);
		int size_arr();
		int* a();
		int* b();
		int* c();
		int* d();
		void print_arr();
	private:
		int **arr;
		int n;
};

template <class T>
class ArrArbitary {
	public:
		ArrArbitary(int);
		~ArrArbitary();
		void inputSizeLine();
		void randSizeLine();
		void inputElem();
		void randElem();
		int sizeLine(int);
		void printLine(int);
		void printArr();
	private:
		T **arr;
		int *size_line_arr;
		int n;
		void init_line();
};

#endif
