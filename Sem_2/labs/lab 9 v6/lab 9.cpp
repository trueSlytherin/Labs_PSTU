#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>

using namespace std;

void createFile() {
    FILE* f = fopen("F1.txt", "w");

    if (f == NULL) {
        cout << "Ошибка при создании файла F1.txt" << endl;
        return;
    }

    fputs("Apple is red\n", f);
    fputs("Banana is yellow\n", f);
    fputs("Cat sits on the sofa\n", f);
    fputs("Dog runs fast\n", f);
    fputs("Elephant is big\n", f);
    fputs("Fish swims in water\n", f);
    fputs("Green grass grows\n", f);
    fputs("House is near the lake\n", f);
    fputs("Ice is cold\n", f);
    fputs("Juice is tasty\n", f);

    fclose(f);
    cout << "Файл F1.txt создан." << endl;
}

int isConsonant(char c) {
    if (c >= 'A' && c <= 'Z')
        c = c + 32;

    return c == 'b' || c == 'c' || c == 'd' || c == 'f' ||
        c == 'g' || c == 'h' || c == 'j' || c == 'k' ||
        c == 'l' || c == 'm' || c == 'n' || c == 'p' ||
        c == 'q' || c == 'r' || c == 's' || c == 't' ||
        c == 'v' || c == 'w' || c == 'x' || c == 'z';
}

int countConsonants() {
    FILE* f = fopen("F2.txt", "r");

    if (f == NULL) {
        cout << "Ошибка при открытии файла F2.txt" << endl;
        return -1;
    }

    char buf[256];
    int count = 0;

    while (fgets(buf, 256, f) != NULL) {
        for (int i = 0; buf[i] != '\0'; i++) {
            if (isConsonant(buf[i])) {
                count++;
            }
        }
    }

    fclose(f);
    return count;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    createFile();
    cout << endl;

    int N, K;
    cout << "Введите номер начальной строки N: ";
    cin >> N;
    cout << "Введите номер конечной строки K: ";
    cin >> K;

    if (N > K || N <= 0) {
        cout << "Неверно заданы границы строк." << endl;
        return 0;
    }

    FILE* in = fopen("F1.txt", "r");
    FILE* out = fopen("F2.txt", "w");

    if (in == NULL || out == NULL) {
        cout << "Ошибка при открытии файлов." << endl;
        return 0;
    }

    char buf[256];
    int lineNum = 0;
    int copiedCount = 0;

    while (fgets(buf, 256, in) != NULL) {
        lineNum++;

        if (lineNum >= N && lineNum <= K) {
            fputs(buf, out);
            copiedCount++;
        }
    }

    fclose(in);
    fclose(out);

    cout << "Скопировано строк в F2.txt: " << copiedCount << endl;

    int consonants = countConsonants();
    if (consonants != -1) {
        cout << "Количество согласных букв в файле F2.txt: " << consonants << endl;
    }

    return 0;
}
