#include "LinearEquation.h"

#include <iomanip>
#include <iostream>

namespace {
    void PrintRoot(const LinearEquation& equation, const char* name) {
        if (name != nullptr && name[0] != '\0') {
            std::cout << name << ": ";
        }

        equation.Show();

        if (equation.HasUniqueRoot()) {
            std::cout << "Root: x = " << equation.Root() << "\n\n";
        } else if (equation.IsIdentity()) {
            std::cout << "The equation has infinitely many roots.\n\n";
        } else {
            std::cout << "The equation has no roots.\n\n";
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(4);

    LinearEquation a;
    LinearEquation b;

    a.Init(3.0, -12.0);

    std::cout << "Enter coefficients for equation B\n";
    b.Read();

    PrintRoot(a, "A");
    PrintRoot(b, "B");

    LinearEquation* pointerEquation = new LinearEquation;
    pointerEquation->Init(2.0, 5.0);
    PrintRoot(*pointerEquation, "Pointer equation");
    delete pointerEquation;

    LinearEquation equations[3];
    equations[0].Init(1.0, -7.0);
    equations[1].Init(0.0, 4.0);
    equations[2].Init(0.0, 0.0);

    std::cout << "Static array\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "equations[" << i << "]: ";
        PrintRoot(equations[i], "");
    }

    LinearEquation* dynamicArray = new LinearEquation[3];
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter coefficients for dynamicArray[" << i << "]\n";
        dynamicArray[i].Read();
    }

    std::cout << "Dynamic array\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "dynamicArray[" << i << "]: ";
        PrintRoot(dynamicArray[i], "");
    }

    delete[] dynamicArray;

    double y;
    double z;
    std::cout << "Enter coefficients for equation F\n";
    std::cout << "A = ";
    std::cin >> y;
    std::cout << "B = ";
    std::cin >> z;

    LinearEquation f = MakeLinearEquation(y, z);
    PrintRoot(f, "F");

    return 0;
}
