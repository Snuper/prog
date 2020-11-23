#ifndef MTEST_H
#define MTEST_H

#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

class MTest
{
public:
    void Gogogo(int argc, char *argv[]);
private:
    string memType;
    double blockSize;
    string elementType;
    int buffSize;
    int launchNum;
    string timer;
    double writeTime;
    double averageWriteTime;
    double writeBandwidth;
    double writeAbsError;
    double writeRealError;
    double readTime;
    double averageReadTime;
    double readBandwidth;
    double readAbsError;
    double readRealError;

    timespec* timeStart = new timespec;
    timespec* timeEnd = new timespec;
    double* timeWrite;
    double* timeRead;

    double secondTimeStart = 0;
    double* timeCountWrite;
    double* timeCountRead;

    int cash[4] = {
        131072,
        524288,
        3145728,
        0
    };

    string memory_type;
    int number_of_tests, customBlockSize;
    int size_of_buffer = 8;
    double absErrorWrite;
    double realErrorWrite;
    double absErrorRead;
    double realErrorRead;

    void BenchTimer(char type[], char task[], int number_try);
    void bTimer(char type[], char task[], int number_try);
    void RAMTestWrite(int size, int number_try);
    void RAMTestRead(int size, int number_try);
    void ROMTestWrite(int size, int number_try);
    void ROMTestRead(int size, int number_try);
    void FlashTestWrite(int size, int number_try);
    void FlashTestRead(int size, int number_try);
    double AverageTimeCounter(char type[], int size);
    void Accuracy(int number_try);
    void KeyReader(int N, char *key[]);
    void FileWriter(int block, int num);
};

#endif // MTEST_H
