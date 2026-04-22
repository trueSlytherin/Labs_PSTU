
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    unsigned int size;
};

void init(List* list) {
    list->head = nullptr;
    list->size = 0;
}

void pushFront(List* list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void printList(List* list) {
    if (list->head == nullptr) {
        cout << "Список пуст." << endl;
        return;
    }

    Node* p = list->head;
    int i = 1;
    while (p != nullptr) {
        cout << i << ") " << p->data << endl;
        p = p->next;
        i++;
    }
}

void deleteByNumber(List* list, unsigned int num) {
    if (list->head == nullptr || num < 1 || num > list->size) {
        cout << "Удаление невозможно." << endl;
        return;
    }

    if (num == 1) {
        Node* tmp = list->head;
        list->head = list->head->next;
        delete tmp;
        list->size--;
        return;
    }

    Node* prev = list->head;
    for (unsigned int i = 1; i < num - 1; i++) {
        prev = prev->next;
    }

    Node* del = prev->next;
    prev->next = del->next;
    delete del;
    list->size--;
}

void writeToFile(List* list, const char* filename) {
    ofstream file(filename);
    Node* p = list->head;

    while (p != nullptr) {
        file << p->data << endl;
        p = p->next;
    }

    file.close();
}

void clearList(List* list) {
    Node* p = list->head;

    while (p != nullptr) {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }

    list->head = nullptr;
    list->size = 0;
}

void restoreFromFile(List* list, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    clearList(list);

    int value;
    while (file >> value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (list->head == nullptr) {
            list->head = newNode;
        } else {
            Node* p = list->head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = newNode;
        }
        list->size++;
    }

    file.close();
}

int main() {
    List list;
    init(&list);

    pushFront(&list, 50);
    pushFront(&list, 40);
    pushFront(&list, 30);
    pushFront(&list, 20);
    pushFront(&list, 10);

    cout << "Исходный односвязный список:" << endl;
    printList(&list);

    unsigned int num;
    cout << "\nВведите номер удаляемого элемента: ";
    cin >> num;
    deleteByNumber(&list, num);

    cout << "\nПосле удаления:" << endl;
    printList(&list);

    int x;
    cout << "\nВведите элемент для добавления в начало: ";
    cin >> x;
    pushFront(&list, x);

    cout << "\nПосле добавления в начало:" << endl;
    printList(&list);

    writeToFile(&list, "list1.txt");
    clearList(&list);

    cout << "\nПосле уничтожения:" << endl;
    printList(&list);

    restoreFromFile(&list, "list1.txt");
    cout << "\nПосле восстановления из файла:" << endl;
    printList(&list);

    clearList(&list);
    return 0;
}
