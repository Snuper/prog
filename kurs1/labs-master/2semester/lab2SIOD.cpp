#include <iostream>
#include "funk.h"

using namespace std;

void SelectSort(int a[], int n, int &c, int &m);

void EquateArray(int array1[],int array2[],int n);

void SelectSortUpdate(int a[], int n, int &c, int &m);

int main() {
	cout << "1. Функция сортировки массива по методу SelectSort:" << endl;
	cout << "void SelectSort(int a[], int n, int &c, int &m) {" << endl << 	"	int buff, b;" << endl << "	for(int i = 0; i < n-1; i++) {" << endl << "		b = i;" << endl << "		for(int j = i+1; j < n; j++) {" << endl << "			if(a[b] > a[j]) {" << endl << "				b = j;" << endl << "			}" << endl << "			c++;" << endl << "		}" << endl << "		buff = a[i];" << endl << "		a[i] = a[b];" << endl << "		a[b] = buff;" << endl << "		m+=3;" << endl << "	}" << endl << "}" << endl;
	const int n = 10;
	int arr[n];
	int c = 0, m = 0, c_ar_in = 0, m_ar_in = 0, c_ar_de = 0, m_ar_de = 0, c_ar_rand = 0, m_ar_rand = 0;
	cout << endl << "2.Проверка правильности сортировки:" << endl;
	FillRand(arr, n);
	PrintMas(arr, n);
	cout << "Контрольная сумма: " << CheckSum(arr, n) << endl;
	cout << "Число серий: " << RunNumber(arr, n) << endl;
	SelectSort(arr, n, c, m);
	PrintMas(arr, n);
	cout << "Контрольная сумма: " << CheckSum(arr, n) << endl;
	cout << "Число серий: " << RunNumber(arr, n) << endl;
	cout << endl << "3.Подсчет фактического кол-ва пересылок и сравнений" << endl;
	cout << "Число пересылок: " << m << endl;
	cout << "Теоретическое число пересылок по формуле M = 3(n-1): " << 3*(n - 1) << endl;
	cout << "Число сравнений: " << c << endl;
	cout << "Теоретическое сравнений по формуле C = (n^2 - n)/2: " << (n*n-n)/2 << endl;
	int array_in[n]/*Возрастающий массив*/, array_de[n]/*Убывающий массив*/, array_rand[n]/*Случайный массив*/;
	FillRand(array_rand, n);
	EquateArray(array_in, array_rand, n);
	EquateArray(array_de, array_rand, n);
	FillInc(array_in, n);
	FillDec(array_de, n);
	SelectSort(array_in, n, c_ar_in, m_ar_in);
	SelectSort(array_de, n, c_ar_de, m_ar_de);
	SelectSort(array_rand, n, c_ar_rand, m_ar_rand);
	bool b_c_ar, b_m_ar, b_RunNumber, b_CheckSum;
	cout << endl << "4.Зависимость метода от исходной упорядоченности массива:" << endl;
	if(b_CheckSum = (CheckSum(array_in, n) == CheckSum(array_de, n) && CheckSum(array_de, n) == CheckSum(array_rand, n))) cout << "Контрольная сумма не зависит" << endl;
	else {
		cout << "Контрольная сумма зависит" << endl;
		cout << "Контрольная сумма рандомного массива: " << CheckSum(array_rand, n) << endl;
		cout << "Контрольная сумма убывающего массива: " << CheckSum(array_de, n) << endl;
		cout << "Контрольная сумма возрастающего массива: " << CheckSum(array_in, n) << endl;
	}
	if(b_RunNumber = (RunNumber(array_in, n) == RunNumber(array_de, n) && RunNumber(array_de, n) == RunNumber(array_rand, n))) cout << "Число серий не зависит" << endl;
	else {
		cout << "Число серий зависит" << endl;
		cout << "Число серий рандомного массива: " << RunNumber(array_rand, n) << endl;
		cout << "Число серий убывающего массива: " << RunNumber(array_de, n) << endl;
		cout << "Число серий возрастающего массива: " << RunNumber(array_in, n) << endl;
	}
	if(b_m_ar = (m_ar_in == m_ar_de && m_ar_de == m_ar_rand)) cout << "Число пересылок не зависит" << endl;
	else {
		cout << "Число пересылок зависит" << endl;
		cout << "Число пересылок рандомного массива: " << m_ar_rand << endl;
		cout << "Число пересылок убывающего массива: " << m_ar_de << endl;
		cout << "Число пересылок возрастающего массива: " << m_ar_in << endl;
	}
	if(b_c_ar = (c_ar_in == c_ar_de && c_ar_de == c_ar_rand)) cout << "Число сравнений не зависит" << endl;
	else {
		cout << "Число сравнений зависит" << endl;
		cout << "Число сравнений рандомного массива: " << c_ar_rand << endl;
		cout << "Число сравнений убывающего массива: " << c_ar_de << endl;
		cout << "Число сравнений возрастающего массива: " << c_ar_in << endl;
	}
	if(b_CheckSum && b_RunNumber && b_m_ar && b_c_ar) cout << "Метод SelectSort не зависит от исходной упорядоченности." << endl;
	else cout << "Метод SelectSort зависит от исходной упорядоченности." << endl;
	c = 0, m = 0, c_ar_in = 0, m_ar_in = 0, c_ar_de = 0, m_ar_de = 0, c_ar_rand = 0, m_ar_rand = 0;
	cout << endl <<  "Дополнительное задание на 5+." << endl << "Функция сортировки массива улучшеным методом SelectSort:" << endl;
	cout << "void SelectSort(int a[], int n, int &c, int &m) {" << endl << 	"	int buff, b;" << endl << "	for(int i = 0; i < n-1; i++) {" << endl << "		b = i;" << endl << "		for(int j = i+1; j < n; j++) {" << endl << "			if(a[b] > a[j]) {" << endl << "				b = j;" << endl << "			}" << endl << "			c++;" << endl << "		}" << endl << "		if(a[i] != a[b]) {"  << endl << "			buff = a[i];" << endl << "			a[i] = a[b];" << endl << "			a[b] = buff;" << endl << "			m+=3;" << endl << "		}" << endl << "	}" << endl << "}" << endl;
	FillRand(array_rand, n);
	EquateArray(array_in, array_rand, n);
	EquateArray(array_de, array_rand, n);
	FillInc(array_in, n);
	FillDec(array_de, n);
	SelectSortUpdate(array_in, n, c_ar_in, m_ar_in);
	SelectSortUpdate(array_de, n, c_ar_de, m_ar_de);
	SelectSortUpdate(array_rand, n, c_ar_rand, m_ar_rand);
	cout << "Зависимость метода от исходной упорядоченности массива:" << endl;
	if(b_CheckSum = (CheckSum(array_in, n) == CheckSum(array_de, n) && CheckSum(array_de, n) == CheckSum(array_rand, n))) cout << "Контрольная сумма не зависит" << endl;
	else {
		cout << "Контрольная сумма зависит" << endl;
		cout << "Контрольная сумма рандомного массива: " << CheckSum(array_rand, n) << endl;
		cout << "Контрольная сумма убывающего массива: " << CheckSum(array_de, n) << endl;
		cout << "Контрольная сумма возрастающего массива: " << CheckSum(array_in, n) << endl;
	}
	if(b_RunNumber = (RunNumber(array_in, n) == RunNumber(array_de, n) && RunNumber(array_de, n) == RunNumber(array_rand, n))) cout << "Число серий не зависит" << endl;
	else {
		cout << "Число серий зависит" << endl;
		cout << "Число серий рандомного массива: " << RunNumber(array_rand, n) << endl;
		cout << "Число серий убывающего массива: " << RunNumber(array_de, n) << endl;
		cout << "Число серий возрастающего массива: " << RunNumber(array_in, n) << endl;
	}
	if(b_m_ar = (m_ar_in == m_ar_de && m_ar_de == m_ar_rand)) cout << "Число пересылок не зависит" << endl;
	else {
		cout << "Число пересылок зависит" << endl;
		cout << "Число пересылок рандомного массива: " << m_ar_rand << endl;
		cout << "Число пересылок убывающего массива: " << m_ar_de << endl;
		cout << "Число пересылок возрастающего массива: " << m_ar_in << endl;
	}
	if(b_c_ar = (c_ar_in == c_ar_de && c_ar_de == c_ar_rand)) cout << "Число сравнений не зависит" << endl;
	else {
		cout << "Число сравнений зависит" << endl;
		cout << "Число сравнений рандомного массива: " << c_ar_rand << endl;
		cout << "Число сравнений убывающего массива: " << c_ar_de << endl;
		cout << "Число сравнений возрастающего массива: " << c_ar_in << endl;
	}
	if(b_CheckSum && b_RunNumber && b_m_ar && b_c_ar) cout << "Улучшенный метод SelectSort не зависит от исходной упорядоченности." << endl;
	else cout << "Улучшенный метод SelectSort зависит от исходной упорядоченности." << endl;
}
void SelectSort(int a[], int n, int &c, int &m) {
	int buff, b;
	for(int i = 0; i < n-1; i++) {
		b = i;
		for(int j = i+1; j < n; j++) {
			if(a[b] > a[j]) {
				b = j;
			}
			c++;
		}
		buff = a[i];
		a[i] = a[b];
		a[b] = buff;
		m+=3;
	}
}
void EquateArray(int array1[],int array2[],int n) {
	for(int i = 0; i < n; i++) {
		array1[i] = array2[i];
	}
}
void SelectSortUpdate(int a[], int n, int &c, int &m) {
	int buff, b;
	for(int i = 0; i < n-1; i++) {
		b = i;
		for(int j = i+1; j < n; j++) {
			if(a[b] > a[j]) {
				b = j;
			}
			c++;
		}
		if(a[i] != a[b]) {
			buff = a[i];
			a[i] = a[b];
			a[b] = buff;
			m+=3;
		}
	}
}
