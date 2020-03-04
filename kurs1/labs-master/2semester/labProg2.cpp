#include <iostream>
#include <math.h>

using namespace std;

/*3. Написать рекурсивную функцию для перевода числа из десятичной
 системы счисления в двоичную.*/

float n = 0.1;

void perevod2(int ch) {
	if(ch == 0) {
		cout << 0;
		return;
	}
	if(ch == 1) {
		cout << 1;
		return;
	}
	perevod2(ch/2);
	cout << ch%2;
	return;
}


int main() {
	int chislo = 1;
	cout << "Программа переводит десятичное число в двоичное." << endl;
	while(chislo) {
		n = 0.1;
		cout << "kkВведите число(0 для выхода): ";
		cin >> chislo;
		perevod2(chislo);
	}
}


