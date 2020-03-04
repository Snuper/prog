all: mySimpleComputer.o main.o
	gcc mySimpleComputer.o main.o -o main

mySimpleComputer.o: mySimpleComputer.c
	gcc mySimpleComputer.c -c

main.o: main.c
	gcc main.c -c

tests: mySimpleComputer.o mainTests.o
	gcc mySimpleComputer.o mainTests.o -o maintest

mainTests.o: mainTests.c
	gcc mainTests.c -c

clear:
	rm *.o
	rm main
	rm maintest