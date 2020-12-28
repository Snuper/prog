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

void summ()
{
	int i = 0;
	while(i < 1000)
	{
		WaitForSingleObject(hSemaphore, INFINITE); 
		result += 1;
		i++;
		ReleaseSemaphore(hSemaphore, 1, NULL);
	}
}

int main()
{	
	go = true;
	
	hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "SEM");
	
	summ();
	
	CloseHandle(hSemaphore);
	
	return 0;
}