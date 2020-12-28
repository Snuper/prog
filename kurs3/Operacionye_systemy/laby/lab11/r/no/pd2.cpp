#include <windows.h>
#include <iostream>
#include <stdio.h>
#pragma comment(lib, "buff")

using namespace std;

extern __declspec(dllimport)
int result;

extern __declspec(dllimport)
bool go;

void summ()
{
	int i = 0;
	while(i < 1000)
	{
		result += 1;
		i++;
	}
}

int main()
{	
	go = true;
	
	summ();
	
	cout << result;
	
	return 0;
}