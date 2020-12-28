#include <iostream>
#include <cmath>

using namespace std;

double vectorLength(double x, double y)
{
	return fabs(sqrt(pow(x,2) + pow(y,2)));
}

int main (void)
{
	double x, y, R = 0;

	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
	
	R = vectorLength(x, y);
	
	cout << "Result: " << R << endl;
	
	return 0;
}
