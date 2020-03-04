#include <iostream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctime>

using namespace std;

int m; 
int table[100]; 
int n; 
int a[100]; 
bool overflow; 
int collisions; 
int HashF(int num) {
	return num % m;
}
void CreateTable1() {
	int i;
	for (i = 0; i < m; i++) 
		table[i] = 0;
	
	collisions = 0;
	
	int h, h0, g;
	for (i = 0; i < n; i++) {
		h = HashF(a[i]);
		h0 = h;
		g = 1;
		
		while (1) {
			if (table[h] == a[i]) 
				break;
			
			if (table[h] == 0) { 
				table[h] = a[i];
				break;
			}
			if (g >= m) { 
				overflow = true;
				return;
			}
			collisions++;
			h = h0 + g;
			
			if (h >= m)
				h -= m;
			
			g++;
		}
	}
	overflow = false;
}
void CreateTable2() {
	int i;
	for (i = 0; i < m; i++) 
		table[i] = 0;
		
  	collisions = 0;
  	
	int h, d;
	for (i = 0; i < n; i++) {
		h = HashF(a[i]);
		d = 1;
		
		while (1) {
			if (table[h] == a[i])
				break;
			
			if (table[h] == 0) {
				table[h] = a[i];
				break;
			}
			if (d >= m) {
				overflow = true;
				return;
			}
			
			collisions++;
			h += d;
			
			if (h >= m)
				h -= m;
				
			d += 2;
		}
	}
	overflow = false;
}

void ShowTable() {
	if (m == 11) {
		printf("-----------------------------------------------------------------------\n");
		printf("| Номер ячейки |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 |\n");
		printf("-----------------------------------------------------------------------\n");
		printf("| Число        | ");
		
		for (int i = 0; i < m; i++)
			if (table[i] != 0)
				printf("%2d | ", table[i]);
		else
			printf("   | ");
			
		std::cout << endl;
		printf("-----------------------------------------------------------------------\n");
	}
	if (!overflow)
		printf("Переполнения таблицы не было\n");
	else
		printf("Возникло переполнение таблицы\n");
		
	printf("Количество коллизий: ");
	std::cout << collisions << endl;
} 
bool Search1(int num) {
	int h, h0, g;
	h = HashF(num);
	h0 = h;
	g = 1;
	while (1) {
		if (table[h] == num) 
			return true;
		if (g >= m)
			return false;
			
		h = h0 + g;
		if (h >= m)
			h -= m;
			
		g++;
	}
}
bool Search2(int num) {
	int h, d;
	h = HashF(num);
	d = 1;
	while (1) {
		if (table[h] == num) 
			return true;
		if (d >= m) 
			return false;
			
		h += d;
		if (h >= m)
			h -= m;
			
		d += 2;
	}
}
int main() {
	setlocale(LC_ALL,"Russian");
	srand(time(NULL));
	
	printf("Введите размер хеш-таблицы: ");
	cin >> m;
	
	printf("Введите количество исходных чисел: ");
	cin >> n;
	
	int num; 
	
	int i;
	for (i = 0; i < n; i++) 
		a[i] = rand() % n + 1;
	
	printf("Метод линейных проб:\n");
	
	CreateTable1();
	ShowTable();
	
	printf("Введите число для поиска: ");
	cin >> num;
	
	if (Search1(num))
		printf("Число найдено\n");
	else
		printf("Число не найдено\n");
	
	printf("\nМетод квадратичных проб:\n");
	
	CreateTable2();
	ShowTable();
	
	printf("Введите число для поиска: ");
	cin >> num;
	
	if (Search2(num))
		printf("Число найдено\n");
	else
		printf("Число не найдено\n");
	
	getch();
	return 0;
}
