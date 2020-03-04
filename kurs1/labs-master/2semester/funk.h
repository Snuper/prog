#include <cstdlib>
#include <ctime>

/*
FillInc(int a[], int n) - Сортировка методом пузырька по возрастанию.
FillDec(int a[], int n) - Сортировка методом пузырька по убыванию.
FillRand(int a[], int n) - Создание рандомного массива.
CheckSum(int a[], int n) - Подсчет контрольной суммы. Возвращает int.
RunNumber(int a[], int n) - Подсчет числа серий в массиве. Возвращает int.
PrintMas(int a[], int n) - Вывод массива.
a[] - указатель на массив, n - кол-во элементов массива
*/

using namespace std;

void FillInc(int a[], int n) {
	int buff;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1; j++) {
			if(a[j] > a[j+1]) {
				buff = a[j];
				a[j] = a[j+1];
				a[j+1] = buff;
			}
		}
	}
}
void FillDec(int a[], int n) {
	int buff;
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n - 1; j++) {
                        if(a[j] < a[j+1]) {
                                buff = a[j];
                                a[j] = a[j+1];
                                a[j+1] = buff;
                        }
                }
        }
}
void FillRand(int a[], int n) {
	srand(time(0));
	for(int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}
int CheckSum(int a[], int n) {
	int result = 0;
	for(int i = 0; i < n; i++) {
		result += a[i];
	}
	return result;
}
int RunNumber(int a[], int n) {
	int result = 1;
	for(int i = 0; i < n - 1; i++) {
		if(a[i] > a[i+1]) result++;
	}
	return result;
}
void PrintMas(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	cout << endl;
}
