#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

void splitFile(const string& sourceFile, const string& file1, const string& file2) {
    ifstream in(sourceFile);
    ofstream out1(file1);
    ofstream out2(file2);

    if (!in.is_open() || !out1.is_open() || !out2.is_open()) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    int x;
    bool toFirst = true;

    while (in >> x) {
        if (toFirst)
            out1 << x << " ";
        else
            out2 << x << " ";

        toFirst = !toFirst;
    }

    in.close();
    out1.close();
    out2.close();
}

void sortFile(const string& fileName) {
    ifstream in(fileName);
    if (!in.is_open()) {
        cout << "Ошибка открытия файла " << fileName << endl;
        return;
    }

    vector<int> arr;
    int x;

    while (in >> x) {
        arr.push_back(x);
    }

    in.close();

    sort(arr.begin(), arr.end());

    ofstream out(fileName);
    for (int num : arr) {
        out << num << " ";
    }

    out.close();
}

void mergeFiles(const string& file1, const string& file2, const string& resultFile) {
    ifstream in1(file1);
    ifstream in2(file2);
    ofstream out(resultFile);

    if (!in1.is_open() || !in2.is_open() || !out.is_open()) {
        cout << "Ошибка открытия файлов!" << endl;
        return;
    }

    int x, y;
    bool hasX = static_cast<bool>(in1 >> x);
    bool hasY = static_cast<bool>(in2 >> y);

    while (hasX && hasY) {
        if (x <= y) {
            out << x << " ";
            hasX = static_cast<bool>(in1 >> x);
        }
        else {
            out << y << " ";
            hasY = static_cast<bool>(in2 >> y);
        }
    }

    while (hasX) {
        out << x << " ";
        hasX = static_cast<bool>(in1 >> x);
    }

    while (hasY) {
        out << y << " ";
        hasY = static_cast<bool>(in2 >> y);
    }

    in1.close();
    in2.close();
    out.close();
}

void printFile(const string& fileName) {
    ifstream in(fileName);
    int x;

    while (in >> x) {
        cout << x << " ";
    }

    cout << endl;
    in.close();
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    string mainFile = "A.txt";
    string file1 = "B.txt";
    string file2 = "C.txt";

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    ofstream out(mainFile);

    cout << "Введите числа: " << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        out << x << " ";
    }

    out.close();

    cout << "Исходный файл: ";
    printFile(mainFile);

    splitFile(mainFile, file1, file2);

    sortFile(file1);
    sortFile(file2);

    mergeFiles(file1, file2, mainFile);

    cout << "После сортировки: ";
    printFile(mainFile);

    return 0;
}
