#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <time.h>
int random (int N) { return rand()%N; }
void printArray(int **array, int m, int n);

int main() {

    int m, n,sum=0;
  printf("m= ");
  scanf("%d", &m);
  printf("n= ");
  scanf("%d", &n);

    int **arrayB = new int *[m];

    for (int i = 0; i < m; ++i) arrayB[i] = new int[n];
srand(time(NULL));
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    arrayB[i][j] = rand() % 10;
    printArray(arrayB, m, n);

    int **arrayC = new int *[m + 1];

    for (int i = 0; i < m + 1; ++i) arrayC[i] = new int[n + 1];

    
    for (int i = 0; i < m + 1; i++)
        for (int j = 0; j < n + 1; j++)
            arrayC[i][j] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arrayC[i][j] = arrayB[i][j];
            arrayC[m][j] += arrayC[i][j];
            arrayC[i][n] += arrayC[i][j];
            arrayC[m][n]+=arrayB[i][j];
        }
    }
    
    printf("\n");
    printArray(arrayC, m + 1, n + 1);


    for (int i = 0; i < m; ++i) delete[] arrayB[i];
    delete[] arrayB;
    for (int i = 0; i < m + 1; ++i) delete[] arrayC[i];
    delete[] arrayC;
    puts("\n");
system("PAUSE");
    return 0;
}

void printArray(int **array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", array[i][j]);
        printf("\n");
    }
}



