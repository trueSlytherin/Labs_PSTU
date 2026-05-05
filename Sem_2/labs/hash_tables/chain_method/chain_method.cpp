#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Record {
    string fio;
    string address;
    long long phone;
};

struct Node {
    Record data;
    Node* next;
};

class HashTableChain {
private:
    int size;
    Node** table;

public:
    HashTableChain(int s) {
        size = s;
        table = new Node * [size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTableChain() {
        clear();
        delete[] table;
    }

    int hashFunction(long long key) {
        return key % size;
    }

    void insert(const Record& rec) {
        int index = hashFunction(rec.phone);

        Node* current = table[index];
        while (current != nullptr) {
            if (current->data.phone == rec.phone) {
                current->data = rec;
                cout << "Данные обновлены.\n";
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node;
        newNode->data = rec;
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Запись добавлена.\n";
    }

    void search(long long key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->data.phone == key) {
                cout << "Найдена запись:\n";
                cout << "ФИО: " << current->data.fio << endl;
                cout << "Адрес: " << current->data.address << endl;
                cout << "Телефон: " << current->data.phone << endl;
                return;
            }
            current = current->next;
        }

        cout << "Запись не найдена.\n";
    }

    void remove(long long key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data.phone == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Запись удалена.\n";
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Запись не найдена.\n";
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* current = table[i];

            if (current == nullptr) {
                cout << "пусто";
            }

            while (current != nullptr) {
                cout << "[" << current->data.fio << ", "
                    << current->data.address << ", "
                    << current->data.phone << "]";
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }

            cout << endl;
        }
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            table[i] = nullptr;
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

            insert(rec);
        }

        file.close();
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    HashTableChain ht(10);

    ht.loadFromFile("input.txt");

    cout << "\nХэш-таблица (chain):\n";
    ht.print();

    cout << "\nПоиск:\n";
    ht.search(89004567890);

    cout << "\nУдаление:\n";
    ht.remove(89004567890);

    cout << "\nПосле удаления:\n";
    ht.print();

    return 0;
}
