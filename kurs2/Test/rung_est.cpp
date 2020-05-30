#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;
const int N = 2;  // WARNING!!! You can change it! Change only together with the function_Ys!!!
const double eps = 1e-4;

double function_Ys(double x, double* y)// WARNING!!! You can change it! Change only together with the const int N!!!
{ 
//	return x + y[0] + x * y[1] - y[2];
	return x * y[1] + y[0];
}

int main()
{
	double *k1, *k2, *k3, *k4, h, *temp;
	double x_start, x_end, *y;
	double *y_last;
	bool method_continue = false;
	int i, j, step = 1;
	cout << "X start : " << endl;
	cin >> x_start;
	cout << "X end : " << endl;
	cin >> x_end;
	cout << "Step : " << endl;
	cin >> h;

	k1 = new double[N];
	k2 = new double[N];
	k3 = new double[N];
	k4 = new double[N];
	y = new double[N];
	temp = new double[N];
	y_last = new double[N];

	for (i = 0; i < N; i++) {
		cout << "Input y";
		for (j = 0; j < i; j++) {
			cout << "'";
		}
		cout << " : ";
		cin >> y[i];
	}

	for (i = 0; i < N; i++) {
		y_last[i] = 0;
	}

	
	while (true) {
		while (x_start <= x_end) {
			//			cout << "_____________Step_" << step << "____________" << endl;

			for (i = 0; i < N - 1; i++) { //start count k1
				k1[i] = y[i + 1];
			}

			k1[N - 1] = function_Ys(x_start, y); //complete count k1 -------------------------

/*			cout << "___________K1____________" << endl;
			for (i = 0; i < N; i++) {
				cout << "k1[" << i << "] = " << k1[i] << endl;
			}
			cout << "________________________" << endl;
*/

			for (i = 0; i < N; i++) { //start count y for k2
				temp[i] = (y[i] + h / 2 * k1[i]);
			}

			k2[N - 1] = function_Ys(x_start + h / 2, temp);

			for (i = 0; i < N - 1; i++) {
				k2[i] = temp[i + 1];
			}  //complete count k2 -------------------------

/*
			cout << "___________K2____________" << endl;
			for (i = 0; i < N; i++) {
				cout << "k2[" << i << "] = " << k2[i] << endl;
			}
			cout << "________________________" << endl;
*/
			for (i = 0; i < N; i++) { //start count y for k3
				temp[i] = (y[i] + h / 2 * k2[i]);
			}

			k3[N - 1] = function_Ys(x_start + h / 2, temp);

			for (i = 0; i < N - 1; i++) {
				k3[i] = temp[i + 1];
			}  //complete count k3 -------------------------

/*
			cout << "___________K3____________" << endl;
			for (i = 0; i < N; i++) {
				cout << "k3[" << i << "] = " << k3[i] << endl;
			}
			cout << "________________________" << endl;
*/
			for (i = 0; i < N; i++) { //start count y for k4
				temp[i] = (y[i] + h * k3[i]);
			}


			k4[N - 1] = function_Ys(x_start + h, temp);

			for (i = 0; i < N - 1; i++) {
				k4[i] = temp[i + 1];
			}  //complete count k4 -------------------------
/*
			cout << "___________K4____________" << endl;
			for (i = 0; i < N; i++) {
				cout << "k4[" << i << "] = " << k4[i] << endl;
			}
			cout << "________________________" << endl;
*/
			for (i = 0; i < N; i++) {
				y[i] = y[i] + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
			}

			for (i = 0; i < N; i++) {
				cout << "y" << step << " [" << i << "] = " << y[i] << endl;
			}
			cout << "________________________" << endl;

			x_start += h; //for the next step
			step++;
		}

		for (i = 0; i < N; i++) {
			if (abs(y_last[i] - y[i]) > eps) {
				method_continue = true;
				break;
			}
		}

		if (method_continue) {
			for (i = 0; i < N; i++) {
				y_last[i] = y[i];
				h -= h / 2;
			}
		}
		else {
			break;
		}
		

	}
	cout << "__________Result Time!__________" << endl;

	for (i = 0; i < N; i++) {
		cout << y_last[i] << endl;
	}
					// time to clean memory
	y = NULL;
	k1 = NULL;
	k2 = NULL;
	k3 = NULL;
	k4 = NULL;
	temp = NULL;
	y_last = NULL;

	delete k1;
	delete k2;
	delete k3;
	delete k4;
	delete y;
	delete temp;
	delete y_last;

	return 0;

}
