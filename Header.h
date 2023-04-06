#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <assert.h>
#include <cmath>
#include<algorithm>
using namespace std;

class CBigNumber{
private:
    long long a;
    unsigned long long b;
public:
    CBigNumber();
    CBigNumber(long long value_a, unsigned long long value_b);
    CBigNumber(long long value_b);
    long long GetA();
    unsigned long long GetB();
    void print();
    void SetA(long long value_a);
    void SetB(unsigned long long value_b);
    void GetBigNum(long long& value_a, unsigned long long& value_b);
    void SetBigNum(long long value_a, unsigned long long value_b);
    CBigNumber SumBigNums(CBigNumber toadd);
    CBigNumber SubtractBigNums(CBigNumber minus);
    void tobinary();
};
#endif // header.h
