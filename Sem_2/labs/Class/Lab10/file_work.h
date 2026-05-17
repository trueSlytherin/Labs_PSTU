#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>

#include "Money.h"

using namespace std;

int make_file(const char* f_name) {
    fstream stream(f_name, ios::out | ios::trunc);

    if (!stream) {
        return -1;
    }

    int n;
    Money m;

    cout << "N? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Money " << i + 1 << endl;
        cin >> m;
        stream << m;
    }

    stream.close();
    return n;
}

int print_file(const char* f_name) {
    fstream stream(f_name, ios::in);

    if (!stream) {
        return -1;
    }

    Money m;
    int i = 0;

    while (stream >> m) {
        i++;
        cout << i << ". " << m << endl;
    }

    stream.close();
    return i;
}

int del_file(const char* f_name, Money value) {
    fstream temp("temp.txt", ios::out | ios::trunc);
    fstream stream(f_name, ios::in);

    if (!stream) {
        return -1;
    }

    Money m;
    int count = 0;

    while (stream >> m) {
        if (m == value) {
            count++;
        } else {
            temp << m;
        }
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp.txt", f_name);

    return count;
}

int change_file(const char* f_name, Money value) {
    fstream temp("temp.txt", ios::out | ios::trunc);
    fstream stream(f_name, ios::in);

    if (!stream) {
        return -1;
    }

    Money m;
    Money add(1, 50);
    int count = 0;

    while (stream >> m) {
        if (m == value) {
            m = m + add;
            count++;
        }

        temp << m;
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp.txt", f_name);

    return count;
}

int add_file(const char* f_name, int number, int k) {
    fstream temp("temp.txt", ios::out | ios::trunc);
    fstream stream(f_name, ios::in);

    if (!stream) {
        return -1;
    }

    Money m;
    Money new_money;
    int i = 0;
    int count = 0;

    while (stream >> m) {
        i++;
        temp << m;

        if (i == number) {
            for (int j = 0; j < k; j++) {
                cout << "New money " << j + 1 << endl;
                cin >> new_money;
                temp << new_money;
                count++;
            }
        }
    }

    stream.close();
    temp.close();

    remove(f_name);
    rename("temp.txt", f_name);

    return count;
}
