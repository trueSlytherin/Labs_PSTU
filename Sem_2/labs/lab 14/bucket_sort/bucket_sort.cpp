#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void bucketSort(int arr[], int n) {
    if (n <= 1)
        return;

    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 100;

    int buckets[BUCKET_NUM][BUCKET_SIZE];
    int bucketSizes[BUCKET_NUM] = {0};

    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (BUCKET_NUM * arr[i]) / (maxVal + 1);

        if (bucketSizes[bucketIndex] < BUCKET_SIZE) {
            buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
            bucketSizes[bucketIndex]++;
        }
    }

    for (int i = 0; i < BUCKET_NUM; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
    }

    int index = 0;
    for (int i = 0; i < BUCKET_NUM; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    srand(time(0));

    int arr[] = {42, 37, 89, 12, 56, 73, 25, 98, 31, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
