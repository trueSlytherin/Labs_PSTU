#pragma once

#include <iostream>

using namespace std;

class Money {
private:
    long rub;
    int kop;

    void normalization();

public:
    Money();
    Money(long r, int k);
    Money(const Money& t);
    ~Money();

    long get_rub();
    int get_kop();

    void set_rub(long r);
    void set_kop(int k);

    void show();

    Money& operator=(const Money& t);
    Money operator+(const Money& t);
    Money operator-(const Money& t);

    friend istream& operator>>(istream& in, Money& t);
    friend ostream& operator<<(ostream& out, const Money& t);
};
