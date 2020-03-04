
#ifndef MSC_H
#define MSC_H
#define 1 flag_overflow
#define	2 flag_0
#define 3 flag_memoryBorder
#define 4 flag_tactIgnore
#define 5 flag_wrongCommand

int memory[100];

bool flag_overflow = false, flag_0 = false, flag_memoryBorder = false, flag_tactIgnore = false, flag_wrongCommand = false;

int sc_memoryInit()
{
	for (int i = 0; i < 100; i++ )
	{
		memory[i] = 0;
	}
};

int sc_memorySet(int address, int value)
{
	if ((address < 0) || (address > 99))
	{
		cout << "Error: out of memory size";
		flag_memoryBorder = true;
	}
	else
		memory[address] = value;
};

int sc_memoryGet (int address, int *value)
{
	if ((address < 0) || (address > 99)
	{
		flag_memoryBorder = true;
		cout << "Error: out of memory size"
		break;
	}
	return memory[address]
};

int sc_regInit (void)
{
	flag_overflow = false;
	flag_0 = false;
	flag_memoryBorder = false;
	flag_tactIgnore = false;
	flag_wrongCommand = false;
};

int sc_regSet (int register, bool value)
{
	if ((register < 1) || (register > 5))
	{
		cout<<"This register does not exist";
	}
	else
	{
		register = velue;
	}
};

int sc_regGet (int register, bool *value)
{
	if ((register < 1) || (register > 5))
	{
		cout<<"This register does not exist";
	}
	else
	{
		return value;
	}
};
#endif
