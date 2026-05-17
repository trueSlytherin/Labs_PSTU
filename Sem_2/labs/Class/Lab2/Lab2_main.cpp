#include "Equation.h"

#include <clocale>

int main() {
    setlocale(LC_ALL, "");

    double a, b, c;

    cout << "Vvedite coefficienty uravnenia:" << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << "C: ";
    cin >> c;

    cout << endl << "Constructor bez parametrov" << endl;
    equation t1;
    t1.show();

    cout << endl << "Constructor s parametrami" << endl;
    equation t2(a, b, c);
    t2.show();

    cout << endl << "Constructor copirovania" << endl;
    equation t3 = t2;
    t3.set_A(t3.get_A() + 100.0);
    t3.set_B(t3.get_B() + 100.0);
    t3.set_C(t3.get_C() + 100.0);
    t3.show();

    cout << endl << "Peredacha objecta v functiu po znacheniu" << endl;
    print_equation(t3);

    cout << endl << "Vozvrat objecta iz functii" << endl;
    equation t4 = make_equation();
    t4.show();

    return 0;
}
