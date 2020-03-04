#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

const float eps = 0.00000001;

float proverka(float left, float right)
{
	return ((right * right - 3) * (left * left - 3));
}

float x_form(float last)
{
	return (last - ((((last*last) -  3)) / (2 * last)));
}

float mymod(float temp)
{
	if (temp < 0) temp *= -1;

	return temp;
}

int main (void)
{
	float l_interval, r_interval, c = 2, last;
	
	cout << "Vvedite interval: ";
	cin >> l_interval >> r_interval;
	
	if (proverka(l_interval, r_interval) >= 0)
	{
		cout << "Korney net " << endl;
	}
	else 
	{
		for(int step = 1; mymod(c - last) >= eps; step++)
		{
			cout << endl << step << endl;
			
			last = c;
			c = x_form(last);
			
			cout << "rezult = " << c << endl;
		}
	}
	
	return 0;
}
