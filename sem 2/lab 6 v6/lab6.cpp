#include <iostream>
#include <cstring>
using namespace std;

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void transformString(char s[]) {
    char result[256];
    int len = strlen(s);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (isLetter(s[i])) {
            result[k] = s[i];
            k++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (isDigit(s[i])) {
            result[k] = s[i];
            k++;
        }
    }
    result[k] = '.';
    k++;
    result[k] = '\0';

    strcpy_s(s, 256, result);
}

int main() {
    char s[256];
    cout << "Введите строку с точкой в конце:" << endl;
    cin.getline(s, 256);
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '.') {
        s[len - 1] = '\0';
    }
    cout << "Исходная строка: " << s << endl;
    transformString(s);
    cout << "Результат: " << s << endl;

    return 0;
}
