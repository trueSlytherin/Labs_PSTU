#include "Money.h"

#include <clocale>

int main() {
    setlocale(LC_ALL, "");

    Money a;
    Money b;
    Money c;

    cout << "Vvedite pervuyu denezhnuyu summu:" << endl;
    cin >> a;

    cout << "Vvedite vtoruyu denezhnuyu summu:" << endl;
    cin >> b;

    cout << endl << "Pervaya summa: " << a << endl;
    cout << "Vtoraya summa: " << b << endl;

    cout << endl << "Constructor s parametrami" << endl;
    Money d(12, 75);
    d.show();

    cout << endl << "Constructor copirovania" << endl;
    Money e = d;
    e.show();

    cout << endl << "Operacia prisvaivania" << endl;
    c = a;
    cout << "c = " << c << endl;

    cout << endl << "Slozhenie denezhnyh summ" << endl;
    c = a + b;
    cout << "a + b = " << c << endl;

    cout << endl << "Vychitanie denezhnyh summ" << endl;
    c = a - b;
    cout << "a - b = " << c << endl;

    return 0;
}
