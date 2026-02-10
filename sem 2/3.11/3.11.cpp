#include <iostream>
using namespace std;

int main() {
    const int n = 3;

    int arr[n][n] = { {1, 5, 0}, {5, 1, 5}, {0, 5, 1} };

    // обнуляем главную диагональ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                arr[i][j] = 0;
            }
        }
    }

    // вывод матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
