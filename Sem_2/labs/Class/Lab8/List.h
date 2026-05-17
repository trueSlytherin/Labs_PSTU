#pragma once

#include <iostream>

#include "Object.h"
#include "Person.h"
#include "Student.h"

using namespace std;

class List {
public:
    List(void);
    List(int n);
    virtual ~List(void);

    virtual void Make(int n);
    virtual void Add();
    virtual void Del();
    virtual void Show();
    virtual void ShowElement(int number);
    virtual int operator()();
    virtual void HandleEvent(const TEvent& event);

protected:
    Object** beg;
    int size;
    int cur;

    void Clear();
};
