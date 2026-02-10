#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int k = 1;

    int arr[n][n] = { {1, 1, 1},{2, 1, 1},{1, 2, 1} };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j + k) {
                arr[i][j] = 0;
            }
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
