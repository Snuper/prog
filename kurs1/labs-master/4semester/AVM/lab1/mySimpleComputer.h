#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX_REG 4
#define	MASK_OUT_OF_MEMORY 1
#define MASK_COMMAND_ERROR 2

int cs_memoryInit();
int cs_memorySet(int, int);
int cs_memoryGet(int, int*);
int cs_memorySave(const char*);
int cs_memoryLoad(const char*);
int cs_regInit();
int cs_regSet(int, int);
int cs_regGet(int, int*);	
int cs_commandEncode(int, int, int*);
int cs_commandDecode(int*, int*, int);
