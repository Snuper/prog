#include "mySimpleComputer.h"
#define cs_SIZE_MEMORY 100

int cs_memory[cs_SIZE_MEMORY];

int cs_reg;

int cs_memoryInit() {
	for(int i = 0; i < cs_SIZE_MEMORY; i++) {
		cs_memory[i] = 0;
	}
	return 0;
}

int cs_memorySet(int address, int value) {
	if(address > cs_SIZE_MEMORY && address < 0) {
		cs_regSet(MASK_OUT_OF_MEMORY, 1);
		return -1;
	}
	cs_memory[address] = value;
	return 0;
}

int cs_memoryGet(int address, int* value) {
	if(address > cs_SIZE_MEMORY && address < 0) {
		cs_regSet(MASK_OUT_OF_MEMORY, 1);
		return -1;
	}
	*value = cs_memory[address];
	return 0;
}

int cs_regInit() {
	cs_reg = 0;
	return 0;
}

int cs_regSet(int registr, int value) {
	if(value < 0 && value > 1 && (registr > MAX_REG)) {
		return -1;
	}
	cs_reg = cs_reg | (registr * value);
	return 0;

}

int cs_regGet(int registr, int *value) {
	if(value == NULL) {
		return -1;
	}
	*value = (registr & cs_reg) / registr;
	return 0;
}

int cs_memorySave(const char *filename) {
	int file = open(filename, O_WRONLY);
	if(file < 0) {
		return -1;
	}
	if(write(file, cs_memory, sizeof(int) * 100) != sizeof(int) * 100) {
		return -1;
	}
	return 0;
}

int cs_memoryLoad(const char *filename) {
	int file = open(filename, O_RDONLY);
	if(file < 0) {
		return -1;
	}
	if(read(file, cs_memory, sizeof(int) * 100) != sizeof(int) * 100) {
		return -1;
	}
	return 0;
}

int cs_commandEncode(int command, int operand, int* value) {
	if(operand > 127 && command > 127) {
		return -1;
	}
	*value = 0;
	*value = *value | (command << 7) | operand;
	return 0;
}

int cs_commandDecode(int* command, int* operand, int value) {
	if(value > 16383) {
		cs_regSet(MASK_COMMAND_ERROR, 1);
		return -1;	
	}
	*command = 0;
	*operand = 0;
	*command = (value >> 7) & 127;
	*operand = 127 & value;
	return 0;
}
