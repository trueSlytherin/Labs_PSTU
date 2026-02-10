#include <iostream>

using namespace std;

int main()
{
    const int n = 11;
    int tmp, p, q;

    int arr[n] = { 11, 53, 54, 887, 856, 92, 73, 23, 72, 21, 75 };

    p = 2;
    q = 6;

    // вывод исходного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // переворачиваем участок массива
    while (p < q)
    {
        tmp = arr[p];
        arr[p] = arr[q];
        arr[q] = tmp;
        p++;
        q--;
    }

    // вывод результата
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
