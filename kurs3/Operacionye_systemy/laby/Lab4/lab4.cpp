#include "lib.h"
#include <stdio.h>
#include <process.h>
#include <iostream>
#include <string.h>
using namespace std;

void printfDir(char *dir)
{
	for(int i = 0; i < 255 && dir[i] > 0; ++i)
	{
		if(dir[i] == '/') dir[i] = 92;
		cout << dir[i];
	}
	cout << " ~ ";
}

int main()
{
	int num;
	char argv[255], arg[255];
	while(1)
	{
		printfDir(dir);
		num = -1; arg[0] = 0;
		cin >> argv;
		for(int i = 0; i < count; ++i)
		{
			if(!strcmp(com[i],argv))
			{
				num = i;
				break;
			}
		}

		if(num == 0)
		{
			if(spawnl(_P_WAIT, argv, "some", NULL) == 1) exit(0);
		}
`		else if(num == 1) spawnl(_P_WAIT, argv, "some", NULL);
		else if(num == 2)
		{
			if(gets(arg) != 0) spawnl(_P_WAIT, argv, "some", arg, NULL);
		}
		else if(num == 3)
		{
			gets(arg);
			if(!spawnl(_P_WAIT, argv, "some", arg, dir, NULL))
			{
				int byt = 0;
				FILE *f = fopen("dir.txt", "rb");
				fread(&byt, sizeof(int), 1, f);
				fread(dir, byt, 1, f);
				fclose(f);
			}
		}
		else if(num == 4)
		{
			gets(arg);
			spawnl(_P_WAIT, argv, "some", dir, arg, NULL);
		}
		else if(num == 5)
		{
			gets(arg);
			spawnl(_P_WAIT, argv, "some", dir, arg, NULL);
		}
		else cout << "comand not found" << endl; break;
	}
}
