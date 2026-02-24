#include <iostream>
#include <cstdarg>
using namespace std;

int min(int count, ...)
{
    va_list args;
    va_start(args, count);

    int minimum = va_arg(args, int);

    for (int i = 1; i < count; i++)
    {
        int value = va_arg(args, int);
        if (value < minimum)
            minimum = value;
    }

    va_end(args);
    return minimum;
}

int main()
{
    cout << "Минимум (5 чисел): "
        << min(5, 8, 3, 15, -2, 7) << endl;

    cout << "Минимум (10 чисел): "
        << min(10, 5, 7, 2, 9, 11, -4, 6, 3, 8, 1) << endl;

    cout << "Минимум (12 чисел): "
        << min(12, 10, 22, -5, 7, 3, 14, 0, -8, 6, 9, 1, 4) << endl;

    return 0;
}
