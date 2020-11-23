#include "mtest.h"

#define NANOSEC_TO_SEC 1000000000

void MTest::Gogogo(int argc, char *argv[])
{
    KeyReader(argc, argv);
    if (memory_type == "HDD" || memory_type == "SSD")
    {
        int ROMBlockSize = 0;
        int blockStep = 4 * 1024 * 1024;
        timeWrite = new double[number_of_tests];
        timeRead = new double[number_of_tests];
        timeCountWrite = new double[number_of_tests];
        timeCountRead = new double[number_of_tests];

        for (int i = 0; i < number_of_tests; i++)
        {
            ROMBlockSize += blockStep;
            ROMTestWrite(ROMBlockSize / size_of_buffer, i);
            ROMTestRead(ROMBlockSize / size_of_buffer, i);
            Accuracy(i);
//            cout << i + 1 <<") Write = " << timeWrite[i] << " Read = " << timeRead[i] << endl;
            FileWriter(ROMBlockSize, i + 1);
        }

        delete [] timeWrite;
        delete [] timeRead;
        delete [] timeCountWrite;
        delete [] timeCountRead;
    }

    else if (memory_type == "flash")
    {
        int flashBlockSize = 0;
        int blockStep = 4 * 1024 * 1024;
        timeWrite = new double[number_of_tests];
        timeRead = new double[number_of_tests];
        timeCountWrite = new double[number_of_tests];
        timeCountRead = new double[number_of_tests];

        for (int i = 0; i < number_of_tests; i++)
        {
            flashBlockSize += blockStep;
            FlashTestWrite(flashBlockSize / size_of_buffer, i);
            FlashTestRead(flashBlockSize / size_of_buffer, i);
            Accuracy(i);
//            cout << i + 1 <<") Write = " << timeWrite[i] << " Read = " << timeRead[i] << endl;
            FileWriter(flashBlockSize, i + 1);
        }

        delete[] timeWrite;
        delete[] timeRead;
        delete[] timeCountWrite;
        delete[] timeCountRead;
    }

    else if (memory_type == "RAM")
    {
        number_of_tests = 4;
        cash[3] = customBlockSize;
        timeWrite = new double[number_of_tests];
        timeRead = new double[number_of_tests];
        timeCountWrite = new double[number_of_tests];
        timeCountRead = new double[number_of_tests];

        for (int i = 0; i < number_of_tests; i++)
        {
            RAMTestWrite(cash[i] / size_of_buffer, i);
            RAMTestRead(cash[i] / size_of_buffer, i);
            Accuracy(i);
//            cout << i + 1 <<") Write = " << timeWrite[i] << " Read = " << timeRead[i] << endl;
            FileWriter(cash[i], i + 1);
        }

        delete [] timeWrite;
        delete [] timeRead;
        delete [] timeCountWrite;
        delete [] timeCountRead;
    }
}

void MTest::BenchTimer(char type[], char task[], int number_try)
{
    if ((string)task == "START") clock_gettime(CLOCK_REALTIME, timeStart);
    else if((string)task == "STOP")
    {
        clock_gettime(CLOCK_REALTIME, timeEnd);
        double current = (double)((timeEnd->tv_nsec - timeStart->tv_nsec) + NANOSEC_TO_SEC * (timeEnd->tv_sec - timeStart->tv_sec)) / NANOSEC_TO_SEC;
        if ((string)type == "READ") timeRead[number_try] = current;
        else if ((string)type == "WRITE") timeWrite[number_try] = current;
    }
}

void MTest::bTimer(char type[], char task[], int number_try)
{
    if ((string)task == "START") secondTimeStart = clock();
    else if((string)task == "STOP")
    {
        if ((string)type == "WRITE") timeCountWrite[number_try] = ((double)(clock() - secondTimeStart)) / CLOCKS_PER_SEC;
        else if ((string)type == "READ") timeCountRead[number_try] = ((double)(clock() - secondTimeStart)) / CLOCKS_PER_SEC;
    }
}

void MTest::RAMTestWrite(int size, int number_try)
{
    double* staticMas = new double [size];
    double* dynamicMas = new double [size];

    for (int i = 0; i < size; i++) staticMas[i] = rand()%100;

    BenchTimer((char*)"WRITE", (char*)"START", number_try);
    bTimer((char*)"WRITE", (char*)"START", number_try);
    for (int i = 0; i < size; i++) dynamicMas[i] = staticMas[i];
    BenchTimer((char*)"WRITE", (char*)"STOP", number_try);
    bTimer((char*)"WRITE", (char*)"STOP", number_try);

    delete [] staticMas;
    delete [] dynamicMas;
}

void MTest::RAMTestRead(int size, int number_try)
{
    double* staticMas = new double [size];
    double* dynamicMas = new double [size];

    for (int i = 0; i < size; i++) staticMas[i] = rand()%100;

    BenchTimer((char*)"READ", (char*)"START", number_try);
    bTimer((char*)"READ", (char*)"START", number_try);
    for (int i = 0; i < size; i++) staticMas[i] = dynamicMas[i];
    BenchTimer((char*)"READ", (char*)"STOP", number_try);
    bTimer((char*)"READ", (char*)"STOP", number_try);

    delete [] staticMas;
    delete [] dynamicMas;
}

void MTest::ROMTestWrite(int size, int number_try)
{
    double* mas = new double[size];
    for (int i = 0; i < size; i++) mas[i] = rand()%100;
    BenchTimer((char*)"WRITE", (char*)"START", number_try);
    bTimer((char*)"WRITE", (char*)"START", number_try);
    ofstream fileROM("testROM.bin", ios::out);
    for (int i = 0; i < size; i++) fileROM << mas[i];
    fileROM.close();
    BenchTimer((char*)"WRITE", (char*)"STOP", number_try);
    bTimer((char*)"WRITE", (char*)"STOP", number_try);
    delete [] mas;
}

void MTest::ROMTestRead(int size, int number_try)
{
    double* mas = new double[size];

    BenchTimer((char*)"READ", (char*)"START", number_try);
    bTimer((char*)"READ", (char*)"START", number_try);
    ifstream fileROM("testROM.bin", ios::in);
    for (int i = 0; i < size; i++) fileROM >> mas[i];
    fileROM.close();
    BenchTimer((char*)"READ", (char*)"STOP", number_try);
    bTimer((char*)"READ", (char*)"STOP", number_try);

    delete [] mas;
}

void MTest::FlashTestWrite(int size, int number_try)
{
    int* mas = new int[size];
    for (int i = 0; i < size; i++) mas[i] = rand()%100;

    BenchTimer((char*)"WRITE", (char*)"START", number_try);
    bTimer((char*)"WRITE", (char*)"START", number_try);
    ofstream fileROM("D:\testROM.bin", ios::out);
    for (int i = 0; i < size; i++) fileROM << mas[i];
    fileROM.close();
    BenchTimer((char*)"WRITE", (char*)"STOP", number_try);
    bTimer((char*)"WRITE", (char*)"STOP", number_try);

    delete [] mas;
}

void MTest::FlashTestRead(int size, int number_try)
{
    int* mas = new int[size];

    BenchTimer((char*)"READ", (char*)"START", number_try);
    bTimer((char*)"READ", (char*)"START", number_try);
    ifstream fileROM("D:\testROM.bin", ios::in);
    for (int i = 0; i < size; i++) fileROM >> mas[i];
    fileROM.close();
    BenchTimer((char*)"READ", (char*)"STOP", number_try);
    bTimer((char*)"READ", (char*)"STOP", number_try);

    delete [] mas;
}

double MTest::AverageTimeCounter(char type[], int size)
{
    double average = 0;
    if ((string)type == "WRITE")
    {
        for (int i = 0; i < size; i++) average += timeWrite[i];
        average /= size;
    }

    else if ((string)type == "READ")
    {
        for (int i = 0; i < size; i++) average += timeRead[i];
        average /= size;
    }

    return abs(average);
}

void MTest::Accuracy(int number_try)
{
    absErrorWrite = abs(timeWrite[number_try] - timeCountWrite[number_try]);
    absErrorRead = abs(timeRead[number_try] - timeCountRead[number_try]);
    realErrorWrite = absErrorWrite / timeCountWrite[number_try] * 100;
    realErrorRead = absErrorRead / timeCountRead[number_try] * 100;
}

void MTest::KeyReader(int N, char *key[])
{
    string input_block_size, temp;

    for(int i = 1; i < N; i++)
    {
        if((string)key[i] == "-m")
        {
            memory_type = key[i + 1];
            if( memory_type != "RAM" and
                memory_type != "HDD" and
                memory_type != "SSD" and
                memory_type != "flash" )
            {
                cout << "\nError(input MEMORY_TYPE)";
                break;
            }
        }

        else if((string)key[i] == "-b")
        {
            input_block_size = key[i + 1];
            if( input_block_size[input_block_size.size() - 2] != 'K' and
                input_block_size[input_block_size.size() - 2] != 'M')
                customBlockSize = atoi(input_block_size.c_str());
            else
            {
                for (unsigned int j = 0; j < input_block_size.size() - 2; j++) temp[j] = input_block_size[j];
                if(input_block_size[input_block_size.size() - 2] == 'K') customBlockSize = atoi(temp.c_str()) * 1024;
                else customBlockSize = atoi(temp.c_str()) * 1024 * 1024;
            }
        }
        else if((string)key[i] == "-l") number_of_tests = atoi(key[i + 1]);
        else;
    }
}

void MTest::FileWriter(int block, int num)
{
    memType = memory_type;
    elementType = "int";
    blockSize = (double)block / (1024 * 1024);
    buffSize = size_of_buffer;
    launchNum = num;
    writeTime = timeWrite[num - 1];
    readTime = timeRead[num - 1];
    readAbsError = absErrorRead;
    writeAbsError = absErrorWrite;
    readRealError = realErrorRead;
    writeRealError = realErrorWrite;
    averageWriteTime = AverageTimeCounter((char*)"WRITE", num);
    averageReadTime = AverageTimeCounter((char*)"READ", num);
    writeBandwidth = (double)block / averageWriteTime;
    readBandwidth = (double)block / averageReadTime;
    timer = "clock_gettime()";

    ofstream file("text.csv", ios::app);
    if(!file.is_open()) cout << endl << "Can't open/find file template_vmf_end.txt" << endl;

    else
    {
        file    << memType << ";"
                << blockSize <<" Mb" << ";"
                << elementType << ";"
                << buffSize << ";"
                << launchNum << ";"
                << timer << ";"
                << writeTime << ";"
                << averageWriteTime << ";"
                << writeBandwidth << ";"
                << writeAbsError << ";"
                << writeRealError << ";"
                << readTime << ";"
                << averageReadTime << ";"
                << readBandwidth << ";"
                << readAbsError << ";"
                << readRealError <<  endl;
    }
    file.close();
}
