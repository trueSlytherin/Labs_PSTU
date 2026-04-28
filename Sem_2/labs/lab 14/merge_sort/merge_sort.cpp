#include <iostream>
#include <ctime>

using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = left;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArr[leftIndex] <= rightArr[rightIndex]) {
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else {
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftSize) {
        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightSize) {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(int* arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main() {
    srand(time(0));

    int size = 10;
    int* arr = new int[size];

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101;
        cout << arr[i] << " ";
    }

    cout << endl;

    merge_sort(arr, 0, size - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;
    return 0;
}
