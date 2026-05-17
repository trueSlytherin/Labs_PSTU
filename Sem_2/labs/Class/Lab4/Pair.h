#pragma once

#include <iostream>

using namespace std;

class Pair {
public:
    Pair(void);
    Pair(int f, int s);
    Pair(const Pair& p);
    ~Pair(void);

    int get_first();
    int get_second();

    void set_first(int f);
    void set_second(int s);

    Pair& operator=(const Pair& p);
    Pair operator+(const Pair& p);

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);

protected:
    int first;
    int second;
};
