#include <iostream>

using namespace std;

int main() {
	int m;
	cout << "Введите m: ";
	cin >> m;
	m++;
	int **arr;
	arr = new int *[m];
	arr[0] = new int [m];
	for(int i = 1; i < m; i++) {
		arr[i] = new int [i+1];
	}
	for(int i = 0; i < m; i++) {
		arr[i][0] = i;
		arr[0][i] = i;
	}
	for(int i = 1; i < m; i++) {
		for(int j = 1; j <= i; j++) {
			arr[i][j] = arr[i][0] * arr[0][j];
		}
	}
	for(int i = 0; i < m; i++) cout << arr[0][i] << " ";
	cout << endl;
	for(int i = 1; i < m; i++) {
		for(int j = 0; j <= i; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}