#include <iostream>

using namespace std;

int main()
{
    const int n = 7;
    int tmp; // временная переменная

    int arr[n] = { 9, 3, 5, 6, 11, 21, 1 };

    // вывод исходного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // сортировка пузырьком
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    // вывод отсортированного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
