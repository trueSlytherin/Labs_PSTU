#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int countRuns(const char* fileName) {
    ifstream file(fileName);
    int prev, curr, runs = 0;

    if (file >> prev) {
        runs = 1;
    }

    while (file >> curr) {
        if (curr < prev) {
            runs++;
        }
        prev = curr;
    }

    file.close();
    return runs;
}

void splitFile(const char* source, const char* file1, const char* file2) {
    ifstream in(source);
    ofstream out1(file1);
    ofstream out2(file2);

    int prev, curr;
    bool toFirst = true;

    if (!(in >> prev)) return;

    if (toFirst) out1 << prev << " ";
    else out2 << prev << " ";

    while (in >> curr) {
        if (curr < prev) {
            if (toFirst) out1 << "| ";
            else out2 << "| ";
            toFirst = !toFirst;
        }

        if (toFirst) out1 << curr << " ";
        else out2 << curr << " ";

        prev = curr;
    }

    if (toFirst) out1 << "|";
    else out2 << "|";

    in.close();
    out1.close();
    out2.close();
}

bool readValue(ifstream& file, int& x, bool& endRun) {
    string s;
    if (!(file >> s)) return false;

    if (s == "|") {
        endRun = true;
        return false;
    }

    x = stoi(s);
    endRun = false;
    return true;
}

void mergeFiles(const char* file1, const char* file2, const char* result) {
    ifstream in1(file1);
    ifstream in2(file2);
    ofstream out(result);

    while (true) {
        bool end1 = false, end2 = false;
        int x, y;

        bool has1 = readValue(in1, x, end1);
        bool has2 = readValue(in2, y, end2);

        if (!has1 && !has2) break;

        while (has1 || has2) {
            if (!has2 || (has1 && x <= y)) {
                out << x << " ";
                has1 = readValue(in1, x, end1);
            }
            else {
                out << y << " ";
                has2 = readValue(in2, y, end2);
            }

            if (!has1 && end1) {
                while (has2) {
                    out << y << " ";
                    has2 = readValue(in2, y, end2);
                }
                break;
            }

            if (!has2 && end2) {
                while (has1) {
                    out << x << " ";
                    has1 = readValue(in1, x, end1);
                }
                break;
            }
        }
    }

    in1.close();
    in2.close();
    out.close();
}

void clearMarks(const char* fileName) {
    ifstream in(fileName);
    ofstream out("temp.txt");

    string s;
    while (in >> s) {
        if (s != "|") {
            out << s << " ";
        }
    }

    in.close();
    out.close();

    remove(fileName);
    rename("temp.txt", fileName);
}

void naturalMergeSort(const char* fileName) {
    while (countRuns(fileName) > 1) {
        splitFile(fileName, "B.txt", "C.txt");
        mergeFiles("B.txt", "C.txt", fileName);
        clearMarks(fileName);
    }
}

void printFile(const char* fileName) {
    ifstream file(fileName);
    int x;

    while (file >> x) {
        cout << x << " ";
    }

    cout << endl;
    file.close();
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    const char* fileName = "A.txt";
    ofstream out(fileName);

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    cout << "Введите числа:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        out << x << " ";
    }
    out.close();

    cout << "Исходный файл: ";
    printFile(fileName);

    naturalMergeSort(fileName);

    cout << "После сортировки: ";
    printFile(fileName);

    return 0;
}
