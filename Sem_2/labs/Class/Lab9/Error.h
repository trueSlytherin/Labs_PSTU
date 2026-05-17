#pragma once

#include <iostream>
#include <string>

using namespace std;

class Error {
public:
    virtual void what() = 0;
};

class SizeError : public Error {
protected:
    string msg;
public:
    SizeError() {
        msg = "Size error\n";
    }

    virtual void what() {
        cout << msg;
    }
};

class MaxSizeError : public SizeError {
protected:
    string msg_;
public:
    MaxSizeError() {
        msg_ = "Set size more than MAX_SIZE\n";
    }

    virtual void what() {
        cout << msg_;
    }
};

class AddSizeError : public SizeError {
protected:
    string msg_;
public:
    AddSizeError() {
        msg_ = "Can not add element: set is full\n";
    }

    virtual void what() {
        cout << msg_;
    }
};

class UnionSizeError : public SizeError {
protected:
    string msg_;
public:
    UnionSizeError() {
        msg_ = "Can not unite sets: result size more than MAX_SIZE\n";
    }

    virtual void what() {
        cout << msg_;
    }
};

class IndexError : public Error {
protected:
    string msg;
public:
    IndexError() {
        msg = "Index error\n";
    }

    virtual void what() {
        cout << msg;
    }
};

class IndexError1 : public IndexError {
protected:
    string msg_;
public:
    IndexError1() {
        msg_ = "Index < 0\n";
    }

    virtual void what() {
        cout << msg_;
    }
};

class IndexError2 : public IndexError {
protected:
    string msg_;
public:
    IndexError2() {
        msg_ = "Index >= set size\n";
    }

    virtual void what() {
        cout << msg_;
    }
};
