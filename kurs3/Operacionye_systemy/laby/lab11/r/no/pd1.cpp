#include <windows.h>
#include <iostream>
#include <stdio.h>
#pragma comment(lib, "buff")

using namespace std;

extern __declspec(dllimport)
int result;

extern __declspec(dllimport)
bool go;

void subtraction()
{
	int i = 0;
	while(i < 1000)
	{
		result -= 1;
		i++;
	}
}

int main()
{	 
	cout << "Wait pd2.exe...\n";
	
	while(go == false);
	
	subtraction();
	
	cout << result;
	
	return 0;
}