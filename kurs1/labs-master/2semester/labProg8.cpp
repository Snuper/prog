#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

/*Дана информация о комнатах в общежитии. Запись имеет вид: 
номер комнаты, площадь комнаты, факультет, количество проживающих. 
Вывести данные по факультетам о  количестве комнат, 
количестве студентов и средней площади на одного студента. 
Названия и количество факультетов заранее не известны  
(их можно занести в отдельный массив по введенным данным).*/

struct dorm{
	int number; //номер комнаты
	int area; //площадь
	char *fac; //название факультета
	int quant; //кол-во студентов
};

void GenerationDorn(dorm *arr, int n);

void InputFaculty(char *&arr);

void AllocationFaculty(char *arr1, char *&arr2);

void PrintFaculty(char *arr);

int Raspredelenie(dorm **&arr, dorm *arr1, int n);

int CalcStudent(dorm *arr);

int CalcMidArea(dorm *arr);

int main() {
	srand(time(NULL));
	int n = 3;
	dorm mass[n];
	GenerationDorn(mass, n);
	int nfac = 0;
	for(int i = 0; i < n; i++) {
		cout << i+1 << "." << endl;
		cout << "Номер комнаты: " << mass[i].number << endl;
		cout << "Площадь комнаты: " << mass[i].area << endl;
		cout << "Факультет: ";
		PrintFaculty(mass[i].fac);
		cout << endl;
		cout << "Кол-во проживающих: " << mass[i].quant << endl;
	}
	dorm **mass2;
	nfac = Raspredelenie(mass2, mass, n);
	cout << nfac << endl;
	for(int i = 0; i < nfac; i++) {
		cout << "Факультет: ";
		PrintFaculty(mass2[i][1].fac);
		cout << endl << "Кол-во комнат: " << mass2[i][0].number << endl;
		cout << "Кол-во студентов: " << CalcStudent(mass2[i]) << endl;
		cout << "Средняя площадь на одного студента: " << CalcMidArea(mass2[i]) << endl;
	}


}

void GenerationDorn(dorm *arr, int n) {
	char **facult;
	int m;
	cout << "Введите кол-во факультетов: ";
	cin >> m;
	facult = new char *[m+1]; 
	for(int i = 0; i <= m; i++) {
		if (i) cout << "Введите " << i << " факультет: ";
		InputFaculty(facult[i]);
	}
	for(int i = 0; i < n; i++) {
		arr[i].number = ((1 + rand() % 8) * 100) + rand() % 21;
		arr[i].area = 10 + rand() % 15;
		AllocationFaculty(facult[1 + rand() % m], arr[i].fac);
		arr[i].quant = 2 + rand() % 3;
	}
}

void InputFaculty(char *&arr) {
	char mass[100];
	int quit = true;
	for(int i = 0; i < 100 && quit; i++) {
		mass[i] = getchar();
		if(mass[i] == '\n') quit = false;
	}
	AllocationFaculty(mass, arr);
}

void AllocationFaculty(char *arr1, char *&arr2) {
	int k = 0;
	for(int i = 0; !k; i++) {
		if(arr1[i] == '\n') k = i + 1;
	}
	arr2 = new char [k];
	for(int i = 0; i < k; i++) {
		arr2[i] = arr1[i];
	}
}

void PrintFaculty(char *arr) {
	for(int i = 0; arr[i] != '\n'; i++) cout << arr[i];
}

int Raspredelenie(dorm **&arr, dorm *arr1, int n) {
	int other = 0;
	arr = new dorm *[n];
	bool quit = true, quit2;
	int count;
	int result;
	for(int h = 0; h < n; h++) {
		count = 0;
		for(int i = 0; i < n; i++) {
			if(!strcmp(arr1[other].fac, arr1[i].fac)) count++;
		}
		arr[h] = new dorm [count+1];
		arr[h][0].number = count + 1;
		count = 1;
		for(int i = 0; i < n; i++) {
			if(!strcmp(arr1[other].fac, arr1[i].fac)) {
				arr[h][count] = arr1[i];
				count++;
			}
		} 
		quit2 = false;
		for(int i = 0; i < n && !quit2; i++) {
			quit = false;
			for(int j = 0; j <= h; j++) {
				if(!strcmp(arr1[i].fac, arr[j][1].fac)) quit = true;
			}
			if(!quit) {
				other = i;
				quit2 = true;
			}
		}
		cout << h << " " << count << " " << other << endl;
		if(!quit2) return h+1;
	}
}

int CalcStudent(dorm *arr) {
	int result = 0;
	for(int i = 1; i < arr[0].number; i++) {
		result += arr[i].quant;
	}
	return result;
}

int CalcMidArea(dorm *arr) {
	double result = 0;
	int nquant = 0;
	int narea = 0;
	for(int i = 1; i < arr[0].number; i++) {
		narea += arr[i].area;
		nquant += arr[i].quant;
	}
	return narea/nquant;
}