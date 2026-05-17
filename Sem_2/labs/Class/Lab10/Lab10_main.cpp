#include <clocale>
#include <iostream>

#include "Money.h"
#include "file_work.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    Money value;
    int k;
    int c;
    char file_name[30];

    do {
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete records equal value";
        cout << "\n4. Add K records after record number N";
        cout << "\n5. Change records equal value";
        cout << "\n0. Exit\n";
        cin >> c;

        switch (c) {
        case 1:
            cout << "file name? ";
            cin >> file_name;
            k = make_file(file_name);
            if (k < 0) {
                cout << "Can't make file\n";
            }
            break;

        case 2:
            cout << "file name? ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0) {
                cout << "Empty file\n";
            }
            if (k < 0) {
                cout << "Can't read file\n";
            }
            break;

        case 3:
            cout << "file name? ";
            cin >> file_name;
            cout << "Value for delete:" << endl;
            cin >> value;
            k = del_file(file_name, value);
            if (k < 0) {
                cout << "Can't read file\n";
            } else {
                cout << "Deleted records: " << k << endl;
            }
            break;

        case 4: {
            int number;
            int count;

            cout << "file name? ";
            cin >> file_name;
            cout << "record number? ";
            cin >> number;
            cout << "K? ";
            cin >> count;

            k = add_file(file_name, number, count);
            if (k < 0) {
                cout << "Can't read file\n";
            } else if (k == 0) {
                cout << "No such record\n";
            } else {
                cout << "Added records: " << k << endl;
            }
            break;
        }

        case 5:
            cout << "file name? ";
            cin >> file_name;
            cout << "Value for change:" << endl;
            cin >> value;
            k = change_file(file_name, value);
            if (k < 0) {
                cout << "Can't read file\n";
            } else {
                cout << "Changed records: " << k << endl;
            }
            break;
        }
    } while (c != 0);

    return 0;
}
