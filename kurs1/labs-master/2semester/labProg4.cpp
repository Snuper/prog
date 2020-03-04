#include <iostream>
#include <cstdlib>

using namespace std;

struct ij
{
	int i;
	int j;
};

int main() {
	int **arr[2];
	int n, m;
	cout << "Введите n: ";
	cin >> n;
	cout << "Введите m: ";
	cin >> m;
	for(int i = 0; i < 2; i++) {
		arr[i] = new int *[n];
		for(int j = 0; j < n; j++) {
			arr[i][j] = new int [m];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			arr[0][i][j] = rand() % 90 + 10;
		}
	}
	bool quit = true;
	bool z = 1;
	ij buff;
	int q = 0;
	while(quit) {
		z = !z;
		buff.i = 0;
		buff.j = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(arr[z][i][j] > arr[z][buff.i][buff.j]) {
					buff.i = i;
					buff.j = j;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << arr[z][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		delete [] arr[!z];
		n--;
		m--;
		arr[!z] = new int *[n];
		for(int j = 0; j < n; j++) {
			arr[!z][j] = new int [m];
		}
		for(int i = 0, k = 0; i < n; i++, k++) {
			if(i == buff.i) k++;
			for(int j = 0, f = 0; j < m; j++, f++) {
				if(j == buff.j) f++;
				arr[!z][i][j] = arr[z][k][f];
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout << arr[!z][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		cout << "Введите 1 для выхода: ";
		cin >> q;
		if(q == 1) quit = false;
	}
}