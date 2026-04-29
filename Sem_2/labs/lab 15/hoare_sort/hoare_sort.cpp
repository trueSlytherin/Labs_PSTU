#include <iostream>
#include <windows.h>
#include <utility>

using namespace std;

int partitionHoare(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSortHoare(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionHoare(arr, low, high);
        quickSortHoare(arr, low, pi);
        quickSortHoare(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int arr[] = { 6, 2, 3, 5, 1, 4, 12, 8, 14, 0, 9, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    quickSortHoare(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
