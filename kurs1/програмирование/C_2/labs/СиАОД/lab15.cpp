#include <iostream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctime>

using namespace std;

struct Elem
{
	int num;
	Elem *next;
};

const int m = 11; 
Elem *table[m]; 

const int n = 30; 
int a[n];

int HashF(int num) {
	return num % m;
}

Elem *NewElem(int num) {
	Elem *p = new Elem;
	p->num = num;
	p->next = NULL;
	return p;
}
void CreateTable() {
	int i;
	for (i = 0; i < m; i++) 
		table[i] = NULL;
	
	for (i = 0; i < n; i++) {
		int hashF = HashF(a[i]); 
	
		if (table[hashF] == NULL) 
			table[hashF] = NewElem(a[i]); 
		else {
			Elem *p = table[hashF]; 
			int found = 0; 
		
			if (p->num == a[i]) 
				found = 1;
		
			while (!found && p->next != NULL)
				if (p->next->num == a[i])
					found = 1;
			else
				p = p->next;
			
			if (!found) 
				p->next = NewElem(a[i]);
		}
	}
}
void ShowTable() {
	printf("Хеш-таблица, построенная методом прямого связывания:\n\n");
	
	int i;
	for (i = 0; i < m; i++) {
		std::cout << i << ":";
		Elem *p = table[i]; 
		while (p != NULL) {
	  		std::cout << " -> " << p->num;
	  		p = p->next;
		}
		std::cout << endl;
	}
}
bool Search(int num) {
	int hashF = HashF(num); 
	Elem *p = table[hashF]; 
	
	while (p != NULL) {
		if (p->num == num)
			return true;
			
		p = p->next;
	}
	return false;
}

int main() {
	setlocale(LC_ALL,"Russian");
	srand(time(NULL));
	
	int i;
	for (i = 0; i < n; i++)
		a[i] = rand() % 30;
	
	CreateTable();
	ShowTable();
	
	int num;
	printf("\nВведите число для поиска: ");
	cin >> num;
	
	if (Search(num))
		printf("Число найдено");
	else
		printf("Число не найдено");
	
	getch();
	return 0;
}
