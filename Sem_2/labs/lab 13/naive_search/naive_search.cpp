#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int* naiveSearch(string text, string pattern, int& outCount) {
    outCount = 0;

    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n)
        return nullptr;

    int* tmpEntr = new int[n - m + 1];

    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            tmpEntr[outCount] = i;
            outCount++;
        }
    }

    if (outCount == 0) {
        delete[] tmpEntr;
        return nullptr;
    }

    int* properEntr = new int[outCount];

    for (int i = 0; i < outCount; i++) {
        properEntr[i] = tmpEntr[i];
    }

    delete[] tmpEntr;
    return properEntr;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    string text = "AABAACAADAABAAABAA";
    string pattern = "BAA";
    int count = 0;

    int* res = naiveSearch(text, pattern, count);

    if (res != nullptr) {
        cout << "Найдено " << count << " вхождений по индексам: ";
        printArr(res, count);
        cout << endl;
        delete[] res;
    }
    else {
        cout << "Вхождений не найдено!" << endl;
    }

    return 0;
}
