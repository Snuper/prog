#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

const float eps = 0.00000001;

float proverka(float left, float right)
{
	return ((right * right - 3) * (left * left - 3));
}

float krainie(float left, float right)
{
	return (((left*left) - 3) * ((right*right) - 3));
}

float c_midl(float left, float right)
{
	return ((left + right) / 2);
}

float epsilon(float left, float right)
{
	return ((right - left) / 2);
}

float mymod(float left, float right)
{
	if (left < 0) left *= -1;
	if (right < 0) right *= -1;

	return (right - left);
}

int main (void)
{
	float l_interval, r_interval, c;
	
	cout << "Vvedite interval: ";
	cin >> l_interval >> r_interval;
	
	if (proverka(l_interval, r_interval) >= 0)
	{
		cout << "Korney net " << endl;
	}
	else
	{
		for(int step = 1; mymod(l_interval, r_interval) >= eps; step++)
			{
				cout << endl << step << endl;
				krainie(l_interval, r_interval);
				
				c = c_midl(l_interval, r_interval);
				
				cout << "granicy " << l_interval << " and " << r_interval << endl;
				cout << "rezult = " << c << endl;
				
				if(krainie(l_interval, c) < 0) r_interval = c;
				else if(krainie(c, r_interval) < 0) l_interval = c;
			}
	}
	
	return 0;
}
