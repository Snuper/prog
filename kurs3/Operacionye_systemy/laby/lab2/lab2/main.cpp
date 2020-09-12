#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include "sysinfoapi.h"
#include "winbase.h"

using namespace std;

int main()
{
    char Buffer[256];
    int size = sizeof(Buffer);
    LPSYSTEM_INFO buffer_info;
    MEMORYSTATUSEX buffer_memory;

    GetWindowsDirectoryA(Buffer, size);
    cout << "Windows directory: " << Buffer;

    GetTempPathA(size, Buffer);
    cout << endl << "Temp path: " << Buffer;

    GetSystemInfo(buffer_info);
    cout << endl << "Number of processor cores: " << buffer_info->dwNumberOfProcessors;
    cout << endl << "Processor architecture: " << buffer_info->dwProcessorType;
    cout << endl << "Custom address space (min): " << buffer_info->lpMinimumApplicationAddress;
    cout << endl << "Custom address space (max): " << buffer_info->lpMaximumApplicationAddress;

    GlobalMemoryStatusEx (&buffer_memory);
    cout << endl << "Use virtual memory: " << buffer_memory.ullTotalVirtual - buffer_memory.ullAvailVirtual;
    cout << endl << "Use physical memory: " << buffer_memory.ullTotalPhys - buffer_memory.ullAvailPhys;
}
