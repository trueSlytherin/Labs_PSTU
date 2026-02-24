#include <iostream>
using namespace std;

// ===== а) Вычитание вещественных чисел =====
double sub(double a, double b)
{
    return a - b;
}

// ===== б) Вычитание комплексных чисел =====
void sub(double a1, double b1, double a2, double b2)
{
    double real = a1 - a2;      // действительная часть
    double imag = b1 - b2;      // мнимая часть

    cout << "Результат: " << real;

    if (imag >= 0)
        cout << " + " << imag << "i" << endl;
    else
        cout << " - " << -imag << "i" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // ===== Вещественные числа =====
    double x, y;
    cout << "Введите два вещественных числа: ";
    cin >> x >> y;

    cout << "Результат вычитания: " << sub(x, y) << endl;

    cout << endl;

    // ===== Комплексные числа =====
    double r1, i1, r2, i2;

    cout << "Введите действительную и мнимую часть первого числа: ";
    cin >> r1 >> i1;

    cout << "Введите действительную и мнимую часть второго числа: ";
    cin >> r2 >> i2;

    sub(r1, i1, r2, i2);

    return 0;
}
