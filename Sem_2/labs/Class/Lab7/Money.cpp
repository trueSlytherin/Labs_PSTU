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

Money::Money(const Money& m) {
    rub = m.rub;
    kop = m.kop;
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

Money& Money::operator=(const Money& m) {
    if (this == &m) {
        return *this;
    }

    rub = m.rub;
    kop = m.kop;
    return *this;
}

bool Money::operator==(const Money& m) {
    return rub == m.rub && kop == m.kop;
}

istream& operator>>(istream& in, Money& m) {
    cout << "rub = ";
    in >> m.rub;
    cout << "kop = ";
    in >> m.kop;
    m.normalization();
    return in;
}

ostream& operator<<(ostream& out, const Money& m) {
    long total = m.rub * 100 + m.kop;

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
