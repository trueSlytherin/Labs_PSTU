#include "Equation.h"

equation::equation()
    : A(0.0), B(0.0), C(0.0) {
    cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

equation::equation(double a, double b, double c)
    : A(a), B(b), C(c) {
    cout << "Constructor s parametrami dlia objecta " << this << endl;
}

equation::equation(const equation& t)
    : A(t.A), B(t.B), C(t.C) {
    cout << "Constructor copirovania dlia objecta " << this << endl;
}

equation::~equation() {
    cout << "Destructor dlia objecta " << this << endl;
}

double equation::get_A() {
    return A;
}

double equation::get_B() {
    return B;
}

double equation::get_C() {
    return C;
}

void equation::set_A(double a) {
    A = a;
}

void equation::set_B(double b) {
    B = b;
}

void equation::set_C(double c) {
    C = c;
}

void equation::show() {
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;
}

equation make_equation() {
    double a, b, c;

    cout << "Vvedite coefficient A: ";
    cin >> a;
    cout << "Vvedite coefficient B: ";
    cin >> b;
    cout << "Vvedite coefficient C: ";
    cin >> c;

    equation t(a, b, c);
    return t;
}

void print_equation(equation t) {
    t.show();
}
