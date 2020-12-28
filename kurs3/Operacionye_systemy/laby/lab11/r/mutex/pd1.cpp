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
HANDLE hMutex;


void subtraction()
{
	int i = 0;
	while(i < 1000)
	{
		WaitForSingleObject(hMutex, INFINITE); 
		result -= 1;
		i++;
		ReleaseMutex(hMutex);
	}
}

int main()
{	 
	hMutex = CreateMutex(NULL, FALSE, "Mutex");
	
	std::cout << "Wait pd2.exe...\n";
	
	while(go == false);
	
	subtraction();
	
	CloseHandle(hMutex);
	
	cout << result;
	
	return 0;
}