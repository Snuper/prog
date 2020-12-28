#include <windows.h>
#include <iostream>
#include <process.h>
#include <stdio.h>
#pragma comment(lib, "buff")

using namespace std;

extern __declspec(dllimport)
int result;

extern __declspec(dllimport)
bool go;

extern __declspec(dllimport)
HANDLE hSemaphore;

void subtraction()
{
	int i = 0;
	while(i < 1000)
	{
		WaitForSingleObject(hSemaphore, INFINITE);
		result -= 1;
		i++;
		ReleaseSemaphore(hSemaphore, 1, NULL);
	}
}

int main()
{	 
	hSemaphore = CreateSemaphore(NULL, 1, 20, "SEM");
	
	std::cout << "Wait pd2.exe...\n";
	
	while(go == false);
	
	subtraction();
	
 	CloseHandle(hSemaphore);
	
	cout << result;
	
	return 0;
}