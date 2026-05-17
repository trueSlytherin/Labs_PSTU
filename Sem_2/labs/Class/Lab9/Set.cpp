#include "Set.h"

Set::Set(void) {
    size = 0;
    data = 0;
}

Set::Set(int s) {
    if (s > MAX_SIZE) {
        throw MaxSizeError();
    }

    size = s;

    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    } else {
        data = 0;
    }
}

Set::Set(const Set& a) {
    size = a.size;

    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
    } else {
        data = 0;
    }
}

Set::~Set(void) {
    if (data != 0) {
        delete[] data;
    }
    data = 0;
}

Set& Set::operator=(const Set& a) {
    if (this == &a) {
        return *this;
    }

    if (data != 0) {
        delete[] data;
    }

    size = a.size;

    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
    } else {
        data = 0;
    }

    return *this;
}

int& Set::operator[](int index) {
    if (index < 0) {
        throw IndexError1();
    }

    if (index >= size) {
        throw IndexError2();
    }

    return data[index];
}

int Set::operator()() {
    return size;
}

bool Set::Contains(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }

    return false;
}

void Set::Add(int value) {
    if (Contains(value)) {
        return;
    }

    if (size + 1 > MAX_SIZE) {
        throw AddSizeError();
    }

    int* temp = new int[size + 1];

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

Set Set::operator+(const Set& a) {
    Set temp;

    for (int i = 0; i < size; i++) {
        temp.Add(data[i]);
    }

    for (int i = 0; i < a.size; i++) {
        if (!temp.Contains(a.data[i]) && temp.size + 1 > MAX_SIZE) {
            throw UnionSizeError();
        }
        temp.Add(a.data[i]);
    }

    return temp;
}

Set& Set::operator++() {
    if (size + 1 > MAX_SIZE) {
        throw AddSizeError();
    }

    int value;
    cout << "new element = ";
    cin >> value;
    Add(value);
    return *this;
}

Set Set::operator++(int) {
    Set temp(*this);
    ++(*this);
    return temp;
}

ostream& operator<<(ostream& out, const Set& a) {
    if (a.size == 0) {
        out << "Empty";
    }

    for (int i = 0; i < a.size; i++) {
        out << a.data[i] << " ";
    }

    return out;
}

istream& operator>>(istream& in, Set& a) {
    int n = a.size;
    int value;

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
