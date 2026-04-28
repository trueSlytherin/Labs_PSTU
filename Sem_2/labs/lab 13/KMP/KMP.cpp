#include <iostream>
#include <string>

using namespace std;

void computePrefix(string pattern, int* lps) {
    int length = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int* KMPSearchAll(string text, string pattern, int& count) {
    count = 0;

    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n)
        return nullptr;

    int* lps = new int[m];
    computePrefix(pattern, lps);

    int* temp = new int[n];
    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            temp[count] = i - j;
            count++;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    delete[] lps;

    if (count == 0) {
        delete[] temp;
        return nullptr;
    }

    int* result = new int[count];
    for (int k = 0; k < count; k++) {
        result[k] = temp[k];
    }

    delete[] temp;
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
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABAB";
    int count = 0;

    int* matches = KMPSearchAll(text, pattern, count);

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
