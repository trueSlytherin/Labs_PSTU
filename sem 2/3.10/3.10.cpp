#include <iostream>
using namespace std;

int main() {
    const int n = 3;

    int arr[n][n] = { {0, 1, 2}, {1, 2, 3}, {2, 3, 4} };

    int tmp;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            tmp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
