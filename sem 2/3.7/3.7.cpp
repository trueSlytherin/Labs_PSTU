#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int arr[n] = { 263, 1432, 5, 62, 72, 96, 1346, 5367, 6, 1 };

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << max << endl;
    cout << min << endl;

    return 0;
}
