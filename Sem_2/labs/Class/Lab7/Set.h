#pragma once

#include <iostream>

using namespace std;

template <class T>
class Set {
public:
    Set(int s = 0, T k = T());
    Set(const Set<T>& a);
    ~Set(void);

    Set<T>& operator=(const Set<T>& a);
    T& operator[](int index);
    int operator()();
    Set<T> operator+(const Set<T>& a);

    void Add(T value);
    bool Contains(T value);

    template <class U>
    friend ostream& operator<<(ostream& out, const Set<U>& a);

    template <class U>
    friend istream& operator>>(istream& in, Set<U>& a);

private:
    int size;
    T* data;
};

template <class T>
Set<T>::Set(int s, T k) {
    size = s;

    if (size > 0) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = k;
        }
    } else {
        data = 0;
    }
}

template <class T>
Set<T>::Set(const Set<T>& a) {
    size = a.size;

    if (size > 0) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
    } else {
        data = 0;
    }
}

template <class T>
Set<T>::~Set(void) {
    if (data != 0) {
        delete[] data;
    }
    data = 0;
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& a) {
    if (this == &a) {
        return *this;
    }

    if (data != 0) {
        delete[] data;
    }

    size = a.size;

    if (size > 0) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
    } else {
        data = 0;
    }

    return *this;
}

template <class T>
T& Set<T>::operator[](int index) {
    static T error = T();

    if (index >= 0 && index < size) {
        return data[index];
    }

    cout << "Error! Index >= size" << endl;
    return error;
}

template <class T>
int Set<T>::operator()() {
    return size;
}

template <class T>
bool Set<T>::Contains(T value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

template <class T>
void Set<T>::Add(T value) {
    if (Contains(value)) {
        return;
    }

    T* temp = new T[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    temp[size] = value;

    if (data != 0) {
        delete[] data;
    }

    data = temp;
    size++;
}

template <class T>
Set<T> Set<T>::operator+(const Set<T>& a) {
    Set<T> temp;

    for (int i = 0; i < size; i++) {
        temp.Add(data[i]);
    }

    for (int i = 0; i < a.size; i++) {
        temp.Add(a.data[i]);
    }

    return temp;
}

template <class U>
ostream& operator<<(ostream& out, const Set<U>& a) {
    if (a.size == 0) {
        out << "Empty";
    }

    for (int i = 0; i < a.size; i++) {
        out << a.data[i] << " ";
    }

    return out;
}

template <class U>
istream& operator>>(istream& in, Set<U>& a) {
    int n = a.size;
    U value;

    if (a.data != 0) {
        delete[] a.data;
    }

    a.data = 0;
    a.size = 0;

    for (int i = 0; i < n; i++) {
        cout << "element[" << i << "] = ";
        in >> value;

        if (a.Contains(value)) {
            cout << "Takoi element uzhe est" << endl;
            i--;
        } else {
            a.Add(value);
        }
    }

    return in;
}
