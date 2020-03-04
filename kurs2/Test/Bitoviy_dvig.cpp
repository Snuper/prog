#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>

using namespace std;

const unsigned char flag_overflow = 0x01;
const unsigned char flag_0 = 0x02;
const unsigned char flag_memoryBorder = 0x08;
const unsigned char flag_tactIgnore = 0x10;
const unsigned char flag_wrongCommand = 0x20;

unsigned char flags = 0;

int flag_activate(int temp)
{
	if (temp == 1)
	{
		if (flags & flag_overflow) flags &= ~flag_overflow;
		else flags |= flag_overflow;
		return 0;
	} 
	else if (temp == 2)
	{
		if (flags & flag_0) flags &= ~flag_0;
		else flags |= flag_0;
		return 0;
	}
	else if (temp == 3)
	{
		if (flags & flag_memoryBorder) flags &= ~flag_memoryBorder;
		else flags |= flag_memoryBorder;
		return 0;
	}
	else if (temp == 4)
	{
		if (flags & flag_tactIgnore) flags &= ~flag_tactIgnore;
		else flags |= flag_tactIgnore;
		return 0;
	}
	else if (temp == 5)
	{
		if (flags & flag_wrongCommand) flags &= ~flag_wrongCommand;
		else flags |= flag_wrongCommand;
		return 0;
	}
	return 1;
}

void flag_sostoyanie()
{
	if (flags & flag_overflow) cout << "flag_overflow - True" << endl;
	else cout << "flag_overflow - False" << endl;
	
	if (flags & flag_0) cout << "flag_0 - True" << endl;
	else cout << "flag_0 - False" << endl;
	
	if (flags & flag_memoryBorder) cout << "flag_memoryBorder - True" << endl;
	else cout << "flag_memoryBorder - False" << endl;
	
	if (flags & flag_tactIgnore) cout << "flag_tactIgnore - True" << endl;
	else cout << "flag_tactIgnore - False" << endl;
	
	if (flags & flag_wrongCommand) cout << "flag_wrongCommand - True" << endl;
	else cout << "flag_wrongCommand - False" << endl;
}

int main(void)
{
	int temp_flag = 1;
	while (temp_flag != 0)
	{
		cout << "Vibor flaga: ";
		cin >> temp_flag;
		if (temp_flag < 0 or temp_flag > 5) cout << "Erorr" << endl;
		else
		{
			flag_activate(temp_flag);
			flag_sostoyanie();
		}
		system("pause");
		system("cls");
	}
}
