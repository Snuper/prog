#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

double eps = 10000;

double formula(double x)
{
    return sqrt(x);
}

double formula_et(double et_x, int n, double *x_mas, double *y_mas)
{
    double temp_ch, temp_zn, p_mas[n];

    for(int i = 0; i < n + 1; i++) p_mas[i] = y_mas[i];

    for (int i = 0, ub = 0; i < (n * n / 2) + 1; i++)
    {
        for(int j = i; j < n + ub; j++)
        {
            if(j >= n - 1) continue;

            temp_ch = p_mas[j - ub] * (et_x - x_mas[j + 1]) - p_mas[j + 1 - ub] * (et_x - x_mas[j - ub]);
            temp_zn = x_mas[j - ub] - x_mas[j + 1];
            p_mas[j - ub] = temp_ch / temp_zn;

        }
        ub++;
    }
    return round(p_mas[0] * eps) / eps;
}

double epsilon(double &E_okr, double &E_us, double la_x, int n, double *x_mas)
{
    double temp_ch = 1, temp_zn = 1, M;
    for(int i = 0; i < n + 1; i++)
    {
        temp_ch *= la_x - x_mas[i];
        if(temp_ch < 0) temp_ch *= -1;
        temp_zn *= i + 1;
    }
    M = 3.0/8.0 * pow(x_mas[n - 1], -5.0/2.0);
    if(M < 0) M *= -1;

    E_okr = 1 / eps;
    E_us = M * (temp_ch / temp_zn);
}

int main()
{
    int n, i;
    double x = 0, et_x, et_y, E_us = 1, E_okr = 1, temp = 0;

    cout << endl << "Vvedite x: ";
    cin >> et_x;

    cout << "Input n = ";
    cin >> n;
    cout << endl;
    double *x_mas = new double [n];
    double *y_mas = new double [n];

    for(i = 0; i < n; i++)
    {
        cout << endl << "x[" << i << "] = ";
        cin >> x_mas[i];
        y_mas[i] = formula(x_mas[i]);
        cout << "y[" << i << "] = " << y_mas[i];
    }
    cout << endl;

    et_y = formula_et(et_x, n, x_mas, y_mas);

    cout << endl << "x = " << et_x << " y = " << et_y << endl;

    epsilon(E_okr, E_us, et_x, n, x_mas);
    cout << "E_okr = " << E_okr << " E_us = " << E_us << " E_real = " << E_us + E_okr << endl;

    return 0;
}
