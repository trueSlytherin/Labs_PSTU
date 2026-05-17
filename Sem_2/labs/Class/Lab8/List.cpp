#include "List.h"

List::List(void) {
    beg = 0;
    size = 0;
    cur = 0;
}

List::List(int n) {
    beg = new Object*[n];
    size = n;
    cur = 0;
}

List::~List(void) {
    Clear();
}

void List::Clear() {
    if (beg != 0) {
        for (int i = 0; i < cur; i++) {
            delete beg[i];
        }
        delete[] beg;
    }

    beg = 0;
    size = 0;
    cur = 0;
}

void List::Make(int n) {
    Clear();

    if (n > 0) {
        beg = new Object*[n];
        size = n;
        cur = 0;
    }
}

void List::Add() {
    if (cur >= size) {
        cout << "Group is full" << endl;
        return;
    }

    cout << "1. Person" << endl;
    cout << "2. Student" << endl;
    cout << "Choose object: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        Person* p = new Person;
        p->Input();
        beg[cur] = p;
        cur++;
    } else if (choice == 2) {
        Student* s = new Student;
        s->Input();
        beg[cur] = s;
        cur++;
    } else {
        cout << "Wrong choice" << endl;
    }
}

void List::Del() {
    if (cur == 0) {
        cout << "Group is empty" << endl;
        return;
    }

    delete beg[cur - 1];
    cur--;
}

void List::Show() {
    if (cur == 0) {
        cout << "Group is empty" << endl;
        return;
    }

    for (int i = 0; i < cur; i++) {
        cout << "Object number " << i + 1 << endl;
        beg[i]->Show();
    }
}

void List::ShowElement(int number) {
    if (number < 1 || number > cur) {
        cout << "Wrong object number" << endl;
        return;
    }

    beg[number - 1]->Show();
}

int List::operator()() {
    return cur;
}

void List::HandleEvent(const TEvent& event) {
    if (event.what == evMessage) {
        for (int i = 0; i < cur; i++) {
            beg[i]->HandleEvent(event);
        }
    }
}
