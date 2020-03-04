#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sleep(int delay) {
	int stime = time(0);
	while(time(0) < stime + delay) { }
}

void FillInc(int a[], int n);

void FillDec(int a[], int n);

void FillRand(int a[], int n);

int CheckSum(int a[], int n);

int RunNumber(int a[], int n);
vi
void PrintMas(int a[], int n);

int main() {
	setlocale(LC_ALL, "Russian");
	int const n = 10;
	int const T = 30; //точность
	int a[n];
	int middleRN = 0;
	FillRand(a, n);
	cout << "Задание 2: " << endl << endl;
	PrintMas(a, n);
	cout << "Кол-во серий в случайном массиве: " << RunNumber(a, n) << endl;
	FillInc(a, n);
	PrintMas(a, n);
	cout << "Кол-во серий в возрастающем массиве: " << RunNumber(a, n) << endl;
	FillDec(a, n);
	PrintMas(a, n);
	cout << "Кол-во серий в убывающем массиве: " << RunNumber(a, n) << endl;
	cout << "Задание 3:" << endl << endl;
	for(int i = 0; i < T; i++) {
		//sleep(1);
		srand(i+time(0));
		FillRand(a, n);
		middleRN += RunNumber(a, n);
		cout << "Серия " << i+1 << " случайного массива = " << RunNumber(a, n) << endl;
	}

	cout << "Средняя серия массива из " << T << " случайных массивов = " << (double)middleRN / T << endl;
}

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
	//srand(time(0));
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
