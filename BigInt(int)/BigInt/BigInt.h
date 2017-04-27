#ifndef BIGINT.H
#define BIGINT.H

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct LargeInt{
    int * Number;
    int NumberDigits = 0;
    int Size;
};

class BigInt{
    private:
        int * Number;
        int NumberDigits = 0;
        int Size;
    public:
        BigInt();
        BigInt(string,int = 100);
        BigInt(int,int = 100);
        BigInt(BigInt & a);
        ~BigInt();
        void Zero();
        void InputNumber(string);
        void InputNumber(int);
        void ResizeSize(const int);
        void PrintValue();
        int GetNumberDigit(void);
        void Add(string);
        void Add(int);
        void Add(BigInt &);
        LargeInt GetBigInt();
};

int IsCarryOut(int &);
int IsCarryOut(char &);


#endif // BIGINT

