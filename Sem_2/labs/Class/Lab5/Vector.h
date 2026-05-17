#pragma once

#include <iostream>

#include "Object.h"

using namespace std;

class Vector {
public:
    Vector(void);
    Vector(int n);
    ~Vector(void);

    void Add(Object* p);

    friend ostream& operator<<(ostream& out, const Vector& v);

private:
    Object** beg;
    int size;
    int cur;
};
