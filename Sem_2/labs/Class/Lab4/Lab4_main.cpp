#include <clocale>
#include <iostream>

#include "Long.h"
#include "Pair.h"

using namespace std;

void f1(Pair& p) {
    p.set_first(100);
    cout << p;
}

Pair f2() {
    Long l(10, 20);
    return l;
}

int main() {
    setlocale(LC_ALL, "");

    cout << "Rabota s bazovym klassom Pair" << endl;
    Pair a;
    cin >> a;
    cout << a;

    Pair b(1, 2);
    cout << "b:" << endl;
    cout << b;

    Pair c = a + b;
    cout << "a + b:" << endl;
    cout << c;

    cout << endl << "Rabota s proizvodnym klassom Long" << endl;
    Long x;
    cin >> x;
    cout << x;

    Long y(3, 4);
    cout << "y:" << endl;
    cout << y;

    Long z;
    z = x + y;
    cout << "x + y:" << endl;
    cout << z;

    z = x - y;
    cout << "x - y:" << endl;
    cout << z;

    z = x * y;
    cout << "x * y:" << endl;
    cout << z;

    cout << endl << "Princip podstanovki" << endl;
    f1(x);

    Pair p;
    p = f2();
    cout << p;

    return 0;
}
