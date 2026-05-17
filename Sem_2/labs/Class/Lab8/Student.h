#pragma once

#include "Person.h"

class Student : public Person {
public:
    Student(void);
    Student(string n, int a, float r);
    Student(const Student& s);
    virtual ~Student(void);

    float get_rating();
    void set_rating(float r);

    Student& operator=(const Student& s);

    virtual void Show();
    virtual void Input();
    virtual void HandleEvent(const TEvent& event);

protected:
    float rating;
};
