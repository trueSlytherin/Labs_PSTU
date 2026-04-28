#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Schoolboy {
    string lastName;
    string firstName;
    string patronymic;
    string className;
    string phone;
    int math;
    int physics;
    int russian;
    int literature;

    void print() {
        cout << "Фамилия: " << lastName << endl;
        cout << "Имя: " << firstName << endl;
        cout << "Отчество: " << patronymic << endl;
        cout << "Класс: " << className << endl;
        cout << "Телефон: " << phone << endl;
        cout << "Математика: " << math << endl;
        cout << "Физика: " << physics << endl;
        cout << "Русский язык: " << russian << endl;
        cout << "Литература: " << literature << endl;
        cout << endl;
    }
};

Schoolboy* deleteBad(Schoolboy* boys, int& size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (boys[i].math == 2 || boys[i].physics == 2 ||
            boys[i].russian == 2 || boys[i].literature == 2) {
            count++;
        }
    }

    Schoolboy* newBoys = new Schoolboy[size - count];
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (boys[i].math != 2 && boys[i].physics != 2 &&
            boys[i].russian != 2 && boys[i].literature != 2) {
            newBoys[j] = boys[i];
            j++;
        }
    }

    delete[] boys;
    size -= count;
    return newBoys;
}

Schoolboy* addToBeginning(Schoolboy* boys, int& size) {
    Schoolboy newBoy;

    cout << "Введите данные нового школьника:" << endl;
    cout << "Фамилия: ";
    getline(cin, newBoy.lastName);
    cout << "Имя: ";
    getline(cin, newBoy.firstName);
    cout << "Отчество: ";
    getline(cin, newBoy.patronymic);
    cout << "Класс: ";
    getline(cin, newBoy.className);
    cout << "Телефон: ";
    getline(cin, newBoy.phone);
    cout << "Оценка по математике: ";
    cin >> newBoy.math;
    cout << "Оценка по физике: ";
    cin >> newBoy.physics;
    cout << "Оценка по русскому языку: ";
    cin >> newBoy.russian;
    cout << "Оценка по литературе: ";
    cin >> newBoy.literature;
    cin.ignore();

    Schoolboy* newBoys = new Schoolboy[size + 1];
    newBoys[0] = newBoy;

    for (int i = 0; i < size; i++) {
        newBoys[i + 1] = boys[i];
    }

    delete[] boys;
    size++;
    return newBoys;
}

void saveToFile(string fileName, Schoolboy* boys, int size) {
    ofstream file(fileName);

    for (int i = 0; i < size; i++) {
        file << boys[i].lastName << endl;
        file << boys[i].firstName << endl;
        file << boys[i].patronymic << endl;
        file << boys[i].className << endl;
        file << boys[i].phone << endl;
        file << boys[i].math << endl;
        file << boys[i].physics << endl;
        file << boys[i].russian << endl;
        file << boys[i].literature << endl;
    }

    file.close();
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    ifstream file("schoolboys.txt");

    int size = 5;
    Schoolboy* boys = new Schoolboy[size];

    for (int i = 0; i < size; i++) {
        getline(file, boys[i].lastName);
        getline(file, boys[i].firstName);
        getline(file, boys[i].patronymic);
        getline(file, boys[i].className);
        getline(file, boys[i].phone);
        file >> boys[i].math;
        file >> boys[i].physics;
        file >> boys[i].russian;
        file >> boys[i].literature;
        file.ignore();
    }

    file.close();

    cout << "=== Исходные данные ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Школьник " << i + 1 << ":" << endl;
        boys[i].print();
    }

    boys = deleteBad(boys, size);

    cout << "=== После удаления школьников с двойками ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Школьник " << i + 1 << ":" << endl;
        boys[i].print();
    }

    boys = addToBeginning(boys, size);

    cout << "=== После добавления нового школьника в начало ===" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Школьник " << i + 1 << ":" << endl;
        boys[i].print();
    }

    saveToFile("schoolboys.txt", boys, size);

    delete[] boys;
    return 0;
}
