#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	float *buf = 0;
	cout << "Введите коллиество элементов: ";
	cin >> n;
	float *a = new float [n];
	for(int i = 0; i < n; i++) {
		a[i] = rand() % (50*10) * 0.1;
	}
	float **b = new float *[n];
	for(int i = 0; i < n; i++) {
		b[i] = &a[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-1; j++) {
			if(*b[j] > *b[j+1]) {
				buf = b[j];
				b[j] = b[j+1];
				b[j+1] = buf;
			}
		}
	}
	cout << endl << "Неотсортерованный массив: " << endl;
	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl << "Отсортированный массив: " << endl;
	for(int i = 0; i < n; i++) {
		cout << *b[i] << " ";
	}
}