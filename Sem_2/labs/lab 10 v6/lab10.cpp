#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** a = new int* [rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[cols];
    }

    cout << "\nИсходный массив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = rand() % 100;
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    int del;
    cout << "\nВведите номер удаляемой строки от 1 до " << rows << ": ";
    cin >> del;

    if (del < 1 || del > rows) {
        cout << "Неверный номер строки!" << endl;
        for (int i = 0; i < rows; i++) {
            delete[] a[i];
        }
        delete[] a;
        return 1;
    }

    del = del - 1;

    int** b = new int* [rows - 1];
    for (int i = 0; i < rows - 1; i++) {
        b[i] = new int[cols];
    }

    for (int i = 0, k = 0; i < rows; i++) {
        if (i != del) {
            for (int j = 0; j < cols; j++) {
                b[k][j] = a[i][j];
            }
            k++;
        }
    }

    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }
    delete[] a;

    cout << "\nМассив после удаления строки:\n";
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < rows - 1; i++) {
        delete[] b[i];
    }
    delete[] b;

    return 0;
}
