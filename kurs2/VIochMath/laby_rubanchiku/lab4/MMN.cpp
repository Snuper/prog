#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
const int N = 3;
double F0(double *x, double *y){
	y[0] = x[0] * x[0] + x[1] * x[1] + x[2] * x[2] - 1;
	y[1] = 2 * x[0] * x[0] + x[1] * x[1] - 4 * x[2];
	y[2] = 3 * x[0] * x[0] - 4 * x[1] + x[2] * x[2];
}

double W_(double **arr, double *x){
	arr[0][0] = 2 * x[0];
	arr[0][1] = 2 * x[1];
	arr[0][2] = 2 * x[2];
	arr[1][0] = 4 * x[0];
	arr[1][1] = 2 * x[1];
	arr[1][2] = -4;
	arr[2][0] = 6 * x[0];
	arr[2][1] = -4;
	arr[2][2] = 2 * x[2];
}


int main(){
	double *x = new double[N];
	double *xk = new double[N];
	double *y = new double[N];
	double *t = new double[N];
	double **W = new double *[N];
	
	double WT[N][N], WO[N][N];
	double eps = 1e-8;
	double det = 0;
	for (int i = 0, j = 0; i < N; i ++, j ++){
		W[i] = new double[N];
		for (int j = 0; j < N; j ++){
			W[i][j] = 0;
			//cout << W[i][j] << " ";
		}
		x[i] = 0.5;
		t[i] = 0;
		xk[i] = 0;
		cout << "x[" << i << "] = " << x[i] << endl;
	}
	int k = 1;
	while(fabs(x[0] - xk[0]) >= eps || fabs(x[1] - xk[1]) >= eps || fabs(x[2] - xk[2]) > eps){
		cout << "---------Step = " << k << "-----------"<< endl;
		W_(W, x);
		det = W[0][0] * (W[1][1] * W[2][2] - W[2][1] * W[1][2]) + W[1][0] * (W[2][1] * W[0][2] - W[0][1] * W[2][2]) + W[2][0] * (W[0][1] * W[1][2] - W[1][1] * W[0][2]);
		//cout << "--------------------" << endl;
		cout << "det = " << det << endl;
		F0(x, y);
		for (int i = 0; i < N; i ++){
			//cout << "y[" << i << "] = " << y[i] << endl;
			printf("y[%d] = %3.6f\n", i, y[i]);
		}
		for (int i = 0; i < N; i ++){
			for (int j = 0; j < N; j ++){
				WT[i][j] = W[j][i];
				cout << WT[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "______________WO_____________ " << endl;
		for (int i = 0; i < N; i ++){
			for (int k = 0, h = 0, p = 0, q = 0, j = 0; j < N; j ++){
				if (i == 1) {
					k = 0;
					h = 2;
				} else {
					k = (i + 1) % N;
					h = k + 1;
				}
				if(j == 1){
					p = 0;
					q = 2;
				} else {
					p = (j + 1) % N;
					q = p + 1;
				}
				WO[i][j] = pow(-1, 2 + i + j) * (WT[k][p] * WT[h][q] - WT[k][q] * WT[h][p]);
				WO[i][j] /= det;
				cout << WO[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "_______________________________"<< endl;
		for (int i = 0; i < N; i ++){
			for (int j = 0; j < N; j ++){

				t[i] += WO[i][j] * y[j];
			}
			//printf("t[%d] = %3.10f\n", i, t[i]);
		}
		
		for (int i = 0; i < N; i ++){
			xk[i] = x[i];
			x[i] = x[i] - t[i];
			t[i] = 0;
			printf("x[%d] = %3.10f\n", i, x[i]);
		}
		k ++;
	}
	return 0;
}
