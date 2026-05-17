#include "Pair.h"

Pair::Pair(void) {
    first = 0;
    second = 0;
}

Pair::Pair(int f, int s) {
    first = f;
    second = s;
}

Pair::Pair(const Pair& p) {
    first = p.first;
    second = p.second;
}

Pair::~Pair(void) {
}

int Pair::get_first() {
    return first;
}

int Pair::get_second() {
    return second;
}

void Pair::set_first(int f) {
    first = f;
}

void Pair::set_second(int s) {
    second = s;
}

Pair& Pair::operator=(const Pair& p) {
    if (this == &p) {
        return *this;
    }

    first = p.first;
    second = p.second;
    return *this;
}

Pair Pair::operator+(const Pair& p) {
    Pair t;
    t.first = first + p.first;
    t.second = second + p.second;
    return t;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "first = ";
    in >> p.first;
    cout << "second = ";
    in >> p.second;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "first = " << p.first << endl;
    out << "second = " << p.second << endl;
    return out;
}
