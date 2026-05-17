#pragma once

#include <iostream>

#include "Error.h"

using namespace std;

const int MAX_SIZE = 30;

class Set {
private:
    int size;
    int* data;

public:
    Set(void);
    Set(int s);
    Set(const Set& a);
    ~Set(void);

    Set& operator=(const Set& a);
    int& operator[](int index);
    int operator()();
    Set operator+(const Set& a);
    Set& operator++();
    Set operator++(int);

    void Add(int value);
    bool Contains(int value);

    friend ostream& operator<<(ostream& out, const Set& a);
    friend istream& operator>>(istream& in, Set& a);
};
