#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Data {
    string name;
    long long passport;
    string address;
};

struct Node {
    Data data;
    Node* next;
};

class HashTable {
private:
    int size;
    Node** table;

public:
    HashTable(int s) {
        size = s;
        table = new Node * [size];

        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        clear();
        delete[] table;
    }

    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<unsigned char>(c);
        }
        return sum % size;
    }

    void insert(const Data& value) {
        int index = hashFunction(value.name);

        Node* current = table[index];
        while (current != nullptr) {
            if (current->data.name == value.name) {
                current->data = value;
                cout << "Данные обновлены для: " << value.name << endl;
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Добавлен: " << value.name << endl;
    }

    void search(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->data.name == key) {
                cout << "Найден: "
                    << current->data.name << ", "
                    << current->data.passport << ", "
                    << current->data.address << endl;
                return;
            }
            current = current->next;
        }

        cout << "Элемент с именем " << key << " не найден." << endl;
    }

    void remove(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data.name == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }

                delete current;
                cout << "Удален: " << key << endl;
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Элемент с именем " << key << " не найден." << endl;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";

            Node* current = table[i];

            if (current == nullptr) {
                cout << "пусто";
            }
            else {
                while (current != nullptr) {
                    cout << "["
                        << current->data.name << ", "
                        << current->data.passport << ", "
                        << current->data.address << "]";

                    if (current->next != nullptr) {
                        cout << " -> ";
                    }

                    current = current->next;
                }
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
            cout << "Ошибка открытия файла!" << endl;
            return;
        }

        Data temp;
        while (file >> temp.name >> temp.passport >> temp.address) {
            insert(temp);
        }

        file.close();
    }
};

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    HashTable ht(10);

    ht.loadFromFile("input.txt");

    cout << "\nХэш-таблица после загрузки:\n";
    ht.print();

    cout << "\nПоиск элементов:\n";
    ht.search("Иван");
    ht.search("Мария");

    cout << "\nУдаление элемента:\n";
    ht.remove("Петр");

    cout << "\nХэш-таблица после удаления:\n";
    ht.print();

    return 0;
}
