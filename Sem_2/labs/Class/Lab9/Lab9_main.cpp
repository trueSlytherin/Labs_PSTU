#include <clocale>
#include <iostream>

#include "Set.h"

using namespace std;

void PrintError(Error& e) {
    cout << "ERROR: ";
    e.what();
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");

    try {
        cout << "Normalnaya rabota s klassom Set" << endl;
        Set a(3);
        cin >> a;
        cout << "a = " << a << endl;
        cout << "size = " << a() << endl;

        int index;
        cout << "index = ";
        cin >> index;
        cout << "a[index] = " << a[index] << endl;

        cout << "Dobavlenie elementa operatorom ++" << endl;
        ++a;
        cout << "a = " << a << endl;

        Set b(2);
        cout << "Vvedite mnozhestvo b" << endl;
        cin >> b;
        cout << "b = " << b << endl;

        Set c;
        c = a + b;
        cout << "a + b = " << c << endl;
    }
    catch (Error& e) {
        PrintError(e);
    }

    cout << endl << "Generacia iskluchenia 1: razmer bolshe MAX_SIZE" << endl;
    try {
        Set x(MAX_SIZE + 1);
        cout << x << endl;
    }
    catch (Error& e) {
        PrintError(e);
    }

    cout << endl << "Generacia iskluchenia 2: index menshe 0" << endl;
    try {
        Set x(2);
        cin >> x;
        cout << x[-1] << endl;
    }
    catch (Error& e) {
        PrintError(e);
    }

    cout << endl << "Generacia iskluchenia 3: index bolshe razmera" << endl;
    try {
        Set x(2);
        cin >> x;
        cout << x[10] << endl;
    }
    catch (Error& e) {
        PrintError(e);
    }

    cout << endl << "Generacia iskluchenia 4: obedinenie bolshe MAX_SIZE" << endl;
    try {
        Set x;
        Set y;

        for (int i = 0; i < 20; i++) {
            x.Add(i);
        }

        for (int i = 20; i < 40; i++) {
            y.Add(i);
        }

        Set z = x + y;
        cout << z << endl;
    }
    catch (Error& e) {
        PrintError(e);
    }

    cout << endl << "Generacia iskluchenia 5: dobavlenie v polnoe mnozhestvo" << endl;
    try {
        Set x;

        for (int i = 0; i < MAX_SIZE; i++) {
            x.Add(i);
        }

        ++x;
        cout << x << endl;
    }
    catch (Error& e) {
        PrintError(e);
    }

    return 0;
}
