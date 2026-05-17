#pragma once

#include "Pair.h"

class Long : public Pair {
public:
    Long(void);
    Long(int h, int l);
    Long(const Long& l);
    ~Long(void);

    int get_high();
    int get_low();

    void set_high(int h);
    void set_low(int l);

    Long& operator=(const Long& l);
    Long operator+(const Long& l);
    Long operator-(const Long& l);
    Long operator*(const Long& l);

    friend istream& operator>>(istream& in, Long& l);
    friend ostream& operator<<(ostream& out, const Long& l);
};
