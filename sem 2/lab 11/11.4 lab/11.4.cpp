#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
    unsigned int size;
};

void init(Queue* q) {
    q->head = nullptr;
    q->tail = nullptr;
    q->size = 0;
}

void push(Queue* q, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (q->tail == nullptr) {
        q->head = newNode;
        q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;
}

int pop(Queue* q) {
    if (q->head == nullptr) {
        return 0;
    }

    Node* tmp = q->head;
    int value = tmp->data;
    q->head = q->head->next;

    if (q->head == nullptr) {
        q->tail = nullptr;
    }

    delete tmp;
    q->size--;
    return value;
}

void printQueue(Queue* q) {
    if (q->head == nullptr) {
        cout << "Очередь пуста." << endl;
        return;
    }

    Node* p = q->head;
    int i = 1;
    while (p != nullptr) {
        cout << i << ") " << p->data << endl;
        p = p->next;
        i++;
    }
}

void deleteByNumber(Queue* q, unsigned int num) {
    if (q->head == nullptr || num < 1 || num > q->size) {
        cout << "Удаление невозможно." << endl;
        return;
    }

    Queue temp;
    init(&temp);

    for (unsigned int i = 1; i < num; i++) {
        push(&temp, pop(q));
    }

    pop(q);

    while (q->head != nullptr) {
        push(&temp, pop(q));
    }

    while (temp.head != nullptr) {
        push(q, pop(&temp));
    }
}

void addToBeginning(Queue* q, int value) {
    Queue temp;
    init(&temp);

    push(&temp, value);

    while (q->head != nullptr) {
        push(&temp, pop(q));
    }

    while (temp.head != nullptr) {
        push(q, pop(&temp));
    }
}

void writeToFile(Queue* q, const char* filename) {
    ofstream file(filename);

    Queue temp;
    init(&temp);

    while (q->head != nullptr) {
        int x = pop(q);
        file << x << endl;
        push(&temp, x);
    }

    while (temp.head != nullptr) {
        push(q, pop(&temp));
    }

    file.close();
}

void clearQueue(Queue* q) {
    while (q->head != nullptr) {
        pop(q);
    }
}

void restoreFromFile(Queue* q, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    clearQueue(q);

    int value;
    while (file >> value) {
        push(q, value);
    }

    file.close();
}

int main() {
    Queue q;
    init(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    push(&q, 50);

    cout << "Исходная очередь:" << endl;
    printQueue(&q);

    unsigned int num;
    cout << "\nВведите номер удаляемого элемента: ";
    cin >> num;
    deleteByNumber(&q, num);

    cout << "\nПосле удаления:" << endl;
    printQueue(&q);

    int x;
    cout << "\nВведите элемент для добавления в начало: ";
    cin >> x;
    addToBeginning(&q, x);

    cout << "\nПосле добавления в начало:" << endl;
    printQueue(&q);

    writeToFile(&q, "queue.txt");
    clearQueue(&q);

    cout << "\nПосле уничтожения:" << endl;
    printQueue(&q);

    restoreFromFile(&q, "queue.txt");
    cout << "\nПосле восстановления из файла:" << endl;
    printQueue(&q);

    clearQueue(&q);
    return 0;
}
