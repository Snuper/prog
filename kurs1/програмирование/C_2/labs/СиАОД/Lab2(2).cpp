#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <iostream>
int random (int N) { return rand()%N; }
using namespace std;
void FillInc (int A[], int n); 
void FillDec (int A[], int n); 
void FillRand (int A[], int n); 
int CheckSum (int A[], int n); 
int RunNumber (int A[], int n); 
void PrintMas (int A[], int n); 
void SelectSort (int A[], int n);

int *A;
int Mprak = 0, Cprak = 0;
int main(){
    int n;
    cout<<"Input N: ";
    cin>>n;
    A = new int [n];
    srand(time(NULL));
    while (1){
    int ch = getch();
    switch(ch){
             case 49: cout<<"Sum = "<<CheckSum(A, n)<<endl<<"Series: "<<RunNumber(A, n)
             <<endl; break;  //1
             case 50: FillRand(A, n); break; //2
             case 51: FillInc(A, n); break; //3
             case 52: FillDec(A, n); break; //4
             case 53: PrintMas(A, n); break; //5
             case 54: cout<<"Fact: "<<endl<<"M = "<<Mprak<<endl<<"C = "<<Cprak<<endl; break; //6
             case 55: cout<<"Theor: "<<endl<<"M = "<<3 * (n - 1)<<endl<<"C = "<<(n * n - n) / 2<<endl; break; //7
             case 56: SelectSort(A, n); break; //8
             case 27: exit(0); //esc
             }
    }
    system ("PAUSE");
    return 0;
}


void FillInc (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = i+1;
}

void FillDec (int A[], int n) {
	int i;
	for ( i = 0; i < n; i ++ ) A[i] = n-i;
}

void FillRand (int A[], int n) {
	int i, a = -50, b = 50;	
	for ( i = 0; i < n; i ++ ) A[i] = random(b-a+1)+a;
}

     
int CheckSum (int A[], int n){
     int sum = 0;
     for (int i = 0; i < n; i++)
         sum += A[i];
     return sum;
     }

int RunNumber (int A[], int n){
     int sum_ser = 1;
         for (int i = 0; i < n-1; i++)
                 if (A [i] > A[i+1]){
                    sum_ser += 1;
                    }
     return sum_ser;
     }

void PrintMas (int A[], int n){
     for (int i = 0; i < n; i++)
         cout<<A[i]<<" ";
     cout<<endl;
     } 
void SelectSort (int A[], int n) 
{
	Mprak = 0, Cprak = 0;
	int i,j,min,t;
	for (i = 0; i < n-1; i++ ) { 
		min = i;
		for( j=i+1; j<n; j++){ 
			Cprak++;
	   		if (A[j]<A[min]) min=j;
	   						   
		}
		//if(min==i) continue;
		t=A[i];
		A[i]=A[min];
		A[min]=t; 
		Mprak+=3;
	}
}


