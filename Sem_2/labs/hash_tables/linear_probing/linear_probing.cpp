#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Record {
    string fio;
    string address;
    long long phone;
    bool occupied;
    bool deleted;
};

class HashTableLinear {
private:
    int size;
    Record* table;

public:
    HashTableLinear(int s) {
        size = s;
        table = new Record[size];

        for (int i = 0; i < size; i++) {
            table[i].fio = "";
            table[i].address = "";
            table[i].phone = 0;
            table[i].occupied = false;
            table[i].deleted = false;
        }
    }

    ~HashTableLinear() {
        delete[] table;
    }

    int hashFunction(long long key) {
        return key % size;
    }

    void insert(const Record& rec) {
        int index = hashFunction(rec.phone);
        int start = index;

        while (table[index].occupied && !table[index].deleted) {
            if (table[index].phone == rec.phone) {
                table[index].fio = rec.fio;
                table[index].address = rec.address;
                cout << "Данные обновлены.\n";
                return;
            }

            index = (index + 1) % size;
            if (index == start) {
                cout << "Таблица заполнена.\n";
                return;
            }
        }

        table[index] = rec;
        table[index].occupied = true;
        table[index].deleted = false;

        cout << "Запись добавлена.\n";
    }

    void search(long long key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].occupied) {
            if (!table[index].deleted && table[index].phone == key) {
                cout << "Найдена запись:\n";
                cout << "ФИО: " << table[index].fio << endl;
                cout << "Адрес: " << table[index].address << endl;
                cout << "Телефон: " << table[index].phone << endl;
                return;
            }

            index = (index + 1) % size;
            if (index == start) {
                break;
            }
        }

        cout << "Запись не найдена.\n";
    }

    void remove(long long key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index].occupied) {
            if (!table[index].deleted && table[index].phone == key) {
                table[index].deleted = true;
                cout << "Запись удалена.\n";
                return;
            }

            index = (index + 1) % size;
            if (index == start) {
                break;
            }
        }

        cout << "Запись не найдена.\n";
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";

            if (!table[i].occupied) {
                cout << "пусто";
            } else if (table[i].deleted) {
                cout << "удалено";
            } else {
                cout << "[" << table[i].fio << ", "
                     << table[i].address << ", "
                     << table[i].phone << "]";
            }

            cout << endl;
        }
    }

    void loadFromFile(const string& fileName) {
        ifstream file(fileName);

        if (!file.is_open()) {
            cout << "Ошибка открытия файла.\n";
            return;
        }

        Record rec;
        while (getline(file, rec.fio, ';')) {
            getline(file, rec.address, ';');
            file >> rec.phone;
            file.ignore();

            rec.occupied = true;
            rec.deleted = false;

            insert(rec);
        }

        file.close();
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    HashTableLinear ht(20);

    ht.loadFromFile("input.txt");

    cout << "\nХэш-таблица (linear probing):\n";
    ht.print();

    cout << "\nПоиск:\n";
    ht.search(89004567890);

    cout << "\nУдаление:\n";
    ht.remove(89004567890);

    cout << "\nПосле удаления:\n";
    ht.print();

    return 0;
}
