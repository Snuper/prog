#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "libra.h"
#include "unit.h"

using namespace std;

int main()
{
	FILE* fp;
	errno_t err;
	unit* mas;
	char key[3];
	int hit, i, k = 0, l = 0, temp;

	fp = fopen("testBase3.dat", "rb");// open file
	mas = new unit[const_size]; //create memory
	i = fread((unit*)mas, sizeof(unit), const_size, fp);//read file

	UI(fp, mas); //process

	delete mas; //free memory
	err = fclose(fp); //close file
	return 0; //finish program
}
