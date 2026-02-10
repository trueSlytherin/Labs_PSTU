#include <iostream>

using namespace std;

int main()
{
    const int n = 11;
    int max;
    int count = 1;

    int arr[n] = { 487, 452, 6116, 87, 82, 68, 79, 124, 455, 3545, 265 };

    max = arr[0];
    cout << arr[0] << " ";

    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";

        if (arr[i] > max)
        {
            max = arr[i];
            count = 1;
        }
        else if (arr[i] == max)
        {
            count++;
        }
    }

    cout << endl;

    cout << "Max: " << max << endl;
    cout << "Количество элементов с этим значением: " << count << endl;

    return 0;
}
