#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main()
{ int m,k,j,i,c=0;
float **B; float *A; // Объявляем matr – указатель на массив указателей
system("CLS");
printf("Vvedite razmer stroki m: "); scanf("%d",&m);
A=new float[m];
if (A==NULL)
{ puts("Massiv ne sozdan!");
return 1;
}
for (i=0; i<m; i++){  // Заполнение одномерного массива
A[i]=rand()%100;
printf("%f ",A[i]);
}
printf("\n Vvedite k, k<m: "); scanf("%d",&k);
B=new float *[m]; // Выделяем память под массив указателей
if (B==NULL)
{ puts("Massiv ne sozdan!");
return 1;
}
int jjo=0;
if (m%k==0) jjo=m/k;
else jjo=m/k+1;
for (i=0; i<jjo; i++)
{ B[i]=new float[k]; // Выделяем память под i-ю строку
if (B[i]==NULL)
{ puts("Massiv ne sozdan!");
return 1;
}
for (j=0; j<k; j++){
B[i][j]=A[c];// Заполняем строку
c++;
if (c>m) B[i][j]=0;}
}
for (i=0; i<jjo; i++)
{ for (j=0; j<k; j++)
printf("\t%6.2f",B[i][j]);
printf("\n");
}
for (i=0;i<m;i++){
delete B[i]; //Освобождаем память i-й строки
B[i]=NULL;
}
delete B; // Освобождаем память массива указателей
B=NULL;
delete A; // Освобождаем память массива сумм
A=NULL;
getch();
}
