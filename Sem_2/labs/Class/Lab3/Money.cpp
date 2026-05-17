#include "Money.h"

void Money::normalization() {
    long total = rub * 100 + kop;
    rub = total / 100;
    kop = total % 100;
}

Money::Money() {
    rub = 0;
    kop = 0;
}

Money::Money(long r, int k) {
    rub = r;
    kop = k;
    normalization();
}

Money::Money(const Money& t) {
    rub = t.rub;
    kop = t.kop;
}

Money::~Money() {
}

long Money::get_rub() {
    return rub;
}

int Money::get_kop() {
    return kop;
}

void Money::set_rub(long r) {
    rub = r;
}

void Money::set_kop(int k) {
    kop = k;
    normalization();
}

void Money::show() {
    cout << *this << endl;
}

Money& Money::operator=(const Money& t) {
    if (this == &t) {
        return *this;
    }

    rub = t.rub;
    kop = t.kop;
    return *this;
}

Money Money::operator+(const Money& t) {
    Money p;
    p.rub = rub + t.rub;
    p.kop = kop + t.kop;
    p.normalization();
    return p;
}

Money Money::operator-(const Money& t) {
    Money p;
    p.rub = rub - t.rub;
    p.kop = kop - t.kop;
    p.normalization();
    return p;
}

istream& operator>>(istream& in, Money& t) {
    cout << "rub = ";
    in >> t.rub;
    cout << "kop = ";
    in >> t.kop;
    t.normalization();
    return in;
}

ostream& operator<<(ostream& out, const Money& t) {
    long total = t.rub * 100 + t.kop;

    if (total < 0) {
        out << "-";
        total = -total;
    }

    out << total / 100 << ",";

    if (total % 100 < 10) {
        out << "0";
    }

    out << total % 100;
    return out;
}
