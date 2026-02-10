#include <iostream>

using namespace std;

int main()
{
    const int n = 6;

    int arr[n] = { 5, 2, 1, 3, 5, 7 };

    bool sorted = true;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            sorted = false;
            break; // раннее прерывание
        }
    }

    if (sorted)
    {
        cout << "Массив отсортирован" << endl;
    }
    else
    {
        cout << "Массив не упорядочен по возрастанию" << endl;
    }

    return 0;
}
