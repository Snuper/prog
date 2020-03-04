#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
float y (float x)
{
 float f;
 f=(2.5*x*x-0.1)/(tan(x)+sin (x));
    }
    
int main()
{setlocale(LC_CTYPE,"Russian");
int n,m,i,j,k;
double t;
//Ввод размерности массива
 float A[5] [7];
      float B [5];
         for  (int i=0; i<5,i++) {
        for int (j=0,j<7,j++){
 A [i][j]=y(i*j/2);
cout « "Введите размер массива n m" « endl;
cin » n » m;

//Выделение памяти под массив
double **A;
A=new double*[n];
for(i=0; i<n; i++)
A[i]=new double[m];

//Тут ввод массива
for (i=0; i<n; i++)
for (j=0; j<m; j++)
{
cout « "Введите A[" « i « "][" « j « "]: " ;
cin » A[i][j];
cout«endl;
}
for (i=0; i<n; i++)
{
for (j=0; j<m; j++)
cout « A[i][j] « " ";
cout « endl;
}

double max=0;

for(int j=0;j<n;j++)
{
for(int i =0;i<m;i++)
{
if ( A[j][i]> max)
max = A[j][i];
}
}
cout « "max:" « max« endl;

for (int i = 0; i < n; i++)
{
double max;
for (int j = j+1 ; j < m; j++)
{
A[i][j]=A[i][j];
}
for (i=0; i<n; i++)
{
for (j=0; j<m; j++)
cout « A[i][j] « " ";
cout « endl;
}
}


system("pause");
}
