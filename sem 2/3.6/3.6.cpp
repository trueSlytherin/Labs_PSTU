#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    const int k = 2;

    int arr[n] = { 1, 2, 3, 6, 5, 6, 9, 12, 10, 7 };
    int tmp[k];

    // сохраняем первые k элементов
    for (int i = 0; i < k; i++) {
        tmp[i] = arr[i];
    }

    // сдвигаем массив влево на k
    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[i + k];
    }

    // возвращаем сохранённые элементы в конец
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = tmp[i];
    }

    // вывод
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
