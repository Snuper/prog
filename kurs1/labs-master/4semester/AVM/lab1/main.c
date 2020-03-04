#include "mySimpleComputer.h"

int main() {
	printf("test mySimpleComputer:\n");
	int error;

	error = cs_memoryInit();
	cs_memorySet(100, 23);
	int registr_out_of_memory;
	cs_regGet(MASK_OUT_OF_MEMORY, &registr_out_of_memory);
	printf("registr_out_of_memory = %i\n", registr_out_of_memory);

	int value;
	cs_commandEncode(0x66, 0x10, &value);
	printf("value = %i\n", value);
	int command, operand;
	cs_commandDecode(&command, &operand, value);
	printf("command = %i, operand = %i\n", command, operand);	
	return 0;
}