#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int Size = 10;

// Функция поиска седловых точек
void SaddlePoints(int a[Size][Size], int n)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int element = a[i][j];

            bool isMinRow = true;
            bool isMaxRow = true;
            bool isMinCol = true;
            bool isMaxCol = true;

            // Проверка строки
            for (int k = 0; k < n; k++)
            {
                if (a[i][k] < element) isMinRow = false;
                if (a[i][k] > element) isMaxRow = false;
            }

            // Проверка столбца
            for (int k = 0; k < n; k++)
            {
                if (a[k][j] < element) isMinCol = false;
                if (a[k][j] > element) isMaxCol = false;
            }

            // Условие седловой точки
            if ((isMinRow && isMaxCol) || (isMaxRow && isMinCol))
            {
                cout << "Седловая точка: "
                    << element
                    << " (строка " << i
                    << ", столбец " << j << ")" << endl;
                found = true;
            }
        }
    }

    if (!found)
        cout << "Седловых точек нет." << endl;
}

int main()
{
    srand(time(0));
    int n;

    cout << "Размер матрицы: ";
    cin >> n;

    int a[Size][Size];

    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 21 - 10; // числа от -10 до 10
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    SaddlePoints(a, n);

    return 0;
}
