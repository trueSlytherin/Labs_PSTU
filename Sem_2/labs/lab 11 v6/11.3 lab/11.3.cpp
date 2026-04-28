#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
    unsigned int size;
};

void init(Stack* s) {
    s->top = nullptr;
    s->size = 0;
}

void push(Stack* s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(Stack* s) {
    if (s->top == nullptr) {
        return 0;
    }

    Node* tmp = s->top;
    int value = tmp->data;
    s->top = s->top->next;
    delete tmp;
    s->size--;
    return value;
}

void printStack(Stack* s) {
    if (s->top == nullptr) {
        cout << "Стек пуст." << endl;
        return;
    }

    Node* p = s->top;
    int i = 1;
    while (p != nullptr) {
        cout << i << ") " << p->data << endl;
        p = p->next;
        i++;
    }
}

void deleteByNumber(Stack* s, unsigned int num) {
    if (s->top == nullptr || num < 1 || num > s->size) {
        cout << "Удаление невозможно." << endl;
        return;
    }

    Stack temp;
    init(&temp);

    for (unsigned int i = 1; i < num; i++) {
        push(&temp, pop(s));
    }

    pop(s);

    while (temp.top != nullptr) {
        push(s, pop(&temp));
    }
}

void addToBeginning(Stack* s, int value) {
    Stack temp;
    init(&temp);

    while (s->top != nullptr) {
        push(&temp, pop(s));
    }

    push(s, value);

    while (temp.top != nullptr) {
        push(s, pop(&temp));
    }
}

void writeToFile(Stack* s, const char* filename) {
    ofstream file(filename);

    Stack temp;
    init(&temp);

    while (s->top != nullptr) {
        int x = pop(s);
        file << x << endl;
        push(&temp, x);
    }

    while (temp.top != nullptr) {
        push(s, pop(&temp));
    }

    file.close();
}

void clearStack(Stack* s) {
    while (s->top != nullptr) {
        pop(s);
    }
}

void restoreFromFile(Stack* s, const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    clearStack(s);

    Stack temp;
    init(&temp);

    int value;
    while (file >> value) {
        push(&temp, value);
    }

    while (temp.top != nullptr) {
        push(s, pop(&temp));
    }

    file.close();
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    cout << "Исходный стек:" << endl;
    printStack(&s);

    unsigned int num;
    cout << "\nВведите номер удаляемого элемента: ";
    cin >> num;
    deleteByNumber(&s, num);

    cout << "\nПосле удаления:" << endl;
    printStack(&s);

    int x;
    cout << "\nВведите элемент для добавления в начало: ";
    cin >> x;
    addToBeginning(&s, x);

    cout << "\nПосле добавления в начало:" << endl;
    printStack(&s);

    writeToFile(&s, "stack.txt");
    clearStack(&s);

    cout << "\nПосле уничтожения:" << endl;
    printStack(&s);

    restoreFromFile(&s, "stack.txt");
    cout << "\nПосле восстановления из файла:" << endl;
    printStack(&s);

    clearStack(&s);
    return 0;
}
