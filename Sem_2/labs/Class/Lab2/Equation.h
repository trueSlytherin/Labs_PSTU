#pragma once

#include <iostream>

using namespace std;

class equation {
private:
    double A;
    double B;
    double C;

public:
    equation();
    equation(double a, double b, double c);
    equation(const equation& t);
    ~equation();

    double get_A();
    double get_B();
    double get_C();

    void set_A(double a);
    void set_B(double b);
    void set_C(double c);

    void show();
};

equation make_equation();
void print_equation(equation t);
