#include "Money.h"
#include "Set.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <windows.h>

using namespace std;

template <class T>
void PrintVector(vector<T> a)
{
    for (int i = 0; i < (int)a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

template <class T>
void MaxAddBegin(vector<T>& a)
{
    if (a.empty()) return;
    typename vector<T>::iterator it = max_element(a.begin(), a.end());
    a.insert(a.begin(), *it);
}

template <class T>
void DelMin(vector<T>& a)
{
    if (a.empty()) return;
    typename vector<T>::iterator it = min_element(a.begin(), a.end());
    a.erase(it);
}

template <class T>
void AddAverage(vector<T>& a)
{
    if (a.empty()) return;

    T sum = T();
    for (int i = 0; i < (int)a.size(); i++)
        sum = sum + a[i];

    T average = sum / (int)a.size();
    for (int i = 0; i < (int)a.size(); i++)
        a[i] = a[i] + average;
}

template <class T>
vector<T> StackToVector(stack<T> s)
{
    vector<T> a;
    while (!s.empty())
    {
        a.push_back(s.top());
        s.pop();
    }
    reverse(a.begin(), a.end());
    return a;
}

template <class T>
stack<T> VectorToStack(vector<T> a)
{
    stack<T> s;
    for (int i = 0; i < (int)a.size(); i++)
        s.push(a[i]);
    return s;
}

template <class T>
void PrintStack(stack<T> s)
{
    vector<T> a = StackToVector(s);
    PrintVector(a);
}

template <class T>
void MaxAddBegin(stack<T>& s)
{
    vector<T> a = StackToVector(s);
    MaxAddBegin(a);
    s = VectorToStack(a);
}

template <class T>
void DelMin(stack<T>& s)
{
    vector<T> a = StackToVector(s);
    DelMin(a);
    s = VectorToStack(a);
}

template <class T>
void AddAverage(stack<T>& s)
{
    vector<T> a = StackToVector(s);
    AddAverage(a);
    s = VectorToStack(a);
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Zadacha 1. Vector<double>" << endl;
    vector<double> a;
    a.push_back(2.5);
    a.push_back(7.4);
    a.push_back(1.2);
    a.push_back(4.8);
    cout << "Nachalnyi vector: ";
    PrintVector(a);
    MaxAddBegin(a);
    cout << "Posle dobavleniya max v nachalo: ";
    PrintVector(a);
    DelMin(a);
    cout << "Posle udaleniya min: ";
    PrintVector(a);
    AddAverage(a);
    cout << "Posle dobavleniya srednego: ";
    PrintVector(a);

    cout << endl << "Zadacha 2. Vector<Money>" << endl;
    vector<Money> b;
    b.push_back(Money(10, 50));
    b.push_back(Money(7, 25));
    b.push_back(Money(15, 10));
    b.push_back(Money(3, 40));
    cout << "Nachalnyi vector: ";
    PrintVector(b);
    MaxAddBegin(b);
    cout << "Posle dobavleniya max v nachalo: ";
    PrintVector(b);
    DelMin(b);
    cout << "Posle udaleniya min: ";
    PrintVector(b);
    AddAverage(b);
    cout << "Posle dobavleniya srednego: ";
    PrintVector(b);

    cout << endl << "Zadacha 3. Parametrizovannyi klass Set<Money>" << endl;
    Set<Money> c;
    c.Add(Money(5, 20));
    c.Add(Money(11, 30));
    c.Add(Money(4, 90));
    cout << "Nachalnoe mnozhestvo: ";
    c.Print();
    c.MaxAddBegin();
    cout << "Posle dobavleniya max v nachalo: ";
    c.Print();
    c.DelMin();
    cout << "Posle udaleniya min: ";
    c.Print();
    c.AddAverage();
    cout << "Posle dobavleniya srednego: ";
    c.Print();

    cout << endl << "Zadacha 4-5. Adapter stack<Money>" << endl;
    stack<Money> s;
    s.push(Money(1, 10));
    s.push(Money(8, 70));
    s.push(Money(6, 45));
    cout << "Nachalnyi stack: ";
    PrintStack(s);
    MaxAddBegin(s);
    cout << "Posle dobavleniya max v nachalo: ";
    PrintStack(s);
    DelMin(s);
    cout << "Posle udaleniya min: ";
    PrintStack(s);
    AddAverage(s);
    cout << "Posle dobavleniya srednego: ";
    PrintStack(s);

    return 0;
}
