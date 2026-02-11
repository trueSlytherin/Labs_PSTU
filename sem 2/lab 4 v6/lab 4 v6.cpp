//6
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    const int n = 10;
    int arr[2 * n]; // делаем запас места для вставки
    int size = n;

    srand(time(0)); // инициализация случайных чисел

    // 1) Формируем массив случайных чисел
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20; // числа от 0 до 19
    }

    // 2) Вывод массива
    cout << "Исходный массив:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 3) Удаление элемента с заданным номером
    int a;
    cout << "Введите номер элемента для удаления (0 - " << size - 1 << "): ";
    cin >> a;

    if (a >= 0 && a < size)
    {
        for (int i = a; i < size - 1; i++)
        {
            arr[i] = arr[i + 1]; // сдвиг влево
        }
        size--;
    }

    // 4) Вставка после первого четного элемента
    int insert_a = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            insert_a = i;
            break;
        }
    }

    if (insert_a != -1)
    {
        int new_value = (insert_a - 1) * (insert_a - 1) + 2;

        for (int i = size; i > insert_a + 1; i--)
        {
            arr[i] = arr[i - 1]; // сдвиг вправо
        }

        arr[insert_a + 1] = new_value;
        size++;
    }

    // 5) Вывод итогового массива
    cout << "Полученный массив:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
