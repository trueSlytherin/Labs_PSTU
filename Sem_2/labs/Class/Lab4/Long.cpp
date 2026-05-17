#include "Long.h"

Long::Long(void) : Pair() {
}

Long::Long(int h, int l) : Pair(h, l) {
}

Long::Long(const Long& l) : Pair(l) {
}

Long::~Long(void) {
}

int Long::get_high() {
    return first;
}

int Long::get_low() {
    return second;
}

void Long::set_high(int h) {
    first = h;
}

void Long::set_low(int l) {
    second = l;
}

Long& Long::operator=(const Long& l) {
    if (this == &l) {
        return *this;
    }

    first = l.first;
    second = l.second;
    return *this;
}

Long Long::operator+(const Long& l) {
    Long t;
    t.first = first + l.first;
    t.second = second + l.second;
    return t;
}

Long Long::operator-(const Long& l) {
    Long t;
    t.first = first - l.first;
    t.second = second - l.second;
    return t;
}

Long Long::operator*(const Long& l) {
    Long t;
    t.first = first * l.first;
    t.second = second * l.second;
    return t;
}

istream& operator>>(istream& in, Long& l) {
    cout << "high = ";
    in >> l.first;
    cout << "low = ";
    in >> l.second;
    return in;
}

ostream& operator<<(ostream& out, const Long& l) {
    out << "high = " << l.first << endl;
    out << "low = " << l.second << endl;
    return out;
}
