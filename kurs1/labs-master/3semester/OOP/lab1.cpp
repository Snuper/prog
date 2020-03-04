#include "lib/lab1.h"

using namespace std;

const int N = 10;

// Задание 1. Создать динамический двумерный массив размером 200х200
// элементов, заполнить его случайными целыми числами (типа Byte).
// Переписать элементы матрицы во вновь созданный одномерный
// динамический массив в следующем порядке:
// a) по правым диагоналям, начиная с правого верхнего элемента
// b) по левым диагоналям, начиная с левого верхнего элемента
// c) по спирали, начиная с центрального элемента
// d) по спирали, начиная с левого верхнего элемента
//
// Задание 2. Создать двумерный динамический массив с произвольным
// количеством элементов в каждой сроке. Заполнить его и распечатать
// построчно.

int main() {
	Arr arr(N);
	arr.rand_arr();
	arr.print_arr();
	std::cout << arr[4][5];
	int *a = arr.d();
	for(int i = 0; i < N*N; i++) {
		cout << a[i] << endl;
	}
	cin.get();
	// ArrArbitary <int> arr(N);
	// arr.randSizeLine();
	// arr.randElem();
	// arr.printArr();
}

//class Arr

Arr::Arr(int buff_n) {
	 n = buff_n;
	 arr = new int *[n];
	 for(int i = 0; i < n; i++) {
		 arr[i] = new int [n];
	 }
}

Arr::~Arr() {
	for(int i = 0; i < n; i++) {
		delete [] arr[i];
	}
	delete [] arr;
}

void Arr::rand_arr() {
	int x = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
//			arr[i][j] = rand() % 90 + 10;
			arr[i][j] = x++;
		}
	}
}

int* Arr::operator[] (int numb1) {
	return arr[numb1];
}

int Arr::size_arr() {
	return n;
}

int* Arr::a() {
	int *arr_a;
	arr_a = new int [n*n];
	int count = 0;
	for(int i = 0; i < 2*n - 1; i++) {
		if(i < n) {
			for(int j = 0; j <= i; j++) {
				arr_a[count] = arr[j][n-(i-j)-1];
				count++;
			}
		} else {
			for(int j = i - n + 1; j < n; j++) {
				arr_a[count] = arr[j][n-(i-j)-1];
				count++;
			}
		}
	}
	return arr_a;
}

int* Arr::b() {
	int *arr_a;
	arr_a = new int [n*n];
	int count = 0;
	for(int i = 0; i < 2*n - 1; i++) {
		if(i < n) {
			for(int j = 0; j <= i; j++) {
				arr_a[count] = arr[j][i-j];
				count++;
			}
		} else {
			for(int j = i - n + 1; j < n; j++) {
				arr_a[count] = arr[j][i-j];
				count++;
			}
		}
	}
	return arr_a;
}

int* Arr::c() {
	int *arr_c;
	arr_c = new int [n*n];
	int x_accelerate = 0, y_accelerate = 1;
	int x = (n - 1) / 2, y = (n - 1) / 2;
	arr_c[0] = arr[x][y];
	int count = 1;
	for(int i = n - 2, last_x_accelerate, last_y_accelerate; i >= 0; i--) {
		for(int j = 0; j < 2 || j < 3 && i == n - 2; j++) {
			for(int k = 0; k < i + 1; k++, count++) {
				if(x < 0 || x >= n || y < 0 || y >= n) {
					std::cout << "error: " << " i = " << i << " j = " << j << " k = " << k << std::endl;
					return arr_c;
				}
				x += x_accelerate;
				y += y_accelerate;
				arr_c[count] = arr[x][y];
			}
			last_x_accelerate = x_accelerate;
			last_y_accelerate = y_accelerate;
			x_accelerate = last_y_accelerate;
			y_accelerate = -last_x_accelerate;
		}
	}
	return arr_c;
}

int* Arr::d() {
	int *arr_d;
	arr_d = new int [n*n];
	int x_accelerate = 0, y_accelerate = 1;
	int x = 0, y = 0;
	arr_d[0] = arr[x][y];
	int count = 1;
	for(int i = n - 2, last_x_accelerate, last_y_accelerate; i >= 0; i--) {
		for(int j = 0; j < 2 || j < 3 && i == n - 2; j++) {
			for(int k = 0; k < i + 1; k++, count++) {
				if(x < 0 || x >= n || y < 0 || y >= n) {
					std::cout << "error: " << " i = " << i << " j = " << j << " k = " << k << std::endl;
					return arr_d;
				}
				x += x_accelerate;
				y += y_accelerate;
				arr_d[count] = arr[x][y];
			}
			last_x_accelerate = x_accelerate;
			last_y_accelerate = y_accelerate;
			x_accelerate = last_y_accelerate;
			y_accelerate = -last_x_accelerate;
		}
	}
	return arr_d;
}

void Arr::print_arr() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

//class ArrArbitary

template <class T>
ArrArbitary<T>::ArrArbitary(int buff_n):n(buff_n) {
	arr = new T *[n];
	size_line_arr = new int [n];
	*arr = NULL;
}

template <class T>
ArrArbitary<T>::~ArrArbitary() {
	for(int i = 0; i < n; i++) {
		delete [] arr[i];
	}
	delete [] arr;
	delete [] size_line_arr;
}

template <class T>
void ArrArbitary<T>::inputSizeLine() {
	std::cout << "Пользовательский ввод каждой строки." << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << "Введите колличество элементов " << i+1 << " строки: ";
		std::cin >> size_line_arr[i];
		std::cout << std::endl;
	}
	init_line();
}

template <class T>
void ArrArbitary<T>::randSizeLine() {
	for(int i = 0; i < n; i++) {
		size_line_arr[i] = rand() % 90 + 10;
	}
	init_line();
}

template <class T>
void ArrArbitary<T>::init_line() {
	for(int i = 0; i < n; i++) {
		arr[i] = new T [size_line_arr[i]];
	}
}

template <class T>
int ArrArbitary<T>::sizeLine(int line) {
	return size_line_arr[line];
}

template <class T>
void ArrArbitary<T>::inputElem() {
	if(*arr == NULL) {
		std::cout << "Не выбрано кол-во элементов в каждой строке!";
		return;
	}
	std::cout << "Пользовательский ввод каждого элемента." << std::endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < sizeLine(i); j++) {
			std::cout << "Введите элемент N" << j << "строки N" << i;
			std::cin >> arr[i][j];
		}
	}
}

template <class T>
void ArrArbitary<T>::randElem() {
	if(*arr == NULL) {
		std::cout << "Не выбрано кол-во элементов в каждой строке!";
		return;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < sizeLine(i); j++) {
			arr[i][j] = rand() % 90 + 10;
		}
	}
}

template <class T>
void ArrArbitary<T>::printLine(int line) {
	for(int i = 0; i < sizeLine(line); i++) std::cout << arr[line][i] << " ";
	return;
}

template <class T>
void ArrArbitary<T>::printArr() {
	for(int i = 0; i < n; i++) {
		printLine(i);
		std::cout << std::endl << std::endl                                                                                     ;
	}
	return;
}
