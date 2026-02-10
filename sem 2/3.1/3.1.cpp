#include <iostream>

using namespace std;

int main()
{
    const int n = 4;
    int tmp;

    // массив
    int arr[n] = { 43, 564, 76, 123 };

    // вывод исходного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // переворачиваем массив
    for (int i = 0; i < n / 2; i++)
    {
        tmp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = tmp;
    }

    // вывод перевёрнутого массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
