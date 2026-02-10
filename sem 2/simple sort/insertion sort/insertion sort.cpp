#include <iostream>
using namespace std;
int main()
{
    const int n = 7;
    int tmp, min_index;
    int arr[n] = { 9, 3, 5, 6, 11, 21, 1 };
    // вывод исходного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // сортировка выбором
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        tmp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = tmp;
    }
    // вывод отсортированного массива
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
