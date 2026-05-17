#include "LinearEquation.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace {
    constexpr double EPS = 1e-12;
}

bool LinearEquation::IsZero(double value) {
    return std::fabs(value) < EPS;
}

LinearEquation::LinearEquation() {
    Init(0.0, 0.0);
}

LinearEquation::LinearEquation(double a, double b) {
    Init(a, b);
}

void LinearEquation::Init(double a, double b) {
    first = a;
    second = b;
}

void LinearEquation::Read() {
    std::cout << "A = ";
    std::cin >> first;

    std::cout << "B = ";
    std::cin >> second;
}

void LinearEquation::Show() const {
    std::cout << "Equation: y = " << first << " * x";

    if (second >= 0.0) {
        std::cout << " + " << second;
    } else {
        std::cout << " - " << -second;
    }

    std::cout << '\n';
}

double LinearEquation::GetFirst() const {
    return first;
}

double LinearEquation::GetSecond() const {
    return second;
}

void LinearEquation::SetFirst(double a) {
    first = a;
}

void LinearEquation::SetSecond(double b) {
    second = b;
}

bool LinearEquation::HasUniqueRoot() const {
    return !IsZero(first);
}

bool LinearEquation::IsIdentity() const {
    return IsZero(first) && IsZero(second);
}

double LinearEquation::Root() const {
    if (!HasUniqueRoot()) {
        throw std::domain_error("Coefficient A must not be zero.");
    }

    return -second / first;
}

LinearEquation MakeLinearEquation(double a, double b) {
    LinearEquation equation;
    equation.Init(a, b);
    return equation;
}
