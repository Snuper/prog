#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

main()
{
	double speed, sila = 290, distance = 0, i;
	bool flag = false;
	
	cout << endl << "Input speed: ";
	cin >> speed;
	
	for(i = 0; ; i++)
	{
		if(sila > 290) break;
		if(sila < 0) flag = true;
		
		if(flag == true) sila += 8;
		else sila -= 8;
		distance += speed / 100;
	}
	
	return 0;
}
