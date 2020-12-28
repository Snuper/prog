#include <windows.h>
#include <iostream>
#include <mutex>
#pragma data_seg(".M_SH")
int result = 0;
bool go = false;
#pragma data_seg()
#pragma comment(linker, "/SECTION:.M_SH,RWS" )