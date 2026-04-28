#include <iostream>
using namespace std;
int main()
{
    const int N = 11;
    int tmp, p, q;
    int a[N] = { 32, 23, 839, 123400,230, 125, 323, 3, 40, 22, 547 };
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
