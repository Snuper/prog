#include <stdio.h>
#include <stdlib.h>
const int n=5; // количество элементов в строке
typedef int rown[n];//rown - новый тип: массив (строка) из n целых чисел
//typedef int rown2[n];

main()
{
 int i,j,i1,j1,m,g=-9999,g1,g2;
 rown *a; // указатель на строку
 rown *b;
 
 printf ( "Число строк?  ");
 scanf ( "%d", &m );
 a = new rown[m]; // выделяем память под матрицу по адресу a, m строк
                                // по n элементов в строке 
if ( a == NULL ) 
{   printf("Не удалось выделить память");
    return 1; // выход по ошибке, код ошибки 1
}
b=new rown[m-1]; // выделяем память под массив сумм строк (m строк)
if ( b == NULL ) 
{   printf("Не удалось выделить память");
    return 1; // выход по ошибке, код ошибки 1
}


  for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
    { a[i][j]=rand()%11;
      printf("%4d",a[i][j]);
      if(a[i][j]>g){
      	g=a[i][j];
      	g1=i;
      	g2=j;
	  }
    }
    puts("\n");
 } 

i1=0;
j1=0;

for (i=0; i<m; i++){
for (j=0; j<n; j++){
	if(i!=g1 and j!=g2){
		b[i1][j1]=a[i][j];
		j1++;
	}
}
if(i!=g1) i1++;
j1=0;
}


 puts("\n");
for (i=0; i<m-1; i++){
for (j=0; j<n-1; j++)
	printf("  %d  ",b[i][j]);    
puts("\n");
}
 delete a; // освобождаем память, занятую под матрицу a
 delete b; // освобождаем память, занятую под массив b  
 puts("\n");
 system("PAUSE");
 return 0;
}

