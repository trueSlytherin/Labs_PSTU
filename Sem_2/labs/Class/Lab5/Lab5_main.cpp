#include <clocale>
#include <iostream>

#include "Long.h"
#include "Pair.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    cout << "Rabota s klassom Pair" << endl;
    Pair a;
    cin >> a;
    cout << a;

    Pair b(1, 2);
    Pair c = a + b;
    cout << "a + b:" << endl;
    cout << c;

    Object* p = &a;
    cout << "Vyvod Pair cherez ukazatel Object*" << endl;
    p->Show();

    cout << endl << "Rabota s klassom Long" << endl;
    Long x;
    cin >> x;
    cout << x;

    Long y(3, 4);
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

    p = &x;
    cout << "Vyvod Long cherez ukazatel Object*" << endl;
    p->Show();

    cout << endl << "Rabota s klassom Vector" << endl;
    Vector v(5);
    v.Add(&a);
    v.Add(&x);
    v.Add(&y);

    cout << v;

    return 0;
}
