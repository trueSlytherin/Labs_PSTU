#pragma once

#include <fstream>
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
    Money(const Money& m);
    ~Money();

    long get_rub();
    int get_kop();

    void set_rub(long r);
    void set_kop(int k);

    Money& operator=(const Money& m);
    Money operator+(const Money& m);
    Money operator-(const Money& m);
    bool operator==(const Money& m);
    bool operator!=(const Money& m);

    friend ostream& operator<<(ostream& out, const Money& m);
    friend istream& operator>>(istream& in, Money& m);
    friend fstream& operator<<(fstream& fout, const Money& m);
    friend fstream& operator>>(fstream& fin, Money& m);
};
