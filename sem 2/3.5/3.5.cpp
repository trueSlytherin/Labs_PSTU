#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int arr[n] = { 12, 967, 53, 10, 62, 63, 56, 919, 1, 158 };

    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << max << endl;

    return 0;
}
