#include "Header.h"

CBigNumber::CBigNumber(){
    a = 0;
    b = 0;
}

CBigNumber::CBigNumber(long long value_a, unsigned long long value_b){
    a = value_a;
    b = value_b;
}

CBigNumber::CBigNumber(long long value_b){
    a = 0;
    b = value_b;
}

long long CBigNumber::GetA(){
    return a;
}

unsigned long long CBigNumber::GetB(){
    return b;
}

void CBigNumber::SetA(long long value_a){
    a = value_a;
}

void CBigNumber::SetB(unsigned long long value_b){
    b = value_b;
}

void CBigNumber::print() {
    cout << a << endl << b << endl;
}

CBigNumber CBigNumber::SumBigNums(CBigNumber toadd){
    long long res;
    res = this->a + toadd.a;
    if (res <= toadd.a) { //check if overflow
        toadd.a = LLONG_MAX;
        res = llabs(LLONG_MIN + (-res));
        this->b += res + 1;
    }else toadd.a += a;
    res = 0;
    res = (unsigned long long) this->b + toadd.b;
    if (res <= toadd.b) {
        toadd.b = ULLONG_MAX;
        toadd.a += res + 1;
    }else toadd.b += b;
    return toadd;
}


CBigNumber CBigNumber::SubtractBigNums(CBigNumber minus) {
    if ((b - minus.b) >= b && b != 0 && minus.b != 0){
        if ((a < 0 && (a - 1) > 0)){
            assert(!"overflow (unable to subtract this number)!");
        }
        a -= 1;
    }
    if ((a > 0 && minus.a < 0 && a - minus.a < 0) || ((a < 0 && minus.a > 0) && a - minus.a > 0)){
        assert(!"overflow (unable to subtract this number)!");
    }
    CBigNumber Answer;
    Answer.a = a - minus.a;
    Answer.b = b - minus.b;
    return Answer;
}

void CBigNumber::GetBigNum(long long& value_a, unsigned long long& value_b){
    value_a = a;
    value_b = b;
}
void CBigNumber::SetBigNum(long long value_a, unsigned long long value_b){
    a = value_a;
    b = value_b;
}
void CBigNumber::tobinary(){

    int count = 0;
    long long num = a, num1 = a;
    bool binary[64] = { 0 };
    do {
        if (num % 2){
            binary[count++] = 1;
        }
        else{
            binary[count++] = 0;
        }
        num = num / 2;
    } while (num);

    if (num1 < 0)
    {
        binary[63] = 1;
        for (int i = 0; i < 63; i++){
            if (binary[i] == 0)
                binary[i] = 1;
            else
                binary[i] = 0;
        }
    }
    else binary[63] = 0;


    int count1 = 0;
    long long num2 = b, num3 = b;
    bool binary1[64] = { 0 };


    do {
        if (num2 % 2)
        {
            binary1[count1++] = 1;
        }
        else
        {
            binary1[count1++] = 0;
        }
        num2 = num2 / 2;
    } while (num2);

    if (num1 < 0)
    {
        for (int i = 0; i < 64; i++)
        {
            if (binary1[i] == 0)
                binary1[i] = 1;
            else
                binary1[i] = 0;
        }
        if (num3 == 0)
        {
            for (int i = 0; i < 63; i++)
            {
                if (binary[i] == 1)
                    binary[i] = 0;
                else
                {
                    binary[i] = 1;
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < 64; i++)
            {
                if (binary1[i] == 1)
                    binary1[i] = 0;
                else
                {
                    binary1[i] = 1;
                    break;
                }
            }
        }
    }




    for (long long i = 63; i >= 0; i--)
    {
        cout << binary[i];
    }
    cout << "§";

    for (long long i = 63; i >= 0; i--)
    {
        cout << binary1[i];
    }
    cout << endl;

}



    