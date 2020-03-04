#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int random (int N) { return rand() % N; }

const int n=1000;

void SS(int **a, int);


main ()
{ 
int i,j,m,n1;
int **a;

 printf ( "Строки - ");
 scanf ( "%d", &n1 );
a = new int*[n];
 for (int i = 0; i < n1; i++){
 		m= rand()%5;
        a[i] = new int [m+1];
        a[i][0]=m;
        m=0;
    }

if ( a == NULL ) 
{   printf("Не удалось выделить память");
    return 1; 
}

for (i=0; i<n1; i++){
  for (j=1; j<=a[i][0]; j++) 
	 a[i][j]=rand()%20;
	 }
    
for (i=0; i<n1; i++){
  for (j=0; j<=a[i][0]; j++) printf("%d  ",a[i][j]);
  printf("\n");}

printf("\n");

SS(a,n1);
  
  getch();
  return 0;
}  

void SS(int **A, int n){
	int i,j,s=0;
	for (i=0; i<n; i++){
  		for (j=1; j<=A[i][0]; j++) 
	  		s+=A[i][j];
  		printf("%d \n", s);
          s=0;}

}



