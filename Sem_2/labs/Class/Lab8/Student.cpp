#include "Student.h"

Student::Student(void) : Person() {
    rating = 0;
}

Student::Student(string n, int a, float r) : Person(n, a) {
    rating = r;
}

Student::Student(const Student& s) : Person(s) {
    rating = s.rating;
}

Student::~Student(void) {
}

float Student::get_rating() {
    return rating;
}

void Student::set_rating(float r) {
    rating = r;
}

Student& Student::operator=(const Student& s) {
    if (this == &s) {
        return *this;
    }

    name = s.name;
    age = s.age;
    rating = s.rating;
    return *this;
}

void Student::Show() {
    cout << "STUDENT" << endl;
    cout << "name = " << name << endl;
    cout << "age = " << age << endl;
    cout << "rating = " << rating << endl;
}

void Student::Input() {
    Person::Input();
    cout << "rating = ";
    cin >> rating;
}

void Student::HandleEvent(const TEvent& event) {
}
