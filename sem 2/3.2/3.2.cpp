#include <iostream>
using namespace std;
int main()
{
    const int N = 11;
    int tmp, p, q;
    int a[n] = { 11, 53, 54, 887, 856, 92, 73, 23, 72, 21, 75 };
    cout << "введите p и q" << endl;
    cin >> p >> q;
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    while (p < q)
    {
        tmp = a[p];
        a[p] = a[q];
        a[q] = tmp;
        p++;
        q--;
    }
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
}
