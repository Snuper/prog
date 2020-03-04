#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

const int N = 3;

struct Hostel {
	int number_of_room;
	double squad_of_room;
	string faculty;
	int number_of_residents;
	int number_of_faculty;
};

Hostel mas[N];

int main () {
	cout << "Input hostel's info: \n";
	for (int i = 0; i < N; i++) {
		cout << "Number of room: ";
		cin >> mas[i].number_of_room;
		cout << "Squad of room: ";
		cin >> mas[i].squad_of_room;
		cout << "Faculty: ";
		cin >> mas[i].faculty;
		cout << "Number of residents: ";
		cin >> mas[i].number_of_residents;
	}

	int k = 0;
	for (int j = 0; j < N - 1; j++) {
		for (int i = 1; i < N; i++) {
			if (mas[j].faculty != mas[i].faculty) {
				k++;
			}
		}
	}

	string *unical = new string[k];
	int *sum_room = new int[k];
	int *sum_residents = new int[k];
	float *area = new float[k];
	for (int i = 0; i < k; i++) {
		sum_room[i] = 0;
		sum_residents[i] = 0;
		area[i] = 0;
	}

	int  q = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)
			if (mas[j].faculty != mas[i].faculty) {
				unical[q] = mas[i].faculty;
			}
		q++;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < N; j++) {
			if (unical[i] == mas[j].faculty) {
				sum_room[i]++;
				sum_residents[i] += mas[j].number_of_residents;
				area[i] += mas[j].squad_of_room;
			}

		}
	}
	cout << endl;
	for (int i = 0; i < k; i++) {
		cout << unical[i] << " faculty has: ";
		cout << sum_room[i] << " rooms," << endl;
		cout << sum_residents[i] << " residents and on average per person" << endl;
		cout << area[i] / sum_residents[i] << " square meters \n" << endl;
	}


	cin.get ();
	return 0;
}
