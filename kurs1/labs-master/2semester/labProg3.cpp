#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n = 0, k = 0, m = 0;
	cout << "Введите колличество элементов: ";
	cin >> n;
	int * b =(int *) malloc(n*(sizeof(int)));
	for(int i = 0; i < n; i++) {
		b[i] = -50 + rand() % 100;
	}
	for(int i = 0; i < n; i++) {
		if(b[i] < 0) k++;
		else m++;
	}
	int *c = (int *) malloc(m*sizeof(int));
	int *d = (int *) malloc(k*sizeof(int));
	for(int i = 0, j = 0, p = 0; i < n; i++) {
		if(b[i] < 0) {
			d[j] = b[i];
			j++;
		}
		else {
			c[p] = b[i];
			p++;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl << "Положительные числа: " << endl;
	for(int i = 0; i < m; i++) {
		cout << c[i] << " ";
	}
	cout << endl << "Отрицательные числа: " << endl;
	for(int i = 0; i < k; i++) {
		cout << d[i] << " ";
	}
	free(b);
	free(c);
	free(d);
	b = 0;
	c = 0;
	d = 0;
}