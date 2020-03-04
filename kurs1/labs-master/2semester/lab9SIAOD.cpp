#include <iostream>
#include "funk.h"
#include <iomanip>
#include <SDL2/SDL.h>
#include <math.h>
#include <algorithm>


using namespace std;

void BubleSort(int a[], int n, int &M, int &C);
void ShakerSort(int a[], int n, int &M, int &C);
void InsertSort(int a[], int n, int &M, int &C);
void ShellSort(int a[], int n, int &M, int &C);
void heapify (int pos, int arr[], int n, int &M, int &C);
void heap_make(int arr[], int n, int &M, int &C);
void HeapSort(int arr[], int n, int &M, int &C);


struct Sort{
	int M;
	int C;
};

struct Mass{
	Sort teor;
	Sort fact_in; //Возрастающий
	Sort fact_rand;
	Sort fact_de; //Убывающий
};
int main() {
	int n = 10;
	int M, C;
	int a[n];
	FillRand(a, n);
    FillInc(a, n);
	HeapSort(a, n, M, C);
	cout << endl << "1. Метод Хаора" << endl;
	cout << endl << "2. Подсчет фактического кол-ва пересылок и сравнений, сравнение с теоретическим" << endl;
	cout << endl << "Фактическое кол-во пересылок М и сравнений С:" << endl;
	cout << "C = " << C << endl << "M = " << M << endl;
	cout << "Теоретическое кол-во пересылок М и сравнений С:" << endl;
    cout << "C < 2 * n * log2(n) + n + 2 = " << 2 * n * (log10(n)/log10(2)) + n + 2 << endl;
	cout << "M < n * log2(n) + 6.5 * n - 4 = " << n * (log10(n)/log10(2)) + 6.5 * n - 4 << endl;
	cout << endl << "3. Таблица." << endl << endl;
	Mass mass[5];
	int *arr;
	cout << setw(3) << "n" << " | " << setw(15)  << "  M+C Теоретич." << " | " << setw(15) << "M+C Факт. Убыв." << " | " << setw(15) << "M+C Факт. Случ." << " | " << setw(15) << "M+C Факт. Возр."  << " | " << endl;
	for(int i = 0; i < 5; i++) {
		n = 100*(i+1);
		arr = new int [n];
		FillRand(arr, n);
		ShellSort(arr, n, mass[i].fact_rand.M, mass[i].fact_rand.C);
		FillDec(arr, n);
		ShellSort(arr, n, mass[i].fact_de.M, mass[i].fact_de.C);
		
		FillInc(arr, n);
		ShellSort(arr, n, mass[i].fact_in.M, mass[i].fact_in.C);
		mass[i].teor.M = (n*n - n)/2 + 2*n - 2;
		mass[i].teor.C = (n*n-n)/2;
		cout << setw(3) << n << " | " << setw(15) << mass[i].teor.M + mass[i].teor.C << " | " << setw(15) << mass[i].fact_de.M + mass[i].fact_de.C << " | " << setw(15) << mass[i].fact_rand.M + mass[i].fact_rand.C << " | " << setw(15) << mass[i].fact_in.M + mass[i].fact_in.C  << " | " << endl;
		delete [] arr;
	}
	/*n = 10;
	int M1 = 
	FillRand(a, n);
	ShakerSort(a, n, )*/
	SDL_Init(SDL_INIT_EVERYTHING);
	int size_window = 600;
	SDL_Window* win = SDL_CreateWindow("Grephic", 200, 200, size_window, size_window, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	bool quit;
	int i = 0;
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderClear(ren);
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderDrawLine(ren, size_window, size_window - 5, 0, size_window - 5);
	SDL_RenderDrawLine(ren, 5, 0, 5, size_window);
	quit = true;
	Sort graph;
	int x_0_shake = 0 + 5, y_0_shake = 0 + 5;
	int x_0_buble = 0 + 5, y_0_buble = 0 + 5;
	int x_0_insert = 0 + 5, y_0_insert = 0 + 5;
	int x_0_shell = 0 + 5, y_0_shell = 0 + 5;
    int x_0_heap = 0 + 5, y_0_heap = 0 + 5;
	n = 10;
	while(quit) {
		SDL_SetRenderDrawColor(ren, 0, 150, 0, 255);
		if(i < 600) {
			arr = new int [i];
			FillRand(arr, i);
			ShakerSort(arr, i, graph.M, graph.C);
			SDL_RenderDrawLine(ren, x_0_shake , y_0_shake , i+5 , size_window - ((graph.M + graph.C)/200 + 5));
			x_0_shake = i+5;
			y_0_shake = size_window - ((graph.M + graph.C)/200 + 5);
		}
		SDL_SetRenderDrawColor(ren, 0, 0, 150, 255);
		if(i < 600) {
			arr = new int [i];
			FillRand(arr, i);
			BubleSort(arr, i, graph.M, graph.C);
			SDL_RenderDrawLine(ren, x_0_buble , y_0_buble , i+5 , size_window - ((graph.M + graph.C)/200 + 5));
			x_0_buble = i+5;
			y_0_buble = size_window - ((graph.M + graph.C)/200 + 5);
		}
		SDL_SetRenderDrawColor(ren, 150, 0, 0, 255);
		if(i < 600) {
			arr = new int [i];
			FillRand(arr, i);
			InsertSort(arr, i, graph.M, graph.C);
			SDL_RenderDrawLine(ren, x_0_insert, y_0_insert, i+5, size_window - ((graph.M + graph.C)/200+5));
			x_0_insert = i+5;
			y_0_insert = size_window - ((graph.M + graph.C)/200 + 5);
		}
        SDL_SetRenderDrawColor(ren, 150, 150, 0, 255);
		if(i < 600) {
			arr = new int [i];
			FillRand(arr, i);
			ShellSort(arr, i, graph.M, graph.C);
			SDL_RenderDrawLine(ren, x_0_shell, y_0_shell, i+5, size_window - ((graph.M + graph.C)/200+5));
			x_0_shell = i+5;
			y_0_shell = size_window - ((graph.M + graph.C)/200 + 5);
		}
        SDL_SetRenderDrawColor(ren, 150, 0, 150, 255);
        if(i < 600) {
            arr = new int [i];
            FillRand(arr, i);
            HeapSort(arr, i, graph.M, graph.C);
            SDL_RenderDrawLine(ren, x_0_heap, y_0_heap, i+5, size_window - ((graph.M + graph.C)/200+5));
            x_0_heap = i+5;
            y_0_heap = size_window - ((graph.M + graph.C)/200 + 5);
        }
		i++;
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT) quit = false;
		SDL_RenderPresent(ren);
	}
	SDL_Quit();
}

void BubleSort(int a[], int n, int &M, int &C) {
	int buff = 0;
	C = 0, M = 0;
	for(int i = 0; i < n; i++) {
		for(int j = n - 1; j > 0 + i; j--) { 
			if(a[j] < a[j-1]) {
				buff = a[j];
				a[j] = a[j-1];
				a[j-1] = buff;
				M+=3;
			}
			C++;
		}
	}
}

void ShakerSort(int a[], int n, int &M, int &C){
	C = 0; M = 0;
	int  left = 0, right = n-1, k = n - 1;
	do {
		for(int j = right; j > left; j--) { 
			if(a[j] < a[j-1]) {
				swap(a[j], a[j-1]);
				M+=3;
				k = j;
			}
			C++;
		}
		left = k;
		for(int j = left; j < right; j++) {
			if(a[j] > a[j+1]) {
				swap(a[j],a[j+1]);
				M+=3;
				k = j;
			}
			C++;
		}
		right = k;
	} while(left < right);
	return;
}


void InsertSort(int a[], int n, int &M, int &C) {
	C = 0; M = 0;
	int s = 0, j;
	for(int i = 1; i < n; i++) {
		s = a[i];
		M++;
		j = i - 1;
		while(j >= 0 && a[j] > s) {
			C++;
			a[j+1] = a[j];
			M++;
			j--;
		}
		a[j+1] = s;
		M++;
	}
}

void ShellSort(int a[], int n, int &M, int &C) {
	M = 0; C = 0;
	int j,temp;
	int step = n/2;
	while(step > 0){
		for (int i = 0; i < (n-step);i++){
			j = i;
			while((j>=0) && (a[j] > a[j+step])) {
				temp = a[j];
				a[j] = a[j+step];
				a[j+step] = temp;
				M += 3;
				j -= step;
			}
			C++;
		}
		step = step/2;
	}
}


void heapify (int pos, int arr[], int n, int &M, int &C) {
    while (2 * pos + 1 < n) {
        int t = 2 * pos +1;
        if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
        {
            t = 2 * pos + 2;
        }
        C++;
        if (arr[pos] < arr[t]) {
            swap(arr[pos], arr[t]);
            M+=3;
            pos = t;
            C++;
        } 
        else {
            C++;
            break;
        }
        
    }
}

void heap_make(int arr[], int n, int &M, int &C)
{
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(i, arr, n, M, C);
    }
}
void HeapSort(int arr[], int n, int &M, int &C)
{   M = 0; C = 0;
    heap_make(arr, n, M, C);
    while(n>0)
    {
        swap(arr[0],arr[n-1]);
        M+=3;
        n--;
        heapify(0, arr, n, M, C);
    }
}
