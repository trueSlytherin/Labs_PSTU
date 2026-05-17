#include "Person.h"

Person::Person(void) {
    name = "";
    age = 0;
}

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::Person(const Person& p) {
    name = p.name;
    age = p.age;
}

Person::~Person(void) {
}

string Person::get_name() {
    return name;
}

int Person::get_age() {
    return age;
}

void Person::set_name(string n) {
    name = n;
}

void Person::set_age(int a) {
    age = a;
}

Person& Person::operator=(const Person& p) {
    if (this == &p) {
        return *this;
    }

    name = p.name;
    age = p.age;
    return *this;
}

void Person::Show() {
    cout << "PERSON" << endl;
    cout << "name = " << name << endl;
    cout << "age = " << age << endl;
}

void Person::Input() {
    cout << "name = ";
    cin >> name;
    cout << "age = ";
    cin >> age;
}

void Person::HandleEvent(const TEvent& event) {
}
