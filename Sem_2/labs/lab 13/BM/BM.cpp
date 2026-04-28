#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void charTable(string pattern, int m, int allChar[256]) {
    for (int i = 0; i < 256; i++) {
        allChar[i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        allChar[(unsigned char)pattern[i]] = m - 1 - i;
    }
}

int* BMsearch(string text, string pattern, int& outCount) {
    outCount = 0;

    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n)
        return nullptr;

    int allChar[256];
    charTable(pattern, m, allChar);

    int* tmpEntr = new int[n];
    int shift = 0;

    while (shift <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            tmpEntr[outCount] = shift;
            outCount++;
            shift++;
        }
        else {
            int badShift = allChar[(unsigned char)text[shift + j]];
            int move = badShift - (m - 1 - j);

            if (move < 1)
                move = 1;

            shift += move;
        }
    }

    if (outCount == 0) {
        delete[] tmpEntr;
        return nullptr;
    }

    int* result = new int[outCount];
    for (int i = 0; i < outCount; i++) {
        result[i] = tmpEntr[i];
    }

    delete[] tmpEntr;
    return result;
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

    string text = "ABABDABACDABAABCABACDABABACDABA";
    string pattern = "BACDABA";
    int count = 0;

    int* matches = BMsearch(text, pattern, count);

    if (matches != nullptr) {
        cout << "Найдено " << count << " совпадений по индексам: ";
        printArr(matches, count);
        cout << endl;
        delete[] matches;
    }
    else {
        cout << "Совпадений не найдено!" << endl;
    }

    return 0;
}
