#include <iostream>
#include <windows.h>
using namespace std;

int interpolationSearch(int arr[], int low, int high, int x) {
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high || arr[low] == arr[high]) {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

void printArr(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 50;
    printArr(arr, n);
    cout << endl;
    int res = interpolationSearch(arr, 0, n - 1, x);
    if (res == -1)
        cout << "Элемент " << x << " не найден" << endl;
    else
        cout << "Элемент " << x << " найден по индексу " << res << endl;
    return 0;
}
