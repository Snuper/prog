#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*Написать функцию, которая вычисляет для двумерного массива 
с переменной длинной строк сумму элементов  каждой строки. 
Длинна каждой строки хранится в 0 элементе соответствующей строки. 
Массив сформировать с помощью случайных чисел, и вывести на экран 
в главной программе.*/

void GenerArr(int **arr, int n, int max);

void SumLine(int *sum, int **arr, int n);

int SumLine2(int *arr);

int main() {
	srand(time(0));
	int n = 10;
	int *array[n];
	int sum[n];
	GenerArr(array, n, 100);
	SumLine(sum, array, n);
	for(int i = 0; i < n; i++) {
		cout << "Сумма элементов " << i + 1 << " строки: " << sum[i] << endl;
	}
	cout << endl;
	for(int i = 0; i < n; i++) {
		cout << "Сумма элементов " << i + 1 << " строки: " << SumLine2(array[i]) << endl;
	}
}


void GenerArr(int **arr, int n, int max){
	int k = 1;
	for(int i = 0; i < n; i++) {
		k = 1 + rand() % (max - 1);
		arr[i] = new int [k];
		arr[i][0] = k;
		for(int j = 1; j < arr[i][0]; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void SumLine(int *sum, int **arr, int n){
	for(int i = 0; i < n; i++) {
		sum[i] = 0;
		for(int j = 1; j < arr[i][0]; j++) {
			sum[i] += arr[i][j]; 
		}
	}
}

int SumLine2(int *arr) {
	int sum = 0;
	for(int j = 1; j < arr[0]; j++) {
		sum += arr[j];
	}
	return sum;
}