#pragma once

#include <iostream>
#include <string>

#include "Object.h"

using namespace std;

class Person : public Object {
public:
    Person(void);
    Person(string n, int a);
    Person(const Person& p);
    virtual ~Person(void);

    string get_name();
    int get_age();

    void set_name(string n);
    void set_age(int a);

    Person& operator=(const Person& p);

    virtual void Show();
    virtual void Input();
    virtual void HandleEvent(const TEvent& event);

protected:
    string name;
    int age;
};
