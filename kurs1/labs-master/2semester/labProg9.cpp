#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


/*1. Сформировать односвязный список, состоящий из структур, 
содержащих информацию: фамилия студента и 4 оценки. 
При формировании списка предусмотреть, чтобы он был упорядочен 
по возрастанию (по фамилии). Вывести полученный список.
2.  Найти и удалить из списка студентов, имеющих хотя бы одну 
неудовлетворительную оценку. Вывести откорректированный список.
3. Освободить память, занятую списком.*/

struct spis {
	int asess[4];
	string sec_name;
	spis *next;
};

spis *newSpis(int n) {
	spis *student = new spis;
	spis *head = student;
	head->next = 0;
		for (int j = 0; j < 4; j++) {
			head->asess[j] = 2 + rand() % 4;
		}
		cout << "Введите фамилию " << 1 <<  " студента: ";
		cin >> head->sec_name;
	for(int i = 1; i < n; i++) {
		head->next = new spis;
		head = head->next;
		head->next = 0;
		for (int j = 0; j < 4; j++) {
			head->asess[j] = 2 + rand() % 4;
		}
		cout << "Введите фамилию " << i + 1 <<  " студента: ";
		cin >> head->sec_name;
	}
	return student;
}

void printSpis(spis *student) {
	spis *head = student;
	for(;head;) {
		cout << "second name: " << head->sec_name << endl;
		for(int j = 0; j < 4; j++) {
			cout << "asessment " << j+1 << ": " << head->asess[j] << endl;
		}
		head = head->next;
	}
	return;
}

spis *delUnAsess(spis *student) {
	spis *head = student;
	spis *buff;
	while(head && head->next) {
		for(int i = 0; i < 4; i++) {
			if(head->next->asess[i] < 3) {
				buff = head->next;
				head->next = head->next->next;
				delete buff;
				i = 4;
			}
		}
		head = head->next;
	}
	for(int i = 0; i < 4; i++) {
		if(student->asess[i] < 3) {
			buff = student->next;
			delete student;
			return buff;
		}
	}
	return student;
}

int main() {
	srand(time(0));
	int n;
	cout << "Введите кол-во студентов: ";
	cin >> n;
	if(!n) return 0;
	spis *student = newSpis(n);
	printSpis(student);
	cout << endl << endl << "--------------------------------------------------" << endl;
	student = delUnAsess(student);
	printSpis(student);
	return 0;
}