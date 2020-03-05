#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>
#include <time.h>
#include <bitset>

using namespace std;

const int flag_overflow = 0;
const int flag_0 = 1;
const int flag_memoryBorder = 2;
const int flag_tactIgnore = 3;
const int flag_wrongCommand = 4;

bitset<5> bits(0x2);

void flag_set(int temp)
{
	if (temp == 1) bits.set(flag_overflow);
	else if (temp == 2) bits.set(flag_0);
	else if (temp == 3) bits.set(flag_memoryBorder);
	else if (temp == 4) bits.set(flag_tactIgnore);
	else if (temp == 5) bits.set(flag_wrongCommand);
}

void flag_reset(int temp)
{
	if (temp == 1) bits.reset(flag_overflow);
	else if (temp == 2) bits.reset(flag_0);
	else if (temp == 3) bits.reset(flag_memoryBorder);
	else if (temp == 4) bits.reset(flag_tactIgnore);
	else if (temp == 5) bits.reset(flag_wrongCommand);
}

void flag_flip(int temp)
{
	if (temp == 1) bits.flip(flag_overflow);
	else if (temp == 2) bits.flip(flag_0);
	else if (temp == 3) bits.flip(flag_memoryBorder);
	else if (temp == 4) bits.flip(flag_tactIgnore);
	else if (temp == 5) bits.flip(flag_wrongCommand);
}

void flag_test(int temp)
{
	if (temp == 0)
	{
		cout << endl << "flag_overflow = " << bits.test(flag_overflow) << endl;
		cout << endl << "flag_0 = " << bits.test(flag_0) << endl;
		cout << endl << "flag_memoryBorder = " << bits.test(flag_memoryBorder) << endl;
		cout << endl << "flag_tactIgnore = " << bits.test(flag_tactIgnore) << endl;
		cout << endl << "flag_wrongCommand = " << bits.test(flag_wrongCommand) << endl;
	}
	else if (temp == 1) cout << endl << "flag_overflow = " << bits.test(flag_overflow) << endl;
	else if (temp == 2) cout << endl << "flag_0 = " << bits.test(flag_0) << endl;
	else if (temp == 3) cout << endl << "flag_memoryBorder = " << bits.test(flag_memoryBorder) << endl;
	else if (temp == 4) cout << endl << "flag_tactIgnore = " << bits.test(flag_tactIgnore) << endl;
	else if (temp == 5) cout << endl << "flag_wrongCommand = " << bits.test(flag_wrongCommand) << endl;
}

int main(void)
{
	flag_reset(2);
	for (int temp_flag = -1, temp_act; temp_flag != 0;)
	{
		cout << "Vibor flaga: ";
		cin >> temp_flag;
		if (temp_flag < 0 or temp_flag > 5) cout << "Erorr" << endl;
		else
		{
			cout << "Viberite deistvie:" << endl << "1 - vkluchaet vibrany flag" << endl << "2 - Menyaet znachenie flaga na protivopolojnoe" << endl << "3 - Vikluchaet flag" << endl << "4 - uznat znachenie flaga" << endl;
			cin >> temp_act;
			if (temp_act < 1 or temp_act > 4) cout << "Erorr" << endl;
			else if (temp_act == 1) flag_set(temp_flag);
			else if (temp_act == 2) flag_flip(temp_flag);
			else if (temp_act == 3) flag_reset(temp_flag);
			else if (temp_act == 4) flag_test(temp_flag);
		}
		flag_test(0);
		system("pause");
		system("cls");
	}
}
