#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>

using namespace std;
const int N = 2;
double F0(double *x, double *f){
	f[0] = x[0] * x[1] - 2.3;
	f[1] = x[0] / x[1] - 1.9;
	//cout << "****************" << endl << x[0] << endl << x[1]<< f[0] << endl << f[1] << endl << "**************"<< endl;
}

double W_(double **arr, double *x){
	//cout << x[0];
	arr[0][0] = x[1];
	//cout << arr[0][0];
	arr[0][1] = x[0];
	arr[1][0] = 1 / x[1];
	arr[1][1] = - x[0] / (x[1] * x[1]);
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
	x[0] = 2;
	x[1] = 1;
	//cout << x[0] << x[1];
	for (int i = 0; i < N; i ++){
		W[i] = new double[N];
		for (int j = 0; j < N; j ++){
			W[i][j] = 0;
			//cout << W[i][j] << " ";
		}
		///cout << endl;
		t[i] = 0;
		xk[i] = 0;
	}
	int k = 1;
	while(fabs(x[0] - xk[0]) >= eps || fabs(x[1] - xk[1]) >= eps){
		cout << "---------Step = " << k << "-----------"<< endl;
		W_(W, x);
		det = W[0][0] * W[1][1] - W[0][1] * W[1][0];
		//cout << "--------------------" << endl;
		cout << "det = " << det << endl;
		F0(x, y);
		/*for (int i = 0; i < N; i ++){
			//cout << "y[" << i << "] = " << y[i] << endl;
			printf("y[%d] = %3.6f\n", i, y[i]);
		}*/
		WO[0][0] = W[1][1];
		WO[1][1] = W[0][0];
		WO[0][1] = -W[0][1];
		WO[1][0] = -W[1][0];
		cout << "_____WO_____ " << endl;
		for (int i = 0; i < N; i ++){
			for (int j = 0; j < N; j ++){
				//cout << WO[i][j] << "\t";
				WO[i][j] /= det;
				cout << WO[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "____________"<< endl;
		for (int i = 0; i < N; i ++){
			for (int j = 0; j < N; j ++){

				t[i] += WO[i][j] * y[j];
			}
			//printf("t[%d] = %3.8f\n", i, t[i]);
		}
		
		for (int i = 0; i < N; i ++){
			xk[i] = x[i];
			x[i] = x[i] - t[i];
			t[i] = 0;
			printf("x[%d] = %3.8f\n", i, x[i]);
		}
		k ++;
	}
	return 0;
}
