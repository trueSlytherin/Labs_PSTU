#include <clocale>
#include <iostream>

#include "Money.h"
#include "Set.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    cout << "Shablon Set<int>" << endl;
    Set<int> a(5, 0);
    cin >> a;
    cout << "a = " << a << endl;
    cout << "size = " << a() << endl;
    cout << "a[2] = " << a[2] << endl;

    Set<int> b(3, 0);
    cout << "Vvedite elementi mnozhestva b:" << endl;
    cin >> b;
    cout << "b = " << b << endl;

    Set<int> c;
    c = a + b;
    cout << "a + b = " << c << endl;

    cout << endl << "Shablon Set<float>" << endl;
    Set<float> f;
    f.Add(1.5f);
    f.Add(2.5f);
    f.Add(3.5f);
    cout << "f = " << f << endl;
    f[1] = 2.5f;
    cout << "f = " << f << endl;
    cout << "size = " << f() << endl;

    cout << endl << "Shablon Set<double>" << endl;
    Set<double> d1;
    d1.Add(1.1);
    d1.Add(2.2);
    d1.Add(3.3);

    Set<double> d2;
    d2.Add(3.3);
    d2.Add(4.4);
    Set<double> d3;
    d3 = d1 + d2;
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "d1 + d2 = " << d3 << endl;

    cout << endl << "Shablon Set<Money>" << endl;
    Money m1(10, 50);
    Set<Money> money1(2, m1);
    cout << "Vvedite elementi money1:" << endl;
    cin >> money1;
    cout << "money1 = " << money1 << endl;
    cout << "size = " << money1() << endl;
    cout << "money1[0] = " << money1[0] << endl;

    Money m2(5, 25);
    Set<Money> money2(2, m2);
    cout << "Vvedite elementi money2:" << endl;
    cin >> money2;
    cout << "money2 = " << money2 << endl;

    Set<Money> money3;
    money3 = money1 + money2;
    cout << "money1 + money2 = " << money3 << endl;

    return 0;
}
