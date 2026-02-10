#include <iostream>
using namespace std;
int main()
{
    const int n = 7;
    int key;
    int arr[n] = { 9, 3, 5, 6, 11, 21, 1 };
    // вывод исходного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // сортировка вставками
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    // вывод отсортированного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
