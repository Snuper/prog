#include "mySimpleComputer.h"

int main() {
	int test = 0;
	int validate_test = 0;
	printf("test mySimpleComputer:\n");
	int error;

	test++;
	validate_test++;
	error = cs_memoryInit();
	if(error) {
		printf("Error cs_memoryInit() return %i\n", error);
		validate_test--;
	}
	
	test++;
	validate_test++;
	error = cs_memorySet(10, 10);
	if(error) {
		printf("Error cs_memorySet() return %i\n", error);
		validate_test--;
	}

	test++;
	validate_test++;
	int value;
	error = cs_memoryGet(10, &value);
	if(error) {
		printf("Error, cs_memoryGet() return %i\n", error);
		validate_test--;
	}
	printf("return value in cs_memoryGet() = %i\n", value);

	test++;
	validate_test++;
	error = cs_regInit();
	if(error) {
		printf("Error, cs_regInit() return %i\n", error);
		validate_test--;
	}

	test++;
	validate_test++;
	error = cs_regSet(MASK_OUT_OF_MEMORY, 1);
	if(error) {
		printf("Error, cs_regSet() return %i\n", error);
		validate_test--;
	}

	test++;
	validate_test++;
	error = cs_regGet(MASK_OUT_OF_MEMORY, &value);
	if(error) {
		printf("Error, cs_regGet() return %i\n", error);
		validate_test--;
	}
	printf("return value in cs_regGet() = %i\n", value);
	
	test++;
	validate_test++;
	error = cs_memorySave("cs_memoryFile.txt");
	if(error) {
		printf("Error, cs_memorySave() return %i\n", error);
		validate_test--;
	}

	test++;
	validate_test++;
	error = cs_memoryLoad("cs_memoryFile.txt");
	if(error) {
		printf("Error, cs_memoryLoad() return %i\n", error);
		validate_test--;
	}

	test++;
	validate_test++;
	error = cs_commandEncode(0x33, 0x59, &value);
	if(error) {
		printf("Error, cs_commandEncode() return %i\n", error);
		validate_test--;
	}
	printf("return value in cs_commandEncode() = %i\n", value);

	test++;
	validate_test++;
	int command = 0;
	int operand = 0;
	error = cs_commandDecode(&command, &operand, value);
	if(error) {
		printf("Error, cs_commandEncode() return %i\n", error);
		validate_test--;
	}
	printf("return command in cs_commandDecode() = %i\n", command);
	printf("return operand in cs_commandDecode() = %i\n", operand);
	printf("\n tests: %i / %i\n", test, validate_test);
	return 0;
}