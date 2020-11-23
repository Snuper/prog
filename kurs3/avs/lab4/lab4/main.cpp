#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

double timeStart;
double timeCounter;

void BenchTimer(string task)
{
    if (task == "START")
        timeStart = clock();

    else if(task == "STOP")
        timeCounter = ((double)(clock() - timeStart)) / CLOCKS_PER_SEC;
}

void random_all(double** aMatrix, double** bMatrix, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            aMatrix[i][j] = rand()%100;
            bMatrix[i][j] = rand()%100;
        }
    }
}

void show(double** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double MultipicMatrix(double** aMatrix, double** bMatrix, int size, int x_pos, int y_pos)
{
    double res = 0;
    int i = 0, j = 0;

    while (i < size)
    {
        res += aMatrix[x_pos][i] * bMatrix[j][y_pos];
        i++;
        j++;
    }

    return res;
}

void DGEMM_BLAS(double** aMatrix, double** bMatrix, double** resMatrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            resMatrix[i][j] = MultipicMatrix(aMatrix, bMatrix, size, i, j);
        }
    }
}

void DGEMM_opt1(double** A , double** B, double** C, int size)
{
    double r;

    for (int i = 0; i < size; i++)
        for (int k = 0; k < size; k++)
        {
            r = A[i][k];
            for (int j = 0; j < size; j++)
                C[i][j] += r*B[k][j];
        }
}

int main()
{
    int n = 1000;
    double** A = new double* [n];
    double** B = new double* [n];
    double** R = new double* [n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
        B[i] = new double[n];
        R[i] = new double[n];
    }

    random_all(A, B, n);
    BenchTimer("START");
//    DGEMM_BLAS(aMatrix, bMatrix, resMatrix, size);
    DGEMM_opt1(A, B, R, n);
    BenchTimer("STOP");
    cout << setprecision(15) << "Time = " << timeCounter << endl;

    delete [] A;
    delete [] B;
    delete [] R;

    return 0;
}
