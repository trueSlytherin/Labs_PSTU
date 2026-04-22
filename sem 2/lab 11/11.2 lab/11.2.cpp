#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
    Node* tail;
    unsigned int size;
};

void init(List* list) {
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
}

void pushFront(List* list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = list->head;

    if (list->head != nullptr) {
        list->head->prev = newNode;
    } else {
        list->tail = newNode;
    }

    list->head = newNode;
    list->size++;
}

void pushBack(List* list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = list->tail;

    if (list->tail != nullptr) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }

    list->tail = newNode;
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

    Node* cur = list->head;
    for (unsigned int i = 1; i < num; i++) {
        cur = cur->next;
    }

    if (cur->prev != nullptr) {
        cur->prev->next = cur->next;
    } else {
        list->head = cur->next;
    }

    if (cur->next != nullptr) {
        cur->next->prev = cur->prev;
    } else {
        list->tail = cur->prev;
    }

    delete cur;
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
    list->tail = nullptr;
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
        pushBack(list, value);
    }

    file.close();
}

int main() {
    List list;
    init(&list);

    pushBack(&list, 10);
    pushBack(&list, 20);
    pushBack(&list, 30);
    pushBack(&list, 40);
    pushBack(&list, 50);

    cout << "Исходный двусвязный список:" << endl;
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

    writeToFile(&list, "list2.txt");
    clearList(&list);

    cout << "\nПосле уничтожения:" << endl;
    printList(&list);

    restoreFromFile(&list, "list2.txt");
    cout << "\nПосле восстановления из файла:" << endl;
    printList(&list);

    clearList(&list);
    return 0;
}
